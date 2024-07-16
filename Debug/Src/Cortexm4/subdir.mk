################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/Cortexm4/CortexM4Core_NVIC.c \
../Src/Cortexm4/CortexM4Core_SCB.c 

OBJS += \
./Src/Cortexm4/CortexM4Core_NVIC.o \
./Src/Cortexm4/CortexM4Core_SCB.o 

C_DEPS += \
./Src/Cortexm4/CortexM4Core_NVIC.d \
./Src/Cortexm4/CortexM4Core_SCB.d 


# Each subdirectory must supply rules for building sources it contributes
Src/Cortexm4/%.o Src/Cortexm4/%.su Src/Cortexm4/%.cyclo: ../Src/Cortexm4/%.c Src/Cortexm4/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DNUCLEO_F411RE -DSTM32 -DSTM32F4 -DSTM32F411RETx -c -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Src-2f-Cortexm4

clean-Src-2f-Cortexm4:
	-$(RM) ./Src/Cortexm4/CortexM4Core_NVIC.cyclo ./Src/Cortexm4/CortexM4Core_NVIC.d ./Src/Cortexm4/CortexM4Core_NVIC.o ./Src/Cortexm4/CortexM4Core_NVIC.su ./Src/Cortexm4/CortexM4Core_SCB.cyclo ./Src/Cortexm4/CortexM4Core_SCB.d ./Src/Cortexm4/CortexM4Core_SCB.o ./Src/Cortexm4/CortexM4Core_SCB.su

.PHONY: clean-Src-2f-Cortexm4

