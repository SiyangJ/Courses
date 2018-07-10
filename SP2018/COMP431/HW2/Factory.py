from Parser import Parser
from CommandProcessor import CommandProcessor
from Server import FTPServer

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
