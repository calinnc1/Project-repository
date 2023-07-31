################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Bsw/Cdd/Cdd_DCMotor/Cdd_DCMotor.c 

OBJS += \
./Bsw/Cdd/Cdd_DCMotor/Cdd_DCMotor.o 

C_DEPS += \
./Bsw/Cdd/Cdd_DCMotor/Cdd_DCMotor.d 


# Each subdirectory must supply rules for building sources it contributes
Bsw/Cdd/Cdd_DCMotor/%.o Bsw/Cdd/Cdd_DCMotor/%.su Bsw/Cdd/Cdd_DCMotor/%.cyclo: ../Bsw/Cdd/Cdd_DCMotor/%.c Bsw/Cdd/Cdd_DCMotor/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -DSTM32F303xE -c -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Bsw-2f-Cdd-2f-Cdd_DCMotor

clean-Bsw-2f-Cdd-2f-Cdd_DCMotor:
	-$(RM) ./Bsw/Cdd/Cdd_DCMotor/Cdd_DCMotor.cyclo ./Bsw/Cdd/Cdd_DCMotor/Cdd_DCMotor.d ./Bsw/Cdd/Cdd_DCMotor/Cdd_DCMotor.o ./Bsw/Cdd/Cdd_DCMotor/Cdd_DCMotor.su

.PHONY: clean-Bsw-2f-Cdd-2f-Cdd_DCMotor

