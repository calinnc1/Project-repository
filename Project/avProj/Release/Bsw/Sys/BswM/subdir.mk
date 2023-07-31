################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Bsw/Sys/BswM/BswM.c 

OBJS += \
./Bsw/Sys/BswM/BswM.o 

C_DEPS += \
./Bsw/Sys/BswM/BswM.d 


# Each subdirectory must supply rules for building sources it contributes
Bsw/Sys/BswM/%.o Bsw/Sys/BswM/%.su Bsw/Sys/BswM/%.cyclo: ../Bsw/Sys/BswM/%.c Bsw/Sys/BswM/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -DSTM32F303xE -c -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Bsw-2f-Sys-2f-BswM

clean-Bsw-2f-Sys-2f-BswM:
	-$(RM) ./Bsw/Sys/BswM/BswM.cyclo ./Bsw/Sys/BswM/BswM.d ./Bsw/Sys/BswM/BswM.o ./Bsw/Sys/BswM/BswM.su

.PHONY: clean-Bsw-2f-Sys-2f-BswM

