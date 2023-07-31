################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Asw/LED/LED.c 

OBJS += \
./Asw/LED/LED.o 

C_DEPS += \
./Asw/LED/LED.d 


# Each subdirectory must supply rules for building sources it contributes
Asw/LED/%.o Asw/LED/%.su Asw/LED/%.cyclo: ../Asw/LED/%.c Asw/LED/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -DSTM32F303xE -c -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Asw-2f-LED

clean-Asw-2f-LED:
	-$(RM) ./Asw/LED/LED.cyclo ./Asw/LED/LED.d ./Asw/LED/LED.o ./Asw/LED/LED.su

.PHONY: clean-Asw-2f-LED

