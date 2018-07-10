import sys
import re
import shutil
NEED_USER = 0
NEED_PASS = 1
COMMON = 2


HAVE_QUIT = 999

grammar = {}

grammar["CR"] = "\r"
grammar["LF"] = "\n"
grammar["CRLF"] = "(?P<CRLF>\r\n)$"
grammar["char"] = r"[^" + grammar["CR"] + grammar["LF"] + r"]"
grammar["string"] = grammar["char"] + r"+"
grammar["username"] = r"(?P<username>" + grammar["string"] + r")"
grammar["password"] = r"(?P<password>" + grammar["string"] + r")"
grammar["type-code"] = r"(?P<typecode>" + r"[AI]" + r")"
grammar["pathname"] = r"(?P<pathname>" + grammar["string"] + r")"
grammar["number"] = "(?:(1\d\d)|2[0-4]\d|25[0-5]|([1-9]\d)|(\d))"
grammar["host-address"] = r"(?P<hostaddress>" \
                            r"(?:" + \
                          grammar["number"] + \
                                r"," \
                            r"){3}" + \
                          grammar["number"] + \
                          r")"
grammar["port-number"] = r"(?P<portnumber>" + grammar["number"] + r"," + grammar["number"] + r")"
grammar["host-port"] = r"(?P<hostport>" + grammar["host-address"] + "," + grammar["port-number"] + ")"
grammar["spaces"] = r" +"
grammar["USER"] = r"([uU][sS][eE][rR])"
grammar["PASS"] = r"([pP][aA][sS][sS])"
grammar["TYPE"] = r"([tT][yY][pP][eE])"
grammar["SYST"] = r"([sS][yY][sS][tT])"

class ParsingError(Exception):

    Error_Message = "ERROR -- "

    def __init__(self,desc=""):
        self._desc = desc

    @property
    def error_desc(self):
        return self._desc

    @error_desc.setter
    def error_desc(self,error_desc):
        self._desc = error_desc

    def error_message(self):
        return "501 Syntax error in parameter."

    def display_message(self):
        sys.stdout.write(self.error_message()+"\r\n")


class FirstWordError(ParsingError):

    def __init__(self,desc="command"):
        super().__init__(desc)

    def error_message(self):
        return "500 Syntax error, command unrecognized."


class FTPCommand:

    def __init__(self,message:str="200 Command OK."):
        self.message=message

    def reply(self):
        sys.stdout.write(self.message+"\r\n")
        pass

    def execute(self):
        pass

class RETRCommand(FTPCommand):

    default_path = "retr_files/file{}"

    def __init__(self,pathname):
        super().__init__("150 File status okay.")
        self.pathname=pathname

    def execute(self,num=0):
        try:
            #subprocess.run(['cp',self.pathname,RETRCommand.default_path.format(num)],check=True)
            #open(RETRCommand.default_path.format(num),'a').close()
            shutil.copy(self.pathname, RETRCommand.default_path.format(num))
            return True
        except IOError:
            sys.stdout.write("550 File not found or access denied.\r\n")
            return False

class USERCommand(FTPCommand):

    def __init__(self,username):
        super().__init__("331 Guest access OK, send password.")
        self.username=username

class PASSCommand(FTPCommand):

    def __init__(self,password):
        super().__init__("230 Guest login OK.")
        self.password=password


class PORTCommand(FTPCommand):

    def __init__(self,host,port):
        self.host = re.sub(',', '.', host)
        nums = re.split(',',port)
        self.port = str(int(nums[0]) * 256 + int(nums[1]))
        super().__init__("200 Port command successful ({},{}).".format(self.host, self.port))

class TYPECommand(FTPCommand):
    def __init__(self,typecode):
        self.code = typecode
        super().__init__("200 Type set to {}.".format(typecode))

class SYSTCommand(FTPCommand):
    def __init__(self):
        super().__init__("215 UNIX Type: L8.")

class NOOPCommand(FTPCommand):
    def __init__(self):
        super().__init__()

class QUITCommand(FTPCommand):
    def __init__(self):
        super().__init__()

class CommandError(Exception):

    def __init__(self,desc="503 Bad sequence of commands"):
        self._desc = desc

    @property
    def error_desc(self):
        return self._desc

    @error_desc.setter
    def error_desc(self,error_desc):
        self._desc = error_desc

    def display_message(self):
        sys.stdout.write(self._desc+"\r\n")

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




class CommandProcessor:

    def __init__(self):
        self._command = None
        self._server = None
        self._cur_phase = NEED_USER
        self._host=None
        self._port=None
        self._pathname=None
        self._type=None
        self._user=None
        self._pass=None
        self.quit=False
        self._fnum=1

    @property
    def command_to_process(self):
        return self._command

    @command_to_process.setter
    def command_to_process(self,command_to_process):
        self._command = command_to_process

    def connect_server(self,server):
        self._server = server

    def process_command(self):
        if self.quit:
            return
        elif isinstance(self._command,QUITCommand):
            self._command.reply()
            self.quit = True
        elif isinstance(self._command,USERCommand):
            self._command.reply()
            self._user = self._command.username
            self._pass = None
        elif self._user is None:
            self._do_error("530 Not logged in.")
        elif self._pass is None:
            if isinstance(self.command_to_process,PASSCommand):
                self._command.reply()
                self._pass=self._command.password
            else:
                self._do_error()
        elif isinstance(self._command,PASSCommand):
            self._do_error()
        elif isinstance(self._command,TYPECommand):
            self._command.reply()
            self._type=self._command.code
        elif isinstance(self._command,PORTCommand):
            self._command.reply()
            self._host=self._command.host
            self._port=self._command.port
        elif isinstance(self._command,RETRCommand):
            if self._host is None:
                self._do_error()
            else:
                if self._command.execute(self._fnum):
                    self._fnum += 1
                    self._command.reply()
                    sys.stdout.write("250 Requested file action completed.\r\n")
                    self._host=None
                    self._port=None
                    self._pathname=self._command.pathname
        else:
            self._command.reply()

    def _do_error(self,desc="503 Bad sequence of commands."):
        sys.stdout.write(desc+"\r\n")

class FTPServer:

    def __init__(self,parser:Parser,processor:CommandProcessor):
        self._parser = parser
        self._parser.connect_server(self)
        self._processor = processor
        sys.stdout.write("220 COMP 431 FTP server ready.\r\n")

    def input(self,s:str):
        if self._processor.quit:
            return
        sys.stdout.write(s)
        self._parser.string_to_parse = s
        self._parser.parse_command(self._after_parse)

    def _after_parse(self,command):
        if isinstance(command,FTPCommand):
            self._processor.command_to_process=command
            self._processor.process_command()
        elif isinstance(command,ParsingError):
            command.display_message()

class SingletonGenerator:
    _Parser = Parser()
    _CommandProcessor = CommandProcessor()
    _FTPServer = FTPServer(_Parser,_CommandProcessor)

    @classmethod
    def GetParser(cls):
        return cls._Parser

    @classmethod
    def GetCommandProcessor(cls):
        return cls._CommandProcessor

    @classmethod
    def GetFTPServer(cls):
        return cls._FTPServer


Test__ = False

test_cases = ["USER Jingling\r\n",
                "PASS 1234567\r\n",
                "Port 1,1,1,1,1,1\r\n",
                "ReTr relative\r\n"]

def main():

    S = SingletonGenerator.GetFTPServer()

    if Test__:
        for s in test_cases:
            S.input(s)
    else:
        for line in sys.stdin:
            S.input(line)

if __name__=="__main__":
    main()


