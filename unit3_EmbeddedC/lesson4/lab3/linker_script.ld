/* linker script cortexM3
eng.Bassant */

MEMORY
{
flash(Rx) : ORIGIN = 0X00000000, LENGTH = 512M
sram(rwx) : ORIGIN = 0X20000000, LENGTH = 512M

}

SECTIONS
{
	.TEXT : {
			*(.vectors*)
			*(.text*)
			*(.rodata)
			_E_text = . ;
	}> flash
	.data : {
	_S_DATA = . ;
	*(.data)
	. = ALIGN(4) ;
	_E_DATA = . ;

	}> sram AT> flash
	.bss : {
	_S_bss = . ;
	*(.bss*)
	_E_bss = . ;

	}> sram
}

