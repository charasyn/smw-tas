#!/usr/bin/env python3

import sys

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
        s = line.rstrip()
        print(s+',')
    fin.close()

if __name__ == "__main__":
    sys.exit(Main(sys.argv))