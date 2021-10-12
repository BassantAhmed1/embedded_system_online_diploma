#copyright : Bassant

CC=arm-none-eabi-
CFLAGS= -mcpu=cortex-m4 -gdwarf-2 -g
INCS=-I .
LIBS=
SRC= $(wildcard *.c)
OBJ= $(SRC:.c=.o)
AS= $(wildcard *.s)
ASOBJ= $(AS:.s=.o)
projectname= unit3_lab3_cortexM4

all: $(projectname).bin
	@echo "======build is done======"

%.o: %.c	
	$(CC)gcc.exe $(CFLAGS) -c $(INKS) $< -o $@

$(projectname).elf: $(OBJ) $(ASOBJ)	
	$(CC)ld.exe -T linker_script.ld $(LIBS) $(OBJ) $(ASOBJ) -o $@ -Map=Map_file.map
	cp $(projectname).elf $(projectname).axf


$(projectname).bin: $(projectname).elf	
	$(CC)objcopy.exe -O binary $< $@

clean_all:
	rm -rf *.o *.elf *.bin
clean:
	rm -rf *.elf *.hex

