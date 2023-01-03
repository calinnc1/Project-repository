################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Bsw/MCal/Adc/stm32f3xx_hal_adc.c \
../Bsw/MCal/Adc/stm32f3xx_hal_adc_ex.c 

OBJS += \
./Bsw/MCal/Adc/stm32f3xx_hal_adc.o \
./Bsw/MCal/Adc/stm32f3xx_hal_adc_ex.o 

C_DEPS += \
./Bsw/MCal/Adc/stm32f3xx_hal_adc.d \
./Bsw/MCal/Adc/stm32f3xx_hal_adc_ex.d 


# Each subdirectory must supply rules for building sources it contributes
Bsw/MCal/Adc/%.o Bsw/MCal/Adc/%.su: ../Bsw/MCal/Adc/%.c Bsw/MCal/Adc/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DSTM32F303xE -DDEBUG -DUSE_HAL_DRIVERS -c -I"C:/Work/Embedded/SVN/avProj/Bsw/MCal/Mcu" -I"C:/Work/Embedded/SVN/avProj/Bsw/MCal/Adc" -I"C:/Work/Embedded/SVN/avProj/Bsw/MCal/Fls" -I"C:/Work/Embedded/SVN/avProj/Bsw/MCal/I2c" -I"C:/Work/Embedded/SVN/avProj/Bsw/MCal/Pwr" -I"C:/Work/Embedded/SVN/avProj/Bsw/MCal/Spi" -I"C:/Work/Embedded/SVN/avProj/Bsw/MCal/Uart" -I"C:/Work/Embedded/SVN/avProj/Bsw/MCal/Dio" -I"C:/Work/Embedded/SVN/avProj/Bsw/MCal/Dma" -I"C:/Work/Embedded/SVN/avProj/Bsw/MCal/Gpt" -I"C:/Work/Embedded/SVN/avProj/Bsw/Sys/EcuM" -I"C:/Work/Embedded/SVN/avProj/Bsw/Sys/BswM" -I"C:/Work/Embedded/SVN/avProj/Config" -I"C:/Work/Embedded/SVN/avProj/Bsw/MCal/Int" -I"C:/Work/Embedded/SVN/avProj/Rte" -I"C:/Work/Embedded/SVN/avProj/Bsw/Sys/Tm" -I"C:/Work/Embedded/SVN/avProj/Bsw/Sys/Os" -I"C:/Work/Embedded/SVN/avProj/Bsw/Mem/NvM" -I"C:/Work/Embedded/SVN/avProj/Bsw/Mem/Ea" -I"C:/Work/Embedded/SVN/avProj/Bsw/Cdd/Cdd_Servo" -I"C:/Work/Embedded/SVN/avProj/Bsw/Cdd/Cdd_Ultrasonic" -I"C:/Work/Embedded/SVN/avProj/Asw/LED" -I"C:/Work/Embedded/SVN/avProj/Asw/Access" -I"C:/Work/Embedded/SVN/avProj/Asw/Engine" -I"C:/Work/Embedded/SVN/avProj/Asw/Steering" -I"C:/Work/Embedded/SVN/avProj/Asw/Brakes" -I"C:/Work/Embedded/SVN/avProj/Asw/Lights/Blinker" -I"C:/Work/Embedded/SVN/avProj/Asw/Lights/FrontLights" -I"C:/Work/Embedded/SVN/avProj/Asw/Lights/RearLights" -I"C:/Work/Embedded/SVN/avProj/Asw/Lights/InteriorLights" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Bsw-2f-MCal-2f-Adc

clean-Bsw-2f-MCal-2f-Adc:
	-$(RM) ./Bsw/MCal/Adc/stm32f3xx_hal_adc.d ./Bsw/MCal/Adc/stm32f3xx_hal_adc.o ./Bsw/MCal/Adc/stm32f3xx_hal_adc.su ./Bsw/MCal/Adc/stm32f3xx_hal_adc_ex.d ./Bsw/MCal/Adc/stm32f3xx_hal_adc_ex.o ./Bsw/MCal/Adc/stm32f3xx_hal_adc_ex.su

.PHONY: clean-Bsw-2f-MCal-2f-Adc

