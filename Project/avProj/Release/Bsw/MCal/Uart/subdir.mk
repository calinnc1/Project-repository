################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Bsw/MCal/Uart/stm32f3xx_hal_uart.c \
../Bsw/MCal/Uart/stm32f3xx_hal_uart_ex.c 

OBJS += \
./Bsw/MCal/Uart/stm32f3xx_hal_uart.o \
./Bsw/MCal/Uart/stm32f3xx_hal_uart_ex.o 

C_DEPS += \
./Bsw/MCal/Uart/stm32f3xx_hal_uart.d \
./Bsw/MCal/Uart/stm32f3xx_hal_uart_ex.d 


# Each subdirectory must supply rules for building sources it contributes
Bsw/MCal/Uart/%.o Bsw/MCal/Uart/%.su Bsw/MCal/Uart/%.cyclo: ../Bsw/MCal/Uart/%.c Bsw/MCal/Uart/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -DSTM32F303xE -c -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Bsw-2f-MCal-2f-Uart

clean-Bsw-2f-MCal-2f-Uart:
	-$(RM) ./Bsw/MCal/Uart/stm32f3xx_hal_uart.cyclo ./Bsw/MCal/Uart/stm32f3xx_hal_uart.d ./Bsw/MCal/Uart/stm32f3xx_hal_uart.o ./Bsw/MCal/Uart/stm32f3xx_hal_uart.su ./Bsw/MCal/Uart/stm32f3xx_hal_uart_ex.cyclo ./Bsw/MCal/Uart/stm32f3xx_hal_uart_ex.d ./Bsw/MCal/Uart/stm32f3xx_hal_uart_ex.o ./Bsw/MCal/Uart/stm32f3xx_hal_uart_ex.su

.PHONY: clean-Bsw-2f-MCal-2f-Uart

