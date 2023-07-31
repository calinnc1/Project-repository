################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Bsw/Cdd/Cdd_Ultrasonic/Cdd_Ultrasonic.c 

OBJS += \
./Bsw/Cdd/Cdd_Ultrasonic/Cdd_Ultrasonic.o 

C_DEPS += \
./Bsw/Cdd/Cdd_Ultrasonic/Cdd_Ultrasonic.d 


# Each subdirectory must supply rules for building sources it contributes
Bsw/Cdd/Cdd_Ultrasonic/%.o Bsw/Cdd/Cdd_Ultrasonic/%.su Bsw/Cdd/Cdd_Ultrasonic/%.cyclo: ../Bsw/Cdd/Cdd_Ultrasonic/%.c Bsw/Cdd/Cdd_Ultrasonic/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -DSTM32F303xE -c -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Bsw-2f-Cdd-2f-Cdd_Ultrasonic

clean-Bsw-2f-Cdd-2f-Cdd_Ultrasonic:
	-$(RM) ./Bsw/Cdd/Cdd_Ultrasonic/Cdd_Ultrasonic.cyclo ./Bsw/Cdd/Cdd_Ultrasonic/Cdd_Ultrasonic.d ./Bsw/Cdd/Cdd_Ultrasonic/Cdd_Ultrasonic.o ./Bsw/Cdd/Cdd_Ultrasonic/Cdd_Ultrasonic.su

.PHONY: clean-Bsw-2f-Cdd-2f-Cdd_Ultrasonic

