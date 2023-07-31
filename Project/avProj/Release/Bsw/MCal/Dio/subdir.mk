################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Bsw/MCal/Dio/stm32f3xx_hal_gpio.c 

OBJS += \
./Bsw/MCal/Dio/stm32f3xx_hal_gpio.o 

C_DEPS += \
./Bsw/MCal/Dio/stm32f3xx_hal_gpio.d 


# Each subdirectory must supply rules for building sources it contributes
Bsw/MCal/Dio/%.o Bsw/MCal/Dio/%.su Bsw/MCal/Dio/%.cyclo: ../Bsw/MCal/Dio/%.c Bsw/MCal/Dio/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -DSTM32F303xE -c -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Bsw-2f-MCal-2f-Dio

clean-Bsw-2f-MCal-2f-Dio:
	-$(RM) ./Bsw/MCal/Dio/stm32f3xx_hal_gpio.cyclo ./Bsw/MCal/Dio/stm32f3xx_hal_gpio.d ./Bsw/MCal/Dio/stm32f3xx_hal_gpio.o ./Bsw/MCal/Dio/stm32f3xx_hal_gpio.su

.PHONY: clean-Bsw-2f-MCal-2f-Dio

