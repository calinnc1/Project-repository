################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Asw/LED/LED.c 

OBJS += \
./Asw/LED/LED.o 

C_DEPS += \
./Asw/LED/LED.d 


# Each subdirectory must supply rules for building sources it contributes
Asw/LED/%.o Asw/LED/%.su: ../Asw/LED/%.c Asw/LED/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DSTM32F303xE -DDEBUG -DUSE_HAL_DRIVERS -c -I"C:/Work/Embedded/avProj/Bsw/MCal/Mcu" -I"C:/Work/Embedded/avProj/Bsw/MCal/Adc" -I"C:/Work/Embedded/avProj/Bsw/MCal/Fls" -I"C:/Work/Embedded/avProj/Bsw/MCal/I2c" -I"C:/Work/Embedded/avProj/Bsw/MCal/Pwr" -I"C:/Work/Embedded/avProj/Bsw/MCal/Spi" -I"C:/Work/Embedded/avProj/Bsw/MCal/Uart" -I"C:/Work/Embedded/avProj/Bsw/MCal/Dio" -I"C:/Work/Embedded/avProj/Bsw/MCal/Dma" -I"C:/Work/Embedded/avProj/Bsw/MCal/Gpt" -I"C:/Work/Embedded/avProj/Bsw/Sys/EcuM" -I"C:/Work/Embedded/avProj/Bsw/Sys/BswM" -I"C:/Work/Embedded/avProj/Config" -I"C:/Work/Embedded/avProj/Bsw/MCal/Int" -I"C:/Work/Embedded/avProj/Rte" -I"C:/Work/Embedded/avProj/Asw/LED" -I"C:/Work/Embedded/avProj/Bsw/Sys/Tm" -I"C:/Work/Embedded/avProj/Bsw/Sys/Os" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Asw-2f-LED

clean-Asw-2f-LED:
	-$(RM) ./Asw/LED/LED.d ./Asw/LED/LED.o ./Asw/LED/LED.su

.PHONY: clean-Asw-2f-LED
