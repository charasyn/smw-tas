# smw-tas
This is code for a Teensy-based SNES TAS playback device. The code has the TAS hardcoded into it,
so short Python programs have been included for working with the TAS data, which can be found in
the `tas-work` folder.

It comes with a modified version of the Masterjun SMW "ends input early" April Fools' Day TAS,
which instead of forcing the SNES to TAS the game itself, installs the jailbreak onto save file C.

The TAS installer will erase the save files itself before proceeding. This requires you to hold down
the Reset button on the SNES at a certain time.

# Usage
In the project folder:

`make teensy` will run the Makefile in the `teensy` directory, which will build the Teensy program
that plays back the TAS.

`make upload` will upload the Teensy program onto a Teensy 2.0.

`make clean` will clean up all the temporary files.

Once you have a Teensy loaded with the program and properly hooked up to the SNES, you can install
the jailbreak by following these steps:

1. Power on your SNES with Super Mario World in the cart slot.
2. Wait for save files A and C to get erased. The light on the Teensy will change its pattern to indicate that the files have been erased.
3. Hold down the Reset button on your SNES until the light on the Teensy goes solid. This will happen after the light blinks five times.
4. Release the Reset button.
5. Wait for the TAS to play back.

At the end of the TAS, your game may appear to be frozen. This is intended. Observe the light on the
Teensy. If it is blinking once per second, it is safe to power down your SNES. When you power it back
on, you should find that the jailbreak has been installed. Enjoy! :)

# Credits
SethBling, for helping me take the jailbreak from proof-of-concept to finished product

Masterjun, for making the TAS that the included jailbreak installer is based on

Nintendo, for making Super Mario World and the SNES
