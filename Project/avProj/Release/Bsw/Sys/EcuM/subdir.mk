################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Bsw/Sys/EcuM/EcuM.c 

OBJS += \
./Bsw/Sys/EcuM/EcuM.o 

C_DEPS += \
./Bsw/Sys/EcuM/EcuM.d 


# Each subdirectory must supply rules for building sources it contributes
Bsw/Sys/EcuM/%.o Bsw/Sys/EcuM/%.su: ../Bsw/Sys/EcuM/%.c Bsw/Sys/EcuM/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -DSTM32F303xE -c -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Bsw-2f-Sys-2f-EcuM

clean-Bsw-2f-Sys-2f-EcuM:
	-$(RM) ./Bsw/Sys/EcuM/EcuM.d ./Bsw/Sys/EcuM/EcuM.o ./Bsw/Sys/EcuM/EcuM.su

.PHONY: clean-Bsw-2f-Sys-2f-EcuM

