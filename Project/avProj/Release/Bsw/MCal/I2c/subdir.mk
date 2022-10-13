################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Bsw/MCal/I2c/stm32f3xx_hal_i2c.c \
../Bsw/MCal/I2c/stm32f3xx_hal_i2c_ex.c 

OBJS += \
./Bsw/MCal/I2c/stm32f3xx_hal_i2c.o \
./Bsw/MCal/I2c/stm32f3xx_hal_i2c_ex.o 

C_DEPS += \
./Bsw/MCal/I2c/stm32f3xx_hal_i2c.d \
./Bsw/MCal/I2c/stm32f3xx_hal_i2c_ex.d 


# Each subdirectory must supply rules for building sources it contributes
Bsw/MCal/I2c/%.o Bsw/MCal/I2c/%.su: ../Bsw/MCal/I2c/%.c Bsw/MCal/I2c/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -DSTM32F303xE -c -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Bsw-2f-MCal-2f-I2c

clean-Bsw-2f-MCal-2f-I2c:
	-$(RM) ./Bsw/MCal/I2c/stm32f3xx_hal_i2c.d ./Bsw/MCal/I2c/stm32f3xx_hal_i2c.o ./Bsw/MCal/I2c/stm32f3xx_hal_i2c.su ./Bsw/MCal/I2c/stm32f3xx_hal_i2c_ex.d ./Bsw/MCal/I2c/stm32f3xx_hal_i2c_ex.o ./Bsw/MCal/I2c/stm32f3xx_hal_i2c_ex.su

.PHONY: clean-Bsw-2f-MCal-2f-I2c

