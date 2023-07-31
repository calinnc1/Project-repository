################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Asw/Lights/RearLights/RearLights.c 

OBJS += \
./Asw/Lights/RearLights/RearLights.o 

C_DEPS += \
./Asw/Lights/RearLights/RearLights.d 


# Each subdirectory must supply rules for building sources it contributes
Asw/Lights/RearLights/%.o Asw/Lights/RearLights/%.su Asw/Lights/RearLights/%.cyclo: ../Asw/Lights/RearLights/%.c Asw/Lights/RearLights/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -DSTM32F303xE -c -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Asw-2f-Lights-2f-RearLights

clean-Asw-2f-Lights-2f-RearLights:
	-$(RM) ./Asw/Lights/RearLights/RearLights.cyclo ./Asw/Lights/RearLights/RearLights.d ./Asw/Lights/RearLights/RearLights.o ./Asw/Lights/RearLights/RearLights.su

.PHONY: clean-Asw-2f-Lights-2f-RearLights

