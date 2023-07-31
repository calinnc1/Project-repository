################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Asw/Lights/Blinker/Blinker.c 

OBJS += \
./Asw/Lights/Blinker/Blinker.o 

C_DEPS += \
./Asw/Lights/Blinker/Blinker.d 


# Each subdirectory must supply rules for building sources it contributes
Asw/Lights/Blinker/%.o Asw/Lights/Blinker/%.su Asw/Lights/Blinker/%.cyclo: ../Asw/Lights/Blinker/%.c Asw/Lights/Blinker/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -DSTM32F303xE -c -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Asw-2f-Lights-2f-Blinker

clean-Asw-2f-Lights-2f-Blinker:
	-$(RM) ./Asw/Lights/Blinker/Blinker.cyclo ./Asw/Lights/Blinker/Blinker.d ./Asw/Lights/Blinker/Blinker.o ./Asw/Lights/Blinker/Blinker.su

.PHONY: clean-Asw-2f-Lights-2f-Blinker

