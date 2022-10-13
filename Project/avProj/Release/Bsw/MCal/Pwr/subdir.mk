################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Bsw/MCal/Pwr/stm32f3xx_hal_pwr.c \
../Bsw/MCal/Pwr/stm32f3xx_hal_pwr_ex.c 

OBJS += \
./Bsw/MCal/Pwr/stm32f3xx_hal_pwr.o \
./Bsw/MCal/Pwr/stm32f3xx_hal_pwr_ex.o 

C_DEPS += \
./Bsw/MCal/Pwr/stm32f3xx_hal_pwr.d \
./Bsw/MCal/Pwr/stm32f3xx_hal_pwr_ex.d 


# Each subdirectory must supply rules for building sources it contributes
Bsw/MCal/Pwr/%.o Bsw/MCal/Pwr/%.su: ../Bsw/MCal/Pwr/%.c Bsw/MCal/Pwr/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -DSTM32F303xE -c -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Bsw-2f-MCal-2f-Pwr

clean-Bsw-2f-MCal-2f-Pwr:
	-$(RM) ./Bsw/MCal/Pwr/stm32f3xx_hal_pwr.d ./Bsw/MCal/Pwr/stm32f3xx_hal_pwr.o ./Bsw/MCal/Pwr/stm32f3xx_hal_pwr.su ./Bsw/MCal/Pwr/stm32f3xx_hal_pwr_ex.d ./Bsw/MCal/Pwr/stm32f3xx_hal_pwr_ex.o ./Bsw/MCal/Pwr/stm32f3xx_hal_pwr_ex.su

.PHONY: clean-Bsw-2f-MCal-2f-Pwr

