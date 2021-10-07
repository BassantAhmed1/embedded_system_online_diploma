/* startup_cortexM3.s
Eng.Bassant */

/*SRAM 0x20000000 */
.section .vectors

.word 0x20001000    	/* start of the stack*/
.word _reset        	/*reset section*/
.word vector_handler	/*_NMI_handler*/
.word vector_handler	/*_HARD_FAULT_handler*/
.word vector_handler	/*MM fault*/
.word vector_handler	/*Bus fault*/
.word vector_handler	/*Usage Fault*/
.word vector_handler	/*RESERVED*/
.word vector_handler	/*RESERVED*/
.word vector_handler	/*RESERVED*/
.word vector_handler	/*RESERVED*/
.word vector_handler	/*SV call*/
.word vector_handler	/*Debug reserved*/
.word vector_handler	/*RESERVED*/
.word vector_handler	/*PendSV*/
.word vector_handler	/*SysTick*/
.word vector_handler	/*IRQ0*/
.word vector_handler	/*IRQ1*/
.word vector_handler	/*IRQ2*/
.word vector_handler	/*IRQ3*/
.word vector_handler	/*IRQ4*/
.word vector_handler	/*IRQ5*/
.word vector_handler	/*IRQ6*/
.word vector_handler	/*IRQ7*/

.section .text


_reset:
	bl main
	b .		/*loop on yourself*/

.thumb_func
vector_handler:
	b _reset