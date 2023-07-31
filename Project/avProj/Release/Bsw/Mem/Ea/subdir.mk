################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Bsw/Mem/Ea/Ea.c 

OBJS += \
./Bsw/Mem/Ea/Ea.o 

C_DEPS += \
./Bsw/Mem/Ea/Ea.d 


# Each subdirectory must supply rules for building sources it contributes
Bsw/Mem/Ea/%.o Bsw/Mem/Ea/%.su Bsw/Mem/Ea/%.cyclo: ../Bsw/Mem/Ea/%.c Bsw/Mem/Ea/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -DSTM32F303xE -c -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Bsw-2f-Mem-2f-Ea

clean-Bsw-2f-Mem-2f-Ea:
	-$(RM) ./Bsw/Mem/Ea/Ea.cyclo ./Bsw/Mem/Ea/Ea.d ./Bsw/Mem/Ea/Ea.o ./Bsw/Mem/Ea/Ea.su

.PHONY: clean-Bsw-2f-Mem-2f-Ea

