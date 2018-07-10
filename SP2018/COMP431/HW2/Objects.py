import sys
import re
import shutil
import subprocess

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