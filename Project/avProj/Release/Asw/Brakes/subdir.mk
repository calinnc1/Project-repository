################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Asw/Brakes/Brakes.c 

OBJS += \
./Asw/Brakes/Brakes.o 

C_DEPS += \
./Asw/Brakes/Brakes.d 


# Each subdirectory must supply rules for building sources it contributes
Asw/Brakes/%.o Asw/Brakes/%.su Asw/Brakes/%.cyclo: ../Asw/Brakes/%.c Asw/Brakes/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -DSTM32F303xE -c -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Asw-2f-Brakes

clean-Asw-2f-Brakes:
	-$(RM) ./Asw/Brakes/Brakes.cyclo ./Asw/Brakes/Brakes.d ./Asw/Brakes/Brakes.o ./Asw/Brakes/Brakes.su

.PHONY: clean-Asw-2f-Brakes

