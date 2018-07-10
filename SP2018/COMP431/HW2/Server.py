import sys

from Parser import Parser
from CommandProcessor import CommandProcessor
from Objects import FTPCommand,ParsingError

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