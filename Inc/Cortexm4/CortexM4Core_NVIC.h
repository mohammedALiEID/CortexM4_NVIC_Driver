
/**
 ******************************************************************************
 * @file           : CortexM4Core_NVIC.h
 * @author         : Mohamed Ali
 * @brief          :Contain the static code for CortexM4Core_NVIC.c
 ******************************************************************************

 */
#ifndef CORTEXM4CORE_NVIC_H_
#define CORTEXM4CORE_NVIC_H_



/*********************** Includes Start ****************************************/
#include "Common/STD_Data_types.h"
#include "Cortexm4/CortexM4Core_SCB.h"
/*********************** Includes end ******************************************/


/*********************** Macro Start *******************************************/

#define BASE_ADDRESS  (0xE000E100UL)

#define NVIC          ((NVIC_type*)BASE_ADDRESS)


#define NVIC_NUMBER_OF_PRIORITY_BITS     (4U)



#if PRIORITYGROUP ==PRIGROUP_4

// Macros for PRIGROUP4: [7:4] (All 4 bits for group priority, no subpriority bits)


#define MP_0  0b0000
#define MP_1  0b0001
#define MP_2  0b0010
#define MP_3  0b0011
#define MP_4  0b0100
#define MP_5  0b0101
#define MP_6  0b0110
#define MP_7  0b0111
#define MP_8  0b1000
#define MP_9  0b1001
#define MP_10 0b1010
#define MP_11 0b1011
#define MP_12 0b1100
#define MP_13 0b1101
#define MP_14 0b1110
#define MP_15 0b1111

#endif

#if PRIORITYGROUP ==PRIGROUP_3
// Macros for PRIGROUP3: [7:5] (3 bits for group priority, [4] 1 bit for subpriority)

#define MP_0_SP_0 0b0000
#define MP_0_SP_1 0b0001
#define MP_1_SP_0 0b0010
#define MP_1_SP_1 0b0011
#define MP_2_SP_0 0b0100
#define MP_2_SP_1 0b0101
#define MP_3_SP_0 0b0110
#define MP_3_SP_1 0b0111
#define MP_4_SP_0 0b1000
#define MP_4_SP_1 0b1001
#define MP_5_SP_0 0b1010
#define MP_5_SP_1 0b1011
#define MP_6_SP_0 0b1100
#define MP_6_SP_1 0b1101
#define MP_7_SP_0 0b1110
#define MP_7_SP_1 0b1111

#endif

#if PRIORITYGROUP ==PRIGROUP_2
// Macros for PRIGROUP2: [7:6] (2 bits for group priority, [5:4] 2 bits for subpriority)

#define MP_0_SP_0 0b0000
#define MP_0_SP_1 0b0001
#define MP_0_SP_2 0b0010
#define MP_0_SP_3 0b0011
#define MP_1_SP_0 0b0100
#define MP_1_SP_1 0b0101
#define MP_1_SP_2 0b0110
#define MP_1_SP_3 0b0111
#define MP_2_SP_0 0b1000
#define MP_2_SP_1 0b1001
#define MP_2_SP_2 0b1010
#define MP_2_SP_3 0b1011
#define MP_3_SP_0 0b1100
#define MP_3_SP_1 0b1101
#define MP_3_SP_2 0b1110
#define MP_3_SP_3 0b1111

#endif

#if PRIORITYGROUP ==PRIGROUP_1
// Macros for PRIGROUP1: [7] (1 bit for group priority, [6:4] 3 bits for subpriority)

#define MP_0_SP_0 0b0000
#define MP_0_SP_1 0b0001
#define MP_0_SP_2 0b0010
#define MP_0_SP_3 0b0011
#define MP_0_SP_4 0b0100
#define MP_0_SP_5 0b0101
#define MP_0_SP_6 0b0110
#define MP_0_SP_7 0b0111
#define MP_1_SP_0 0b1000
#define MP_1_SP_1 0b1001
#define MP_1_SP_2 0b1010
#define MP_1_SP_3 0b1011
#define MP_1_SP_4 0b1100
#define MP_1_SP_5 0b1101
#define MP_1_SP_6 0b1110
#define MP_1_SP_7 0b1111

#endif

#if PRIORITYGROUP ==PRIGROUP_0
// Macros for PRIGROUP0: No group priority bits, [7:4] all 4 bits for subpriority // no premption

#define SP_0  0b0000
#define SP_1  0b0001
#define SP_2  0b0010
#define SP_3  0b0011
#define SP_4  0b0100
#define SP_5  0b0101
#define SP_6  0b0110
#define SP_7  0b0111
#define SP_8  0b1000
#define SP_9  0b1001
#define SP_10 0b1010
#define SP_11 0b1011
#define SP_12 0b1100
#define SP_13 0b1101
#define SP_14 0b1110
#define SP_15 0b1111

#endif

/*********************** Macro end *********************************************/


/*********************** Macro function  Start *********************************/

/*********************** Macro function  end ***********************************/


/*********************** Data types  Start **************************************/


typedef struct {

	volatile uint32_t NVIC_ISER[8U] ;
    uint32_t RESERVED_0[24U] ;
    volatile uint32_t NVIC_ICER[8U] ;
    uint32_t RESERVED_1[24U] ;
    volatile uint32_t NVIC_ISPR[8U] ;
    uint32_t RESERVED_2[24U] ;
    volatile uint32_t NVIC_ICPR[8U] ;
    uint32_t RESERVED_3[24U] ;
    volatile uint32_t NVIC_IABR[8U] ;
    uint32_t RESERVED_4[56U] ;
    volatile uint8_t NVIC_IPR[240U] ;
    uint32_t RESERVED_5[644U] ;
    volatile uint32_t STIR ;

}NVIC_type;
typedef enum {
    NonMaskableInt_IRQn         = -14,    /*!< 2 Non Maskable Interrupt                                         */
    MemoryManagement_IRQn       = -12,    /*!< 4 Cortex-M4 Memory Management Interrupt                          */
    BusFault_IRQn               = -11,    /*!< 5 Cortex-M4 Bus Fault Interrupt                                  */
    UsageFault_IRQn             = -10,    /*!< 6 Cortex-M4 Usage Fault Interrupt                                */
    SVCall_IRQn                 = -5,     /*!< 11 Cortex-M4 SV Call Interrupt                                   */
    DebugMonitor_IRQn           = -4,     /*!< 12 Cortex-M4 Debug Monitor Interrupt                             */
    PendSV_IRQn                 = -2,     /*!< 14 Cortex-M4 Pend SV Interrupt                                   */
    SysTick_IRQn                = -1,     /*!< 15 Cortex-M4 System Tick Interrupt                               */





/********************specific IRQ i can control them bu NVIC registers ********************/
    WWDG_IRQn                   = 0,      /*!< Window WatchDog Interrupt                                        */
    PVD_IRQn                    = 1,      /*!< PVD through EXTI Line detection Interrupt                        */
    TAMP_STAMP_IRQn             = 2,      /*!< Tamper and TimeStamp interrupts through the EXTI line            */
    RTC_WKUP_IRQn               = 3,      /*!< RTC Wakeup interrupt through the EXTI line                       */
    FLASH_IRQn                  = 4,      /*!< FLASH global Interrupt                                           */
    RCC_IRQn                    = 5,      /*!< RCC global Interrupt                                             */
    EXTI0_IRQn                  = 6,      /*!< EXTI Line0 Interrupt                                             */
    EXTI1_IRQn                  = 7,      /*!< EXTI Line1 Interrupt                                             */
    EXTI2_IRQn                  = 8,      /*!< EXTI Line2 Interrupt                                             */
    EXTI3_IRQn                  = 9,      /*!< EXTI Line3 Interrupt                                             */
    EXTI4_IRQn                  = 10,     /*!< EXTI Line4 Interrupt                                             */
    DMA1_Stream0_IRQn           = 11,     /*!< DMA1 Stream 0 global Interrupt                                   */
    DMA1_Stream1_IRQn           = 12,     /*!< DMA1 Stream 1 global Interrupt                                   */
    DMA1_Stream2_IRQn           = 13,     /*!< DMA1 Stream 2 global Interrupt                                   */
    DMA1_Stream3_IRQn           = 14,     /*!< DMA1 Stream 3 global Interrupt                                   */
    DMA1_Stream4_IRQn           = 15,     /*!< DMA1 Stream 4 global Interrupt                                   */
    DMA1_Stream5_IRQn           = 16,     /*!< DMA1 Stream 5 global Interrupt                                   */
    DMA1_Stream6_IRQn           = 17,     /*!< DMA1 Stream 6 global Interrupt                                   */
    ADC_IRQn                    = 18,     /*!< ADC1 global Interrupts                                           */
    EXTI9_5_IRQn                = 23,     /*!< External Line[9:5] Interrupts                                    */
    TIM1_BRK_TIM9_IRQn          = 24,     /*!< TIM1 Break interrupt and TIM9 global interrupt                   */
    TIM1_UP_TIM10_IRQn          = 25,     /*!< TIM1 Update Interrupt and TIM10 global interrupt                 */
    TIM1_TRG_COM_TIM11_IRQn     = 26,     /*!< TIM1 Trigger and Commutation Interrupt and TIM11 global interrupt*/
    TIM1_CC_IRQn                = 27,     /*!< TIM1 Capture Compare Interrupt                                   */
    TIM2_IRQn                   = 28,     /*!< TIM2 global Interrupt                                            */
    TIM3_IRQn                   = 29,     /*!< TIM3 global Interrupt                                            */
    TIM4_IRQn                   = 30,     /*!< TIM4 global Interrupt                                            */
    I2C1_EV_IRQn                = 31,     /*!< I2C1 Event Interrupt                                             */
    I2C1_ER_IRQn                = 32,     /*!< I2C1 Error Interrupt                                             */
    I2C2_EV_IRQn                = 33,     /*!< I2C2 Event Interrupt                                             */
    I2C2_ER_IRQn                = 34,     /*!< I2C2 Error Interrupt                                             */
    SPI1_IRQn                   = 35,     /*!< SPI1 global Interrupt                                            */
    SPI2_IRQn                   = 36,     /*!< SPI2 global Interrupt                                            */
    USART1_IRQn                 = 37,     /*!< USART1 global Interrupt                                          */
    USART2_IRQn                 = 38,     /*!< USART2 global Interrupt                                          */
    EXTI15_10_IRQn              = 40,     /*!< External Line[15:10] Interrupts                                  */
    RTC_Alarm_IRQn              = 41,     /*!< RTC Alarm (A and B) through EXTI Line Interrupt                  */
    OTG_FS_WKUP_IRQn            = 42,     /*!< USB OTG FS Wakeup through EXTI line interrupt                    */
    DMA1_Stream7_IRQn           = 47,     /*!< DMA1 Stream7 Interrupt                                           */
    SDIO_IRQn                   = 49,     /*!< SDIO global Interrupt                                            */
    TIM5_IRQn                   = 50,     /*!< TIM5 global Interrupt                                            */
    SPI3_IRQn                   = 51,     /*!< SPI3 global Interrupt                                            */
    DMA2_Stream0_IRQn           = 56,     /*!< DMA2 Stream 0 global Interrupt                                   */
    DMA2_Stream1_IRQn           = 57,     /*!< DMA2 Stream 1 global Interrupt                                   */
    DMA2_Stream2_IRQn           = 58,     /*!< DMA2 Stream 2 global Interrupt                                   */
    DMA2_Stream3_IRQn           = 59,     /*!< DMA2 Stream 3 global Interrupt                                   */
    DMA2_Stream4_IRQn           = 60,     /*!< DMA2 Stream 4 global Interrupt                                   */
    OTG_FS_IRQn                 = 67,     /*!< USB OTG FS global Interrupt                                      */
    DMA2_Stream5_IRQn           = 68,     /*!< DMA2 Stream 5 global interrupt                                   */
    DMA2_Stream6_IRQn           = 69,     /*!< DMA2 Stream 6 global interrupt                                   */
    DMA2_Stream7_IRQn           = 70,     /*!< DMA2 Stream 7 global interrupt                                   */
    USART6_IRQn                 = 71,     /*!< USART6 global interrupt                                          */
    I2C3_EV_IRQn                = 72,     /*!< I2C3 event interrupt                                             */
    I2C3_ER_IRQn                = 73,     /*!< I2C3 error interrupt                                             */
    FPU_IRQn                    = 81,     /*!< FPU global interrupt                                             */
    SPI4_IRQn                   = 84,     /*!< SPI4 global Interrupt                                            */
    SPI5_IRQn                   = 85,     /*!< SPI5 global Interrupt                                            */
    QUADSPI_IRQn                = 92,     /*!< QuadSPI global Interrupt                                         */
    FMPI2C1_EV_IRQn             = 95,     /*!< FMPI2C1 Event Interrupt                                          */
    FMPI2C1_ER_IRQn             = 96      /*!< FMPI2C1 Error Interrupt                                          */
} IRQn_Type;



/*********************** Data types end   **************************************/


/***********************  Software interface Declarations  Start **************************************/
/**
 * @brief  Enables the specified interrupt.
 * @param  IRQn: The IRQ number of the interrupt to enable.
 *               This parameter can be an enumerator from IRQn_Type.
 * @retval None
 * note    IRQn must not be negative
 */
void NVIC_EnableIRQ(IRQn_Type IRQn);

/**
 * @brief  Disables the specified interrupt.
 * @param  IRQn: The IRQ number of the interrupt to disable.
 *               This parameter can be an enumerator from IRQn_Type.
 * @retval None
 *  note    IRQn must not be negative
 */
void NVIC_DisableIRQ(IRQn_Type IRQn);

/**
 * @brief  Sets the pending status of the specified interrupt.
 * @param  IRQn: The IRQ number of the interrupt to set pending.
 *               This parameter can be an enumerator from IRQn_Type.
 * @retval None
 *  note    IRQn must not be negative
 */
void NVIC_SetPendingIRQ(IRQn_Type IRQn);

/**
 * @brief  Clears the pending status of the specified interrupt.
 * @param  IRQn: The IRQ number of the interrupt to clear pending.
 *               This parameter can be an enumerator from IRQn_Type.
 * @retval None
 *  note    IRQn must not be negative
 */
void NVIC_ClearPendingIRQ(IRQn_Type IRQn);


/**
 * @brief  Gets the active status of the specified interrupt.
 * @param  IRQn: The IRQ number of the interrupt to get the active status.
 *               This parameter can be an enumerator from IRQn_Type.
 * @retval 1 if the interrupt is active, 0 otherwise.
 *  note    IRQn must not be negative
 */
uint32_t NVIC_GetActive(IRQn_Type IRQn);

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
void NVIC_SetPriority(IRQn_Type IRQn, uint8_t priority);

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
uint8_t NVIC_GetPriority(IRQn_Type IRQn);




/**
 * @brief Triggers a software interrupt for the given IRQ number.
 *
 * This function writes to the Software Trigger Interrupt Register (STIR)
 * to generate an interrupt request for the specified IRQ number.
 *
 * @param IRQn The IRQ number to trigger. This should be a value of type IRQn_Type,
 *
 */

void NVIC_triggerSoftware_interrupt(IRQn_Type IRQn) ;


/*********************** Software interface Declarations  end   **************************************/














#endif /* CORTEXM4CORE_NVIC_H_ */
