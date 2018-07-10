import sys

class ServerReplyInterpreter:

    def __init__(self,reply=""):
        self._reply=reply

    @property
    def reply(self):
        return self._reply

    def interpret_reply(self,reply):
        self._reply = reply
        sys.stdout.write(reply)
