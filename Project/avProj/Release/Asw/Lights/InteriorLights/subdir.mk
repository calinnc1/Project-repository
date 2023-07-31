################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Asw/Lights/InteriorLights/InteriorLights.c 

OBJS += \
./Asw/Lights/InteriorLights/InteriorLights.o 

C_DEPS += \
./Asw/Lights/InteriorLights/InteriorLights.d 


# Each subdirectory must supply rules for building sources it contributes
Asw/Lights/InteriorLights/%.o Asw/Lights/InteriorLights/%.su Asw/Lights/InteriorLights/%.cyclo: ../Asw/Lights/InteriorLights/%.c Asw/Lights/InteriorLights/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -DSTM32F303xE -c -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Asw-2f-Lights-2f-InteriorLights

clean-Asw-2f-Lights-2f-InteriorLights:
	-$(RM) ./Asw/Lights/InteriorLights/InteriorLights.cyclo ./Asw/Lights/InteriorLights/InteriorLights.d ./Asw/Lights/InteriorLights/InteriorLights.o ./Asw/Lights/InteriorLights/InteriorLights.su

.PHONY: clean-Asw-2f-Lights-2f-InteriorLights

