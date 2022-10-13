################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Bsw/MCal/Spi/stm32f3xx_hal_spi.c \
../Bsw/MCal/Spi/stm32f3xx_hal_spi_ex.c 

OBJS += \
./Bsw/MCal/Spi/stm32f3xx_hal_spi.o \
./Bsw/MCal/Spi/stm32f3xx_hal_spi_ex.o 

C_DEPS += \
./Bsw/MCal/Spi/stm32f3xx_hal_spi.d \
./Bsw/MCal/Spi/stm32f3xx_hal_spi_ex.d 


# Each subdirectory must supply rules for building sources it contributes
Bsw/MCal/Spi/%.o Bsw/MCal/Spi/%.su: ../Bsw/MCal/Spi/%.c Bsw/MCal/Spi/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DSTM32F303xE -DDEBUG -DUSE_HAL_DRIVERS -c -I"C:/Work/Embedded/avProj/Bsw/MCal/Mcu" -I"C:/Work/Embedded/avProj/Bsw/MCal/Adc" -I"C:/Work/Embedded/avProj/Bsw/MCal/Fls" -I"C:/Work/Embedded/avProj/Bsw/MCal/I2c" -I"C:/Work/Embedded/avProj/Bsw/MCal/Pwr" -I"C:/Work/Embedded/avProj/Bsw/MCal/Spi" -I"C:/Work/Embedded/avProj/Bsw/MCal/Uart" -I"C:/Work/Embedded/avProj/Bsw/MCal/Dio" -I"C:/Work/Embedded/avProj/Bsw/MCal/Dma" -I"C:/Work/Embedded/avProj/Bsw/MCal/Gpt" -I"C:/Work/Embedded/avProj/Bsw/Sys/EcuM" -I"C:/Work/Embedded/avProj/Bsw/Sys/BswM" -I"C:/Work/Embedded/avProj/Config" -I"C:/Work/Embedded/avProj/Bsw/MCal/Int" -I"C:/Work/Embedded/avProj/Rte" -I"C:/Work/Embedded/avProj/Asw/LED" -I"C:/Work/Embedded/avProj/Bsw/Sys/Tm" -I"C:/Work/Embedded/avProj/Bsw/Sys/Os" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Bsw-2f-MCal-2f-Spi

clean-Bsw-2f-MCal-2f-Spi:
	-$(RM) ./Bsw/MCal/Spi/stm32f3xx_hal_spi.d ./Bsw/MCal/Spi/stm32f3xx_hal_spi.o ./Bsw/MCal/Spi/stm32f3xx_hal_spi.su ./Bsw/MCal/Spi/stm32f3xx_hal_spi_ex.d ./Bsw/MCal/Spi/stm32f3xx_hal_spi_ex.o ./Bsw/MCal/Spi/stm32f3xx_hal_spi_ex.su

.PHONY: clean-Bsw-2f-MCal-2f-Spi

