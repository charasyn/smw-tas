#!/usr/bin/env python3

import sys
import re

def Main(args):
    if len(args) > 3 or (len(args) > 1 and args[1] == "--help"):
        print("Usage: {0} [input filename] [output filename]".format(args[0]))
        print("If filename is not provided, stdio will be used.")
        return 1
    
    if len(args) >= 2:
        fin = open(args[1],"r")
    else:
        fin = sys.stdin
    if len(args) >= 3:
        fout = open(args[2],"w")
    else:
        fout = sys.stdout
    
    for line in fin:
        match = re.search("0x([0-9A-Fa-f]{1,2})",line)
        if not match:
            match = re.search("([0-9A-Fa-f]{2})",line)
        if match:
            num = int(match.group(1),16)
            n_str = bin(num)[2:] # [2:] is to delete the 0b prefix
            i = int(n_str.rjust(8,'0')[::-1],2)
            fout.write(hex(i)+',\n')
    fin.close()
    fout.close()

if __name__ == "__main__":
    sys.exit(Main(sys.argv))
