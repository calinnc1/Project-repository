################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Asw/Lights/FrontLights/FrontLights.c 

OBJS += \
./Asw/Lights/FrontLights/FrontLights.o 

C_DEPS += \
./Asw/Lights/FrontLights/FrontLights.d 


# Each subdirectory must supply rules for building sources it contributes
Asw/Lights/FrontLights/%.o Asw/Lights/FrontLights/%.su Asw/Lights/FrontLights/%.cyclo: ../Asw/Lights/FrontLights/%.c Asw/Lights/FrontLights/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -DSTM32F303xE -c -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Asw-2f-Lights-2f-FrontLights

clean-Asw-2f-Lights-2f-FrontLights:
	-$(RM) ./Asw/Lights/FrontLights/FrontLights.cyclo ./Asw/Lights/FrontLights/FrontLights.d ./Asw/Lights/FrontLights/FrontLights.o ./Asw/Lights/FrontLights/FrontLights.su

.PHONY: clean-Asw-2f-Lights-2f-FrontLights

