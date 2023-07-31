################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Bsw/MCal/Gpt/Gpt.c \
../Bsw/MCal/Gpt/stm32f3xx_hal_tim.c \
../Bsw/MCal/Gpt/stm32f3xx_hal_tim_ex.c 

OBJS += \
./Bsw/MCal/Gpt/Gpt.o \
./Bsw/MCal/Gpt/stm32f3xx_hal_tim.o \
./Bsw/MCal/Gpt/stm32f3xx_hal_tim_ex.o 

C_DEPS += \
./Bsw/MCal/Gpt/Gpt.d \
./Bsw/MCal/Gpt/stm32f3xx_hal_tim.d \
./Bsw/MCal/Gpt/stm32f3xx_hal_tim_ex.d 


# Each subdirectory must supply rules for building sources it contributes
Bsw/MCal/Gpt/%.o Bsw/MCal/Gpt/%.su Bsw/MCal/Gpt/%.cyclo: ../Bsw/MCal/Gpt/%.c Bsw/MCal/Gpt/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -DSTM32F303xE -c -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Bsw-2f-MCal-2f-Gpt

clean-Bsw-2f-MCal-2f-Gpt:
	-$(RM) ./Bsw/MCal/Gpt/Gpt.cyclo ./Bsw/MCal/Gpt/Gpt.d ./Bsw/MCal/Gpt/Gpt.o ./Bsw/MCal/Gpt/Gpt.su ./Bsw/MCal/Gpt/stm32f3xx_hal_tim.cyclo ./Bsw/MCal/Gpt/stm32f3xx_hal_tim.d ./Bsw/MCal/Gpt/stm32f3xx_hal_tim.o ./Bsw/MCal/Gpt/stm32f3xx_hal_tim.su ./Bsw/MCal/Gpt/stm32f3xx_hal_tim_ex.cyclo ./Bsw/MCal/Gpt/stm32f3xx_hal_tim_ex.d ./Bsw/MCal/Gpt/stm32f3xx_hal_tim_ex.o ./Bsw/MCal/Gpt/stm32f3xx_hal_tim_ex.su

.PHONY: clean-Bsw-2f-MCal-2f-Gpt

