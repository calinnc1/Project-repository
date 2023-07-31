################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Asw/Steering/Steering.c 

OBJS += \
./Asw/Steering/Steering.o 

C_DEPS += \
./Asw/Steering/Steering.d 


# Each subdirectory must supply rules for building sources it contributes
Asw/Steering/%.o Asw/Steering/%.su Asw/Steering/%.cyclo: ../Asw/Steering/%.c Asw/Steering/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -DSTM32F303xE -c -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Asw-2f-Steering

clean-Asw-2f-Steering:
	-$(RM) ./Asw/Steering/Steering.cyclo ./Asw/Steering/Steering.d ./Asw/Steering/Steering.o ./Asw/Steering/Steering.su

.PHONY: clean-Asw-2f-Steering

