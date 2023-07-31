################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Rte/Rte.c 

OBJS += \
./Rte/Rte.o 

C_DEPS += \
./Rte/Rte.d 


# Each subdirectory must supply rules for building sources it contributes
Rte/%.o Rte/%.su Rte/%.cyclo: ../Rte/%.c Rte/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -DSTM32F303xE -c -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Rte

clean-Rte:
	-$(RM) ./Rte/Rte.cyclo ./Rte/Rte.d ./Rte/Rte.o ./Rte/Rte.su

.PHONY: clean-Rte

