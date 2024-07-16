



/**
 ******************************************************************************
 * @file           :  * CortexM4Core_SCB.h
 * @author         : Mohamed Ali
 * @brief          :Contain the static code for  CortexM4Core_SCB.h
 ******************************************************************************

 */
#ifndef CORTEXM4CORE_SCB_H_
#define CORTEXM4CORE_SCB_H_




/*********************** Includes Start ****************************************/
#include "Common/STD_Data_types.h"
/*********************** Includes end ******************************************/


/*********************** Macro Start *******************************************/

#define    SCB_BASE_ADRESS          (0xE000ED00)
#define    SCB                      ( (SCB_Type*)SCB_BASE_ADRESS)


#define SCB_AIRCR_VECTKEY           ((uint32_t )(0x5FA))
#define SCB_AIRCR_VECTKEY_POS       (16U)
#define SCB_AIRCR_PRIGROUP_POS      (8U)
#define SCB_AIRCR_VECTKEY_mask      (0xffffUL<<16)
#define SCB_AIRCR_PRIGROUPY_mask    (0b111UL<<8)



// PRIGROUP field values with detailed comments
#define PRIGROUP_4 0b000  // [7:4] (All 4 bits for group priority, no sub priority bits)

#define PRIGROUP_3 0b100  //  [7:5] (3 bits for group priority,[4] 1 bit for sub priority)

#define PRIGROUP_2 0b101  // [7:6] (2 bits for group priority,[5:4]  2 bits for sub priority)

#define PRIGROUP_1 0b110  //  [7]  (1 bit for group priority,[6:4] 3 bits for sub priority)

#define PRIGROUP_0 0b111  //  None (No group priority bits, [7:4] all 4 bits for sub priority)

#define PRIORITYGROUP    PRIGROUP_2


/*********************** Macro end *********************************************/

/*********************** Macro function  Start *********************************/

/*********************** Macro function  end ***********************************/


/*********************** Data types  Start **************************************/

typedef struct {
    volatile uint32_t CPUID;     // CPUID Base Register
    volatile uint32_t ICSR;      // Interrupt Control and State Register
    volatile uint32_t VTOR;      // Vector Table Offset Register
    volatile uint32_t AIRCR;     // Application Interrupt and Reset Control Register
    volatile uint32_t SCR;       // System Control Register
    volatile uint32_t CCR;       // Configuration and Control Register
    volatile uint32_t SHPR[3];   // System Handler Priority Registers (SHPR1, SHPR2, SHPR3)
    volatile uint32_t SHCSR;     // System Handler Control and State Register
    volatile uint32_t CFSR;      // Configurable Fault Status Register

} SCB_Type;


/*********************** Data types end   **************************************/


/***********************  Software interface Declarations  Start **************************************/

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
void SCB_SetPriorityGrouping(uint32_t group);

/**
 * \brief   Get Priority Grouping
 * \details Reads the priority grouping field from the NVIC Interrupt Controller.
 * \return  Priority grouping field (SCB->AIRCR [10:8] PRIGROUP field).
 */
uint32_t SCB_GetPriorityGrouping(void);



#endif /* CORTEXM4CORE_SCB_H_ */
