#!/usr/bin/make

all: main.hex 

main.hex: main.c
	avr-gcc -Wall -Os -DF_CPU=16000000 -mmcu=atmega328p -c main.c -o main.o
	avr-gcc -Wall -mmcu=atmega328p -o main.elf main.o
	avr-objcopy -j .text -j .data -O ihex main.elf main.hex

burn: 
	avrdude -c usbasp -p m328p -U flash:w:main.hex:i

clean:
	rm -v *.o *.elf *.hex





