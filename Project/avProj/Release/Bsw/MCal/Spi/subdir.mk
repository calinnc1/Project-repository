################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Bsw/MCal/Spi/stm32f3xx_hal_spi.c \
../Bsw/MCal/Spi/stm32f3xx_hal_spi_ex.c 

OBJS += \
./Bsw/MCal/Spi/stm32f3xx_hal_spi.o \
./Bsw/MCal/Spi/stm32f3xx_hal_spi_ex.o 

C_DEPS += \
./Bsw/MCal/Spi/stm32f3xx_hal_spi.d \
./Bsw/MCal/Spi/stm32f3xx_hal_spi_ex.d 


# Each subdirectory must supply rules for building sources it contributes
Bsw/MCal/Spi/%.o Bsw/MCal/Spi/%.su Bsw/MCal/Spi/%.cyclo: ../Bsw/MCal/Spi/%.c Bsw/MCal/Spi/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -DSTM32F303xE -c -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Bsw-2f-MCal-2f-Spi

clean-Bsw-2f-MCal-2f-Spi:
	-$(RM) ./Bsw/MCal/Spi/stm32f3xx_hal_spi.cyclo ./Bsw/MCal/Spi/stm32f3xx_hal_spi.d ./Bsw/MCal/Spi/stm32f3xx_hal_spi.o ./Bsw/MCal/Spi/stm32f3xx_hal_spi.su ./Bsw/MCal/Spi/stm32f3xx_hal_spi_ex.cyclo ./Bsw/MCal/Spi/stm32f3xx_hal_spi_ex.d ./Bsw/MCal/Spi/stm32f3xx_hal_spi_ex.o ./Bsw/MCal/Spi/stm32f3xx_hal_spi_ex.su

.PHONY: clean-Bsw-2f-MCal-2f-Spi

