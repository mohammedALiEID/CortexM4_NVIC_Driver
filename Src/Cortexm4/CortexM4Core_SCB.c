/**
 ******************************************************************************
 * @file           :  * CortexM4Core_SCB.c
 * @author         : Mohamed Ali
 * @brief          :Contain the static code for  CortexM4Core system control block
 ******************************************************************************

 */

/*********************** Includes Start ****************************************/

#include "Cortexm4/CortexM4Core_SCB.h"
/*********************** Includes end ******************************************/


/*********************** Macro Start *******************************************/

/*********************** Macro end *********************************************/


/*********************** Macro function  Start *********************************/

/*********************** Macro function  end ***********************************/


/*********************** Data types  Start **************************************/

/*********************** Data types end   **************************************/


/***********************  Software interface Implementation  Start **************************************/

/**
 * @brief   Sets the priority grouping for the system control block (SCB).
 *
 * @param   group: The desired priority grouping value. This value determines
 *                  the split of the interrupt priority levels between pre-emption
 *                  priority and subpriority.
 *
 * @note    The priority grouping controls how the NVIC divides the bits of the
 *          interrupt priority value into a pre-emption priority and a subpriority.
 *          Refer to the specific microcontroller documentation for valid `group` values.
 *
 * @note    Changing the priority grouping may affect the interrupt response time
 *          and handling, so it should be done with care, especially in time-critical
 *          applications.
 *
 * @warning This function should only be called in a privileged mode, as it directly
 *          modifies the SCB registers. Calling this function in an unprivileged mode
 *          will result in a fault.
 */
void SCB_SetPriorityGrouping(uint32_t group){

	uint32_t PRIGROUP_value =(group&((uint32_t)0b111)) ; // to ensure it is just 3 bits

	uint32_t AIRCR_register = 0 ;

	AIRCR_register =(SCB->AIRCR) ;


	AIRCR_register&=(~(SCB_AIRCR_VECTKEY_mask|SCB_AIRCR_PRIGROUPY_mask)) ;// to clear the SCB_VECTKEY bits and PRIGROUP bits

	//AIRCR_register&=((uint32_t)0XF8FF) ; // to clear the SCB_VECTKEY bits and PRIGROUP bits


	AIRCR_register|=((SCB_AIRCR_VECTKEY<<SCB_AIRCR_VECTKEY_POS)|(PRIGROUP_value<<SCB_AIRCR_PRIGROUP_POS)) ;

	SCB->AIRCR =AIRCR_register ;


}

/**
 * \brief   Get Priority Grouping
 * \details Reads the priority grouping field from the NVIC Interrupt Controller.
 * \return  Priority grouping field (SCB->AIRCR [10:8] PRIGROUP field).
 */
uint32_t SCB_GetPriorityGrouping(void){



	return (((SCB->AIRCR)&(SCB_AIRCR_PRIGROUPY_mask))>>SCB_AIRCR_PRIGROUP_POS) ;
}

