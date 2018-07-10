import re

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

