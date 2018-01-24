#!/usr/bin/env python3

import sys
import re

def AdjustData(dat):
    if len(dat) == 1:
        return int(dat)
    elif len(dat) != 2:
        raise Exception("bad data")
    return int(dat[0],36)*10+int(dat[1])

def Main(args):
    if len(args) > 2 or (len(args) > 1 and args[1] == "--help"):
        print("Usage: {0} [filename]".format(args[0]))
        print("If filename is not provided, stdin will be used.")
        return 1
    if len(args) == 2:
        fin = open(args[1],"r")
    else:
        fin = sys.stdin
    for line in fin:
        match = re.match("^([0-9]+): *([0-9a-zA-Z]+)", line)
        if not match:
            print("bad match {0}".format(line))
            return 1
        data = match.group(2)
        print(hex(AdjustData(data)))

if __name__ == "__main__":
    sys.exit(Main(sys.argv))