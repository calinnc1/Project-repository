################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_SRCS += \
../Config/startup_stm32f303retx.s 

OBJS += \
./Config/startup_stm32f303retx.o 

S_DEPS += \
./Config/startup_stm32f303retx.d 


# Each subdirectory must supply rules for building sources it contributes
Config/%.o: ../Config/%.s Config/subdir.mk
	arm-none-eabi-gcc -mcpu=cortex-m4 -g3 -c -x assembler-with-cpp -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@" "$<"

clean: clean-Config

clean-Config:
	-$(RM) ./Config/startup_stm32f303retx.d ./Config/startup_stm32f303retx.o

.PHONY: clean-Config

