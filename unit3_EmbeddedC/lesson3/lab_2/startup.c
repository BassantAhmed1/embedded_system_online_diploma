//startup.c 
//Eng.Bassant

#include <stdint.h>
extern int main(void);

void Reset_Handler ();
void NMI_Handler();
void H_fault_Handler();
void MM_fault_Handler();
void Bus_fault();
void Usage_fault_Handler();

uint32_t vectors[] __attribute__((section(".vectors"))) = {
	(uint32_t) 0x20001000,
	(uint32_t) &Reset_Handler,
	(uint32_t) &NMI_Handler,
	(uint32_t) &H_fault_Handler,
	(uint32_t) &MM_fault_Handler,
	(uint32_t) &Bus_fault,
	(uint32_t) &Usage_fault_Handler
};

void Reset_Handler (void)
{
	main();
}
void NMI_Handler(void)
{
	Reset_Handler();
}
void H_fault_Handler(void){
	Reset_Handler();
}
void MM_fault_Handler(void){
	Reset_Handler();
}
void Bus_fault(void){
	Reset_Handler();
}
void Usage_fault_Handler(void){
	Reset_Handler();
}
