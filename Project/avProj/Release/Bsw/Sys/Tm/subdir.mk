################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Bsw/Sys/Tm/Tm.c 

OBJS += \
./Bsw/Sys/Tm/Tm.o 

C_DEPS += \
./Bsw/Sys/Tm/Tm.d 


# Each subdirectory must supply rules for building sources it contributes
Bsw/Sys/Tm/%.o Bsw/Sys/Tm/%.su Bsw/Sys/Tm/%.cyclo: ../Bsw/Sys/Tm/%.c Bsw/Sys/Tm/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -DSTM32F303xE -c -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Bsw-2f-Sys-2f-Tm

clean-Bsw-2f-Sys-2f-Tm:
	-$(RM) ./Bsw/Sys/Tm/Tm.cyclo ./Bsw/Sys/Tm/Tm.d ./Bsw/Sys/Tm/Tm.o ./Bsw/Sys/Tm/Tm.su

.PHONY: clean-Bsw-2f-Sys-2f-Tm

