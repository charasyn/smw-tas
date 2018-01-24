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
    if len(args) != 2:
        print("no")
        return 1
    fin = open(args[1],'r')
    for line in fin:
        match = re.match("^([0-9]+): *([0-9a-zA-Z]+)", line)
        if not match:
            print("bad match {0}".format(line))
            return 1
        data = match.group(2)
        print(hex(AdjustData(data)))

if __name__ == "__main__":
    sys.exit(Main(sys.argv))