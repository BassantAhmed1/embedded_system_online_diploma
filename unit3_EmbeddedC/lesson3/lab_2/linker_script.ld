/* linker script cortexM3
eng.Bassant */

MEMORY
{
flash(Rx) : ORIGIN = 0X08000000, LENGTH = 128K
sram(rwx) : ORIGIN = 0X20000000, LENGTH = 20K

}

SECTIONS
{
	.TEXT : {
			*(.vectors*)
			*(.text*)
			*(.rodata)
	}> flash
	.data : {
			*(.data)

	}> flash
	.bss : {
			*(.bss)
	}> sram
}

