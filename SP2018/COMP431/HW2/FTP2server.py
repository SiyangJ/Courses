import sys
from Factory import SingletonGenerator

Test__ = False

test_cases = ["USER Jing\r\n",
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
