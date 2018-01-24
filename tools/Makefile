all: ../gen/buttons.txt
.PHONY: all clean 

clean:
	rm -rvf ../gen/*

../gen/buttons.txt: ../smw-ends-input-early/input
	./change-input.py ../smw-ends-input-early/input ../gen/buttons.txt