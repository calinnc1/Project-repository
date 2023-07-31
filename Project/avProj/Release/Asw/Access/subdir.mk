################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Asw/Access/Access.c 

OBJS += \
./Asw/Access/Access.o 

C_DEPS += \
./Asw/Access/Access.d 


# Each subdirectory must supply rules for building sources it contributes
Asw/Access/%.o Asw/Access/%.su Asw/Access/%.cyclo: ../Asw/Access/%.c Asw/Access/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -DSTM32F303xE -c -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Asw-2f-Access

clean-Asw-2f-Access:
	-$(RM) ./Asw/Access/Access.cyclo ./Asw/Access/Access.d ./Asw/Access/Access.o ./Asw/Access/Access.su

.PHONY: clean-Asw-2f-Access

