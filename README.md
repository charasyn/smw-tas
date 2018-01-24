# smw-tas
This is code for a Teensy-based SNES TAS playback device. The code has the TAS hardcoded into it,
so short Python programs have been included for working with the TAS data.

It comes with a modified version of the Masterjun SMW "ends input early" April Fools' Day TAS,
which instead of forcing the SNES to TAS the game itself, installs the jailbreak onto save file C.
If you are going to use this to install the jailbreak, make sure you delete file C first.

# Usage
In the project folder:

`make tools` will run the Makefile in the `tools` directory, which will build `buttons.txt` in the
`gen` folder using the `smw-ends-input-early/input` file. Note that this file is not used by
default; instead, `buttons-{tas, first, second}.txt` are used instead.

`make teensy` will run the Makefile in the `teensy` directory, which will build the Teensy program
that plays back the TAS.

`make upload` will upload the Teensy program onto a Teensy 2.0.

`make clean` will clean up all the temporary files, including everything in the `gen` folder.

# Credits
SethBling, for helping me take the jailbreak from proof-of-concept to finished product
Masterjun, for making the TAS that the included jailbreak installer is based on
Nintendo, for making Super Mario World and the SNES
