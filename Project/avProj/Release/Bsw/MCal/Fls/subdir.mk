################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Bsw/MCal/Fls/stm32f3xx_hal_flash.c \
../Bsw/MCal/Fls/stm32f3xx_hal_flash_ex.c 

OBJS += \
./Bsw/MCal/Fls/stm32f3xx_hal_flash.o \
./Bsw/MCal/Fls/stm32f3xx_hal_flash_ex.o 

C_DEPS += \
./Bsw/MCal/Fls/stm32f3xx_hal_flash.d \
./Bsw/MCal/Fls/stm32f3xx_hal_flash_ex.d 


# Each subdirectory must supply rules for building sources it contributes
Bsw/MCal/Fls/%.o Bsw/MCal/Fls/%.su Bsw/MCal/Fls/%.cyclo: ../Bsw/MCal/Fls/%.c Bsw/MCal/Fls/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -DSTM32F303xE -c -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Bsw-2f-MCal-2f-Fls

clean-Bsw-2f-MCal-2f-Fls:
	-$(RM) ./Bsw/MCal/Fls/stm32f3xx_hal_flash.cyclo ./Bsw/MCal/Fls/stm32f3xx_hal_flash.d ./Bsw/MCal/Fls/stm32f3xx_hal_flash.o ./Bsw/MCal/Fls/stm32f3xx_hal_flash.su ./Bsw/MCal/Fls/stm32f3xx_hal_flash_ex.cyclo ./Bsw/MCal/Fls/stm32f3xx_hal_flash_ex.d ./Bsw/MCal/Fls/stm32f3xx_hal_flash_ex.o ./Bsw/MCal/Fls/stm32f3xx_hal_flash_ex.su

.PHONY: clean-Bsw-2f-MCal-2f-Fls

