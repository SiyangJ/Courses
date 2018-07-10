import sys
from Objects import USERCommand,PASSCommand,PORTCommand,TYPECommand,RETRCommand,QUITCommand


NEED_USER = 0
NEED_PASS = 1
COMMON = 2


HAVE_QUIT = 999


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