################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Bsw/Mem/NvM/NvM.c 

OBJS += \
./Bsw/Mem/NvM/NvM.o 

C_DEPS += \
./Bsw/Mem/NvM/NvM.d 


# Each subdirectory must supply rules for building sources it contributes
Bsw/Mem/NvM/%.o Bsw/Mem/NvM/%.su Bsw/Mem/NvM/%.cyclo: ../Bsw/Mem/NvM/%.c Bsw/Mem/NvM/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -DSTM32F303xE -c -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Bsw-2f-Mem-2f-NvM

clean-Bsw-2f-Mem-2f-NvM:
	-$(RM) ./Bsw/Mem/NvM/NvM.cyclo ./Bsw/Mem/NvM/NvM.d ./Bsw/Mem/NvM/NvM.o ./Bsw/Mem/NvM/NvM.su

.PHONY: clean-Bsw-2f-Mem-2f-NvM

