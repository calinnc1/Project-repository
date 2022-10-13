################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Bsw/MCal/Dma/stm32f3xx_hal_dma.c 

OBJS += \
./Bsw/MCal/Dma/stm32f3xx_hal_dma.o 

C_DEPS += \
./Bsw/MCal/Dma/stm32f3xx_hal_dma.d 


# Each subdirectory must supply rules for building sources it contributes
Bsw/MCal/Dma/%.o Bsw/MCal/Dma/%.su: ../Bsw/MCal/Dma/%.c Bsw/MCal/Dma/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -DSTM32F303xE -c -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Bsw-2f-MCal-2f-Dma

clean-Bsw-2f-MCal-2f-Dma:
	-$(RM) ./Bsw/MCal/Dma/stm32f3xx_hal_dma.d ./Bsw/MCal/Dma/stm32f3xx_hal_dma.o ./Bsw/MCal/Dma/stm32f3xx_hal_dma.su

.PHONY: clean-Bsw-2f-MCal-2f-Dma

