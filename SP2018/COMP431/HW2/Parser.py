import sys
import re

from Grammar import grammar
from Objects import ParsingError, FirstWordError, RETRCommand, USERCommand, PASSCommand, PORTCommand,TYPECommand,SYSTCommand,NOOPCommand,QUITCommand

class Parser:

    def __init__(self, target_string=""):
        self._str = target_string
        self._cur_pos = 0
        self._len = len(self._str)
        self._parse_method_list = \
            [self._parse_USER,self._parse_PASS,self._parse_TYPE,
             self._parse_SYST,self._parse_NOOP,self._parse_QUIT,
             self._parse_RETR,self._parse_PORT]
        self._cur_err = None
        self._cur_command = None
        self._server = None
        # _cur_pos is the position to be read

    def connect_server(self,server):
        self._server = server

    @property
    def string_to_parse(self):
        return self._str

    @string_to_parse.setter
    def string_to_parse(self,string_to_parse):
        self._str=string_to_parse

    def parse_command(self,callback=None):
        self._cur_pos = 0
        self._cur_command = None
        self._cur_err = None
        #sys.stdout.write(self._str)
        pos = self._cur_pos
        suc = False
        for par in self._parse_method_list:
            self._cur_pos = pos
            try:
                par()
                self._parse_CRLF()
                suc = True
                break
            except FirstWordError as er:
                self._cur_err = er
                continue
            except ParsingError as er:
                self._cur_err = er
                break

        if suc:
            self._do_success(callback)
            return self._cur_command
        else:
            self._do_error(callback)

    def _parse_USER(self):
        self._parse_command_space("USER")
        try:
            self._cur_command = USERCommand(self._parse_string())
        except ParsingError as err:
            err.error_desc = "username"
            raise

    def _parse_PASS(self):
        self._parse_command_space("PASS")
        try:
            self._cur_command = PASSCommand(self._parse_string())
        except ParsingError as err:
            err.error_desc = "password"
            raise

    def _parse_RETR(self):
        self._parse_command_space("RETR")
        try:
            s = self._parse_string()
            if s[0] == "\\" or s[0]=="/":
                s = s[1:]
            self._cur_command = RETRCommand(s)
        except ParsingError as err:
            err.error_desc = "pathname"
            raise

    def _parse_PORT(self):
        self._parse_command_space("PORT")
        m=re.match(grammar["host-port"], self._cur_sub_string())
        if m is None:
            raise ParsingError("host-port")
        else:
            self._cur_pos+=m.end(m.lastindex)
            self._cur_command = PORTCommand(m.group("hostaddress"), m.group("portnumber"))

    def _parse_TYPE(self):
        self._parse_command_space("TYPE")
        m=re.match(grammar["type-code"], self._cur_sub_string())
        if m is None:
            raise ParsingError("type-code")
        else:
            self._cur_pos+=m.end(0)
            self._cur_command=TYPECommand(m.group("typecode"))

    def _parse_SYST(self):
        self._parse_single_command("SYST")
        self._cur_command=SYSTCommand()

    def _parse_NOOP(self):
        self._parse_single_command("NOOP")
        self._cur_command=NOOPCommand()

    def _parse_QUIT(self):
        self._parse_single_command("QUIT")
        self._cur_command=QUITCommand()

    def _parse_single_command(self,command_string):
        m = re.match(r"(?i)"+command_string,self._cur_sub_string())
        if m is None:
            raise FirstWordError()
        else:
            self._cur_pos+=m.end(0)

    def _parse_command_space(self,command_string):
        self._parse_single_command(command_string)
        m=re.match(grammar["spaces"], self._cur_sub_string())
        if m is None:
            raise FirstWordError()
        else:
            self._cur_pos+=m.end(0)

    def _parse_string(self):
        r = re.compile(grammar["string"])
        m = r.match(self._cur_sub_string())
        ## Check for ascii-ness
        if m is None or len(m.group(0))!=len(m.group(0).encode()):
            raise ParsingError("string")
        else:
            self._cur_pos+=m.end(0)
            return m.group(0)

    def _parse_CRLF(self):
        r = re.compile(grammar["CRLF"])
        m = r.match(self._cur_sub_string())
        if m is None:
            raise ParsingError("CRLF")
        else:
            self._cur_pos+=m.end(0)

    def _cur_sub_string(self):
        return self.string_to_parse[self._cur_pos:]

    def _do_error(self,callback=None):
        if callback is not None:
            callback(self._cur_err)
        else:
            sys.stdout.write(self._cur_err.error_message())

    def _do_success(self,callback=None):
        if callback is not None:
            callback(self._cur_command)
        else:
            self._cur_command.reply()