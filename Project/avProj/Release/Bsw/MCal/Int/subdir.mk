################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Bsw/MCal/Int/Int.c 

OBJS += \
./Bsw/MCal/Int/Int.o 

C_DEPS += \
./Bsw/MCal/Int/Int.d 


# Each subdirectory must supply rules for building sources it contributes
Bsw/MCal/Int/%.o Bsw/MCal/Int/%.su Bsw/MCal/Int/%.cyclo: ../Bsw/MCal/Int/%.c Bsw/MCal/Int/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -DSTM32F303xE -c -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Bsw-2f-MCal-2f-Int

clean-Bsw-2f-MCal-2f-Int:
	-$(RM) ./Bsw/MCal/Int/Int.cyclo ./Bsw/MCal/Int/Int.d ./Bsw/MCal/Int/Int.o ./Bsw/MCal/Int/Int.su

.PHONY: clean-Bsw-2f-MCal-2f-Int

