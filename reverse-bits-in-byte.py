#!/usr/bin/env python3

import sys
import re

def Main(args):
    if len(args) != 2:
        print("Bad invocation.")
        return 1
    fin = open(args[1],"r")
    for line in fin:
        match = re.search("0x([0-9A-Fa-f]{1,2})",line)
        if not match:
            match = re.search("([0-9A-Fa-f]{2})",line)
        if match:
            num = int(match.group(1),16)
            n_str = bin(num)[2:] # [2:] is to delete the 0b prefix
            i = int(n_str.rjust(8,'0')[::-1],2)
            print(hex(i)+',')
    fin.close()

if __name__ == "__main__":
    sys.exit(Main(sys.argv))
