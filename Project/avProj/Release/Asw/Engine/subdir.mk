################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Asw/Engine/Engine.c 

OBJS += \
./Asw/Engine/Engine.o 

C_DEPS += \
./Asw/Engine/Engine.d 


# Each subdirectory must supply rules for building sources it contributes
Asw/Engine/%.o Asw/Engine/%.su Asw/Engine/%.cyclo: ../Asw/Engine/%.c Asw/Engine/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -DSTM32F303xE -c -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Asw-2f-Engine

clean-Asw-2f-Engine:
	-$(RM) ./Asw/Engine/Engine.cyclo ./Asw/Engine/Engine.d ./Asw/Engine/Engine.o ./Asw/Engine/Engine.su

.PHONY: clean-Asw-2f-Engine

