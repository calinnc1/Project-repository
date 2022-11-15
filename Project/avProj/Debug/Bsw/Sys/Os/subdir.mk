################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
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
Bsw/Sys/Os/%.o Bsw/Sys/Os/%.su: ../Bsw/Sys/Os/%.c Bsw/Sys/Os/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DSTM32F303xE -DDEBUG -DUSE_HAL_DRIVERS -c -I"C:/Work/Embedded/SVN/avProj/Bsw/MCal/Mcu" -I"C:/Work/Embedded/SVN/avProj/Bsw/MCal/Adc" -I"C:/Work/Embedded/SVN/avProj/Bsw/MCal/Fls" -I"C:/Work/Embedded/SVN/avProj/Bsw/MCal/I2c" -I"C:/Work/Embedded/SVN/avProj/Bsw/MCal/Pwr" -I"C:/Work/Embedded/SVN/avProj/Bsw/MCal/Spi" -I"C:/Work/Embedded/SVN/avProj/Bsw/MCal/Uart" -I"C:/Work/Embedded/SVN/avProj/Bsw/MCal/Dio" -I"C:/Work/Embedded/SVN/avProj/Bsw/MCal/Dma" -I"C:/Work/Embedded/SVN/avProj/Bsw/MCal/Gpt" -I"C:/Work/Embedded/SVN/avProj/Bsw/Sys/EcuM" -I"C:/Work/Embedded/SVN/avProj/Bsw/Sys/BswM" -I"C:/Work/Embedded/SVN/avProj/Config" -I"C:/Work/Embedded/SVN/avProj/Bsw/MCal/Int" -I"C:/Work/Embedded/SVN/avProj/Rte" -I"C:/Work/Embedded/SVN/avProj/Bsw/Sys/Tm" -I"C:/Work/Embedded/SVN/avProj/Bsw/Sys/Os" -I"C:/Work/Embedded/SVN/avProj/Bsw/Cdd/Cdd_Servo" -I"C:/Work/Embedded/SVN/avProj/Asw/LED" -I"C:/Work/Embedded/SVN/avProj/Asw/Access" -I"C:/Work/Embedded/SVN/avProj/Asw/Engine" -I"C:/Work/Embedded/SVN/avProj/Asw/Steering" -I"C:/Work/Embedded/SVN/avProj/Asw/Brakes" -I"C:/Work/Embedded/SVN/avProj/Asw/Lights/Blinker" -I"C:/Work/Embedded/SVN/avProj/Asw/Lights/FrontLights" -I"C:/Work/Embedded/SVN/avProj/Asw/Lights/RearLights" -I"C:/Work/Embedded/SVN/avProj/Asw/Lights/InteriorLights" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Bsw-2f-Sys-2f-Os

clean-Bsw-2f-Sys-2f-Os:
	-$(RM) ./Bsw/Sys/Os/Os.d ./Bsw/Sys/Os/Os.o ./Bsw/Sys/Os/Os.su ./Bsw/Sys/Os/Os_scheduler.d ./Bsw/Sys/Os/Os_scheduler.o ./Bsw/Sys/Os/Os_scheduler.su ./Bsw/Sys/Os/Os_task.d ./Bsw/Sys/Os/Os_task.o ./Bsw/Sys/Os/Os_task.su

.PHONY: clean-Bsw-2f-Sys-2f-Os

