all: tools teensy
.PHONY: all clean tools teensy upload

clean:
	$(MAKE) -C tools clean
	$(MAKE) -C teensy clean

tools:
	$(MAKE) -C tools

teensy:
	$(MAKE) -C teensy

upload: teensy
	teensy_loader_cli --mcu=atmega32u4 teensy/smw-tas-playback.hex