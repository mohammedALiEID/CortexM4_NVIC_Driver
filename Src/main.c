/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Mohamed Ali
 * @brief          : Main program body
 ******************************************************************************

 */

#include "Cortexm4/CortexM4Core_NVIC.h"
#include "Cortexm4/CortexM4Core_SCB.h"


uint32_t PriorityGroupValue= 0 ;

uint32_t PriorityValue= 0 ;

uint8_t volatile USART1_IRQHandler_flag = 0 ;
uint8_t volatile USART2_IRQHandler_flag = 0 ;
uint8_t volatile EXTI15_10_IRQHandler_flag = 0 ;

uint8_t volatile USART1_IRQHandler_active_flage1 = 0 ;
uint8_t volatile USART1_IRQHandler_active_flage2 = 0 ;
int main(void)
{

	 // NVIC_EnableIRQ(USART2_IRQn) ;
	//  NVIC_triggerSoftware_interrupt(USART2_IRQn) ;



	SCB_SetPriorityGrouping(PRIGROUP_2) ;
	// if i do not want preemption SCB_SetPriorityGrouping(PRIGROUP_0) ; no group priority


	PriorityGroupValue =SCB_GetPriorityGrouping() ;


	    NVIC_EnableIRQ(USART1_IRQn) ;
		NVIC_EnableIRQ(USART2_IRQn) ;
		NVIC_EnableIRQ(EXTI15_10_IRQn) ;



	NVIC_SetPriority(USART1_IRQn ,MP_2_SP_0) ; //8
	NVIC_SetPriority(USART2_IRQn ,MP_1_SP_0) ; // 4
	NVIC_SetPriority(EXTI15_10_IRQn ,MP_0_SP_0) ; //0


	PriorityValue= NVIC_GetPriority(USART1_IRQn) ;
	PriorityValue= NVIC_GetPriority(USART2_IRQn) ;
	PriorityValue= NVIC_GetPriority(EXTI15_10_IRQn) ;

	NVIC_SetPendingIRQ(USART1_IRQn) ;





	while(1){
		//USART1_IRQHandler_active_flage1=NVIC_GetActive(USART1_IRQn) ;

	}
}

void USART1_IRQHandler (void){

	USART1_IRQHandler_flag = 1 ;
	NVIC_SetPendingIRQ(USART2_IRQn) ;

	USART1_IRQHandler_flag = 2 ;
}
void USART2_IRQHandler (void){

	USART2_IRQHandler_flag=1 ;

	NVIC_SetPendingIRQ(EXTI15_10_IRQn) ;
	USART2_IRQHandler_flag=2 ;
}
void EXTI15_10_IRQHandler (void){

	EXTI15_10_IRQHandler_flag=1 ;


	EXTI15_10_IRQHandler_flag=2 ;

}
