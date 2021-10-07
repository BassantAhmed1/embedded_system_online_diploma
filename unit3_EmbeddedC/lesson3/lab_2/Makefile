#copyright : Bassant

CC=arm-none-eabi-
CFLAGS= -mcpu=cortex-m3 -gdwarf-2
INCS=-I .
LIBS=
SRC= $(wildcard *.c)
OBJ= $(SRC:.c=.o)
AS= $(wildcard *.s)
ASOBJ= $(AS:.s=.o)
projectname= learn-in-depth-cortex-m3

all: $(projectname).hex
	@echo "======build is done======"

%.o: %.s
	$(CC)as.exe $(CFLAGS) $< -o $@

%.o: %.c	
	$(CC)gcc.exe $(CFLAGS) -c $(INKS) $< -o $@

$(projectname).elf: $(OBJ) $(ASOBJ)	
	$(CC)ld.exe -T linker_script.ld $(LIBS) $(OBJ) $(ASOBJ) -o $@ -Map=Map_file.map

$(projectname).hex: $(projectname).elf	
	$(CC)objcopy.exe -O binary $< $@

clean_all:
	rm -rf *.o *.elf *.hex
clean:
	rm -rf *.elf *.hex

