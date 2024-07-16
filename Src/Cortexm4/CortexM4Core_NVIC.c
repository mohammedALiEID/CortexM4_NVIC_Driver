


/**
 ******************************************************************************
 * @file           : CortexM4Core_NVIC.c
 * @author         : Mohamed Ali
 * @brief          :Contain the static code for CortexM4Core_NVIC.c
 ******************************************************************************

 */


/*********************** Includes Start ****************************************/


#include "Cortexm4/CortexM4Core_NVIC.h"
/*********************** Includes end ******************************************/


/*********************** Macro Start *******************************************/

/*********************** Macro end *********************************************/


/*********************** Macro function  Start *********************************/

/*********************** Macro function  end ***********************************/


/*********************** Data types  Start **************************************/

/*********************** Data types end   **************************************/


/***********************  Software interface Implementation  Start **************************************/
/**
 * @brief  Enables the specified interrupt.
 * @param  IRQn: The IRQ number of the interrupt to enable.
 *               This parameter can be an enumerator from IRQn_Type.
 * @retval None
 *  note    IRQn must not be negative
 */
void NVIC_EnableIRQ(IRQn_Type IRQn){

	if (((uint8_t)IRQn)>=0){

		NVIC->NVIC_ISER[(uint8_t)IRQn/32]|=(1UL<<((uint8_t)IRQn%32)) ;


		//NVIC->NVIC_ISER[((uint8_t)IRQn)>>5] = (1UL<<(((uint8_t)IRQn)& 0x1f)) ;


	}



}



/**
 * @brief  Disables the specified interrupt.
 * @param  IRQn: The IRQ number of the interrupt to disable.
 *               This parameter can be an enumerator from IRQn_Type.
 * @retval None
 *  note    IRQn must not be negative
 */
void NVIC_DisableIRQ(IRQn_Type IRQn){
	if (((uint8_t)IRQn)>=0){


		NVIC->NVIC_ICER[(uint8_t)IRQn/32]|=(1UL<<((uint8_t)IRQn%32)) ;


		//NVIC->NVIC_ICER[((uint8_t)IRQn)>>5] = (1UL<<(((uint8_t)IRQn)& 0x1f)) ;



	}
}

/**
 * @brief  Sets the pending status of the specified interrupt.
 * @param  IRQn: The IRQ number of the interrupt to set pending.
 *               This parameter can be an enumerator from IRQn_Type.
 * @retval None
 *  note    IRQn must not be negative
 */
void NVIC_SetPendingIRQ(IRQn_Type IRQn){
	if (((uint8_t)IRQn)>=0){

		NVIC->NVIC_ISPR[(uint8_t)IRQn/32]|=(1UL<<((uint8_t)IRQn%32)) ;


		//NVIC->NVIC_ISPR[((uint8_t)IRQn)>>5] = (1UL<<(((uint8_t)IRQn)& 0x1f)) ;

	}

}

/**
 * @brief  Clears the pending status of the specified interrupt.
 * @param  IRQn: The IRQ number of the interrupt to clear pending.
 *               This parameter can be an enumerator from IRQn_Type.
 * @retval None
 *  note    IRQn must not be negative
 */
void NVIC_ClearPendingIRQ(IRQn_Type IRQn){
	if (((uint8_t)IRQn)>=0){

		NVIC->NVIC_ICPR[(uint8_t)IRQn/32]|=(1UL<<((uint8_t)IRQn%32)) ;


		//NVIC->NVIC_ICPR[((uint8_t)IRQn)>>5] = (1UL<<(((uint8_t)IRQn)& 0x1f)) ;
	}


}


/**
 * @brief  Gets the active status of the specified interrupt.
 * @param  IRQn: The IRQ number of the interrupt to get the active status.
 *               This parameter can be an enumerator from IRQn_Type.
 * @retval 1 if the interrupt is active, 0 otherwise.
 *  note    IRQn must not be negative
 */
uint32_t NVIC_GetActive(IRQn_Type IRQn){


	if (((uint8_t)IRQn)>=0){

		//return (NVIC->NVIC_IABR[(uint8_t)IRQn/32]!=0 )? 1UL :0UL ;

		return (((NVIC->NVIC_IABR[(uint8_t)IRQn/32])>>(IRQn%32))&(1UL)) ;
	}
	else {

		return 0UL ;
	}




}
/**
 * @brief  Sets the priority of the specified interrupt.
 * @param  IRQn: The IRQ number of the interrupt to set the priority.
 *               This parameter can be an enumerator from IRQn_Type.
 * @param  priority: The priority to set for the interrupt.
 *                   This parameter can be a value [4]:[7] 0 to 15 in decimal for STM32 cortexM4
 *                   where lower values correspond to higher priority.
 * @retval None
 *  note    IRQn must not be negative
 */
void NVIC_SetPriority(IRQn_Type IRQn, uint8_t priority){


	if (((uint8_t)IRQn)>=0){


		NVIC->NVIC_IPR[(uint8_t)IRQn] =(priority<<4) ;

		// for general Equation  NVIC->NVIC_IPR[(uint8_t)IRQn] =(priority<<8-NVIC_NUMBER_OF_PRIORITY_BITS) ;


	}
	else {

		/*nothing*/
	}




}

/**
 * @brief  Gets the priority of the specified interrupt.
 * @param  IRQn: The IRQ number of the interrupt to get the priority.
 *               This parameter can be an enumerator from IRQn_Type.
 * @retval The priority of the specified interrupt.
 *         This return value is a uint32_t representing the priority.
 *         For STM32 Cortex-M4, the priority is in the range [4]:[7] 0 to 15
 *         where lower values correspond to higher priority.
 * @note   IRQn must not be negative.
 */
uint8_t NVIC_GetPriority(IRQn_Type IRQn){



	if (((uint8_t)IRQn)>=0){


		return ((NVIC->NVIC_IPR[(uint8_t)IRQn])>>4) ;

		// for general Equation  return ((NVIC->NVIC_IPR[(uint8_t)IRQn])>>(8-NVIC_NUMBER_OF_PRIORITY_BITS)) ; ;
	}
	else {

		/*nothing*/
	}








}



/**
 * @brief Triggers a software interrupt for the given IRQ number.
 *
 * This function writes to the Software Trigger Interrupt Register (STIR)
 * to generate an interrupt request for the specified IRQ number.
 *
 * @param IRQn The IRQ number to trigger. This should be a value of type IRQn_Type,
 *
 */

void NVIC_triggerSoftware_interrupt(IRQn_Type IRQn){


	if (((uint8_t)IRQn)>=0){


		NVIC->STIR=(uint32_t)IRQn ;

	}
	else {

		/*nothing*/
	}





}



/*********************** Software interface Implementation  end   **************************************/

