#!/usr/bin/env python3

import sys

def Main(args):
    if len(args) != 3:
        print("Bad invocation.")
        return 1
    fin = open(args[1],"r")
    fout = open(args[2],"w")
    for line in fin:
        buttons = line[7:-1]
        b_bs = list(map(lambda x: x!='.', buttons))
        str_bs = ""
        for b in reversed(b_bs):
            if b:
                str_bs += '1'
            else:
                str_bs += '0'
        int_bs = int(str_bs,2)
        fout.write("{0},\n".format(hex(int_bs)))
    fin.close()
    fout.close()

if __name__ == "__main__":
    sys.exit(Main(sys.argv))