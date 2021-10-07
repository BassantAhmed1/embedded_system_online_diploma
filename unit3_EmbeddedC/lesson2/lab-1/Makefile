#copyright : Bassant

CC=arm-none-eabi-
CFLAGS=-mcpu=arm926ej-s -g
INCS=-I .
LIBS=
SRC= $(wildcard *.c)
OBJ= $(SRC:.c=.o)
AS= $(wildcard *.s)
ASOBJ= $(AS:.s=.o)

all: learn-in-depth.bin

startup.o: startup.s
	$(CC)as.exe $(CFLAGS) $< -o $@

%.o: %.c	
	$(CC)gcc.exe $(CFLAGS) -c $(INKS) $< -o $@

learn-in-depth.elf: $(OBJ) $(ASOBJ)	
	$(CC)ld.exe -T linker_script.ld $(LIBS) $(OBJ) $(ASOBJ) -o $@ -Map=Map_file.map

learn-in-depth.bin: learn-in-depth.elf	
	$(CC)objcopy.exe -O binary $< $@

clean_all:
	rm -rf *.o *.elf *.bin
clean:
	rm -rf *.elf *.bin

