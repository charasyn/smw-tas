#!/usr/bin/env python3

import sys

def Main(args):
    if len(args) != 2:
        print("Bad invocation.")
        return 1
    fin = open(args[1],"r")
    for line in fin:
        s = line.rstrip()
        print(s+',')
    fin.close()

if __name__ == "__main__":
    sys.exit(Main(sys.argv))