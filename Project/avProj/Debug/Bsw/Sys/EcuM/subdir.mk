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
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DSTM32F303xE -DDEBUG -DUSE_HAL_DRIVERS -c -I"C:/Work/Embedded/avProj/Bsw/MCal/Mcu" -I"C:/Work/Embedded/avProj/Bsw/MCal/Adc" -I"C:/Work/Embedded/avProj/Bsw/MCal/Fls" -I"C:/Work/Embedded/avProj/Bsw/MCal/I2c" -I"C:/Work/Embedded/avProj/Bsw/MCal/Pwr" -I"C:/Work/Embedded/avProj/Bsw/MCal/Spi" -I"C:/Work/Embedded/avProj/Bsw/MCal/Uart" -I"C:/Work/Embedded/avProj/Bsw/MCal/Dio" -I"C:/Work/Embedded/avProj/Bsw/MCal/Dma" -I"C:/Work/Embedded/avProj/Bsw/MCal/Gpt" -I"C:/Work/Embedded/avProj/Bsw/Sys/EcuM" -I"C:/Work/Embedded/avProj/Bsw/Sys/BswM" -I"C:/Work/Embedded/avProj/Config" -I"C:/Work/Embedded/avProj/Bsw/MCal/Int" -I"C:/Work/Embedded/avProj/Rte" -I"C:/Work/Embedded/avProj/Asw/LED" -I"C:/Work/Embedded/avProj/Bsw/Sys/Tm" -I"C:/Work/Embedded/avProj/Bsw/Sys/Os" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Bsw-2f-Sys-2f-EcuM

clean-Bsw-2f-Sys-2f-EcuM:
	-$(RM) ./Bsw/Sys/EcuM/EcuM.d ./Bsw/Sys/EcuM/EcuM.o ./Bsw/Sys/EcuM/EcuM.su

.PHONY: clean-Bsw-2f-Sys-2f-EcuM
