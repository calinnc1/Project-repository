################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Bsw/Sys/Os/Os.c \
../Bsw/Sys/Os/Os_scheduler.c \
../Bsw/Sys/Os/Os_task.c 

OBJS += \
./Bsw/Sys/Os/Os.o \
./Bsw/Sys/Os/Os_scheduler.o \
./Bsw/Sys/Os/Os_task.o 

C_DEPS += \
./Bsw/Sys/Os/Os.d \
./Bsw/Sys/Os/Os_scheduler.d \
./Bsw/Sys/Os/Os_task.d 


# Each subdirectory must supply rules for building sources it contributes
Bsw/Sys/Os/%.o Bsw/Sys/Os/%.su Bsw/Sys/Os/%.cyclo: ../Bsw/Sys/Os/%.c Bsw/Sys/Os/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -DSTM32F303xE -c -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Bsw-2f-Sys-2f-Os

clean-Bsw-2f-Sys-2f-Os:
	-$(RM) ./Bsw/Sys/Os/Os.cyclo ./Bsw/Sys/Os/Os.d ./Bsw/Sys/Os/Os.o ./Bsw/Sys/Os/Os.su ./Bsw/Sys/Os/Os_scheduler.cyclo ./Bsw/Sys/Os/Os_scheduler.d ./Bsw/Sys/Os/Os_scheduler.o ./Bsw/Sys/Os/Os_scheduler.su ./Bsw/Sys/Os/Os_task.cyclo ./Bsw/Sys/Os/Os_task.d ./Bsw/Sys/Os/Os_task.o ./Bsw/Sys/Os/Os_task.su

.PHONY: clean-Bsw-2f-Sys-2f-Os

