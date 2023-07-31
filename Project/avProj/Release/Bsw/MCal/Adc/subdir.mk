################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Bsw/MCal/Adc/stm32f3xx_hal_adc.c \
../Bsw/MCal/Adc/stm32f3xx_hal_adc_ex.c 

OBJS += \
./Bsw/MCal/Adc/stm32f3xx_hal_adc.o \
./Bsw/MCal/Adc/stm32f3xx_hal_adc_ex.o 

C_DEPS += \
./Bsw/MCal/Adc/stm32f3xx_hal_adc.d \
./Bsw/MCal/Adc/stm32f3xx_hal_adc_ex.d 


# Each subdirectory must supply rules for building sources it contributes
Bsw/MCal/Adc/%.o Bsw/MCal/Adc/%.su Bsw/MCal/Adc/%.cyclo: ../Bsw/MCal/Adc/%.c Bsw/MCal/Adc/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -DSTM32F303xE -c -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Bsw-2f-MCal-2f-Adc

clean-Bsw-2f-MCal-2f-Adc:
	-$(RM) ./Bsw/MCal/Adc/stm32f3xx_hal_adc.cyclo ./Bsw/MCal/Adc/stm32f3xx_hal_adc.d ./Bsw/MCal/Adc/stm32f3xx_hal_adc.o ./Bsw/MCal/Adc/stm32f3xx_hal_adc.su ./Bsw/MCal/Adc/stm32f3xx_hal_adc_ex.cyclo ./Bsw/MCal/Adc/stm32f3xx_hal_adc_ex.d ./Bsw/MCal/Adc/stm32f3xx_hal_adc_ex.o ./Bsw/MCal/Adc/stm32f3xx_hal_adc_ex.su

.PHONY: clean-Bsw-2f-MCal-2f-Adc

