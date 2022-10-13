################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Bsw/MCal/Mcu/mcu.c \
../Bsw/MCal/Mcu/stm32f3xx_hal.c \
../Bsw/MCal/Mcu/stm32f3xx_hal_cortex.c \
../Bsw/MCal/Mcu/stm32f3xx_hal_dma.c \
../Bsw/MCal/Mcu/stm32f3xx_hal_exti.c \
../Bsw/MCal/Mcu/stm32f3xx_hal_gpio.c \
../Bsw/MCal/Mcu/stm32f3xx_hal_rcc.c \
../Bsw/MCal/Mcu/stm32f3xx_hal_rcc_ex.c 

OBJS += \
./Bsw/MCal/Mcu/mcu.o \
./Bsw/MCal/Mcu/stm32f3xx_hal.o \
./Bsw/MCal/Mcu/stm32f3xx_hal_cortex.o \
./Bsw/MCal/Mcu/stm32f3xx_hal_dma.o \
./Bsw/MCal/Mcu/stm32f3xx_hal_exti.o \
./Bsw/MCal/Mcu/stm32f3xx_hal_gpio.o \
./Bsw/MCal/Mcu/stm32f3xx_hal_rcc.o \
./Bsw/MCal/Mcu/stm32f3xx_hal_rcc_ex.o 

C_DEPS += \
./Bsw/MCal/Mcu/mcu.d \
./Bsw/MCal/Mcu/stm32f3xx_hal.d \
./Bsw/MCal/Mcu/stm32f3xx_hal_cortex.d \
./Bsw/MCal/Mcu/stm32f3xx_hal_dma.d \
./Bsw/MCal/Mcu/stm32f3xx_hal_exti.d \
./Bsw/MCal/Mcu/stm32f3xx_hal_gpio.d \
./Bsw/MCal/Mcu/stm32f3xx_hal_rcc.d \
./Bsw/MCal/Mcu/stm32f3xx_hal_rcc_ex.d 


# Each subdirectory must supply rules for building sources it contributes
Bsw/MCal/Mcu/%.o Bsw/MCal/Mcu/%.su: ../Bsw/MCal/Mcu/%.c Bsw/MCal/Mcu/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -DSTM32F303xE -c -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Bsw-2f-MCal-2f-Mcu

clean-Bsw-2f-MCal-2f-Mcu:
	-$(RM) ./Bsw/MCal/Mcu/mcu.d ./Bsw/MCal/Mcu/mcu.o ./Bsw/MCal/Mcu/mcu.su ./Bsw/MCal/Mcu/stm32f3xx_hal.d ./Bsw/MCal/Mcu/stm32f3xx_hal.o ./Bsw/MCal/Mcu/stm32f3xx_hal.su ./Bsw/MCal/Mcu/stm32f3xx_hal_cortex.d ./Bsw/MCal/Mcu/stm32f3xx_hal_cortex.o ./Bsw/MCal/Mcu/stm32f3xx_hal_cortex.su ./Bsw/MCal/Mcu/stm32f3xx_hal_dma.d ./Bsw/MCal/Mcu/stm32f3xx_hal_dma.o ./Bsw/MCal/Mcu/stm32f3xx_hal_dma.su ./Bsw/MCal/Mcu/stm32f3xx_hal_exti.d ./Bsw/MCal/Mcu/stm32f3xx_hal_exti.o ./Bsw/MCal/Mcu/stm32f3xx_hal_exti.su ./Bsw/MCal/Mcu/stm32f3xx_hal_gpio.d ./Bsw/MCal/Mcu/stm32f3xx_hal_gpio.o ./Bsw/MCal/Mcu/stm32f3xx_hal_gpio.su ./Bsw/MCal/Mcu/stm32f3xx_hal_rcc.d ./Bsw/MCal/Mcu/stm32f3xx_hal_rcc.o ./Bsw/MCal/Mcu/stm32f3xx_hal_rcc.su ./Bsw/MCal/Mcu/stm32f3xx_hal_rcc_ex.d ./Bsw/MCal/Mcu/stm32f3xx_hal_rcc_ex.o ./Bsw/MCal/Mcu/stm32f3xx_hal_rcc_ex.su

.PHONY: clean-Bsw-2f-MCal-2f-Mcu

