################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Bsw/MCal/Fls/stm32f3xx_hal_flash.c \
../Bsw/MCal/Fls/stm32f3xx_hal_flash_ex.c 

OBJS += \
./Bsw/MCal/Fls/stm32f3xx_hal_flash.o \
./Bsw/MCal/Fls/stm32f3xx_hal_flash_ex.o 

C_DEPS += \
./Bsw/MCal/Fls/stm32f3xx_hal_flash.d \
./Bsw/MCal/Fls/stm32f3xx_hal_flash_ex.d 


# Each subdirectory must supply rules for building sources it contributes
Bsw/MCal/Fls/%.o Bsw/MCal/Fls/%.su Bsw/MCal/Fls/%.cyclo: ../Bsw/MCal/Fls/%.c Bsw/MCal/Fls/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DSTM32F303xE -DDEBUG -DUSE_HAL_DRIVERS -c -I"C:/CristianTirziu/Internship/Project-repository/Project/avProj/Bsw/MCal/Mcu" -I"C:/CristianTirziu/Internship/Project-repository/Project/avProj/Bsw/MCal/Adc" -I"C:/CristianTirziu/Internship/Project-repository/Project/avProj/Bsw/MCal/Fls" -I"C:/CristianTirziu/Internship/Project-repository/Project/avProj/Bsw/MCal/I2c" -I"C:/CristianTirziu/Internship/Project-repository/Project/avProj/Bsw/MCal/Pwr" -I"C:/CristianTirziu/Internship/Project-repository/Project/avProj/Bsw/MCal/Spi" -I"C:/CristianTirziu/Internship/Project-repository/Project/avProj/Bsw/MCal/Uart" -I"C:/CristianTirziu/Internship/Project-repository/Project/avProj/Bsw/MCal/Dio" -I"C:/CristianTirziu/Internship/Project-repository/Project/avProj/Bsw/MCal/Dma" -I"C:/CristianTirziu/Internship/Project-repository/Project/avProj/Bsw/MCal/Gpt" -I"C:/CristianTirziu/Internship/Project-repository/Project/avProj/Bsw/Sys/EcuM" -I"C:/CristianTirziu/Internship/Project-repository/Project/avProj/Bsw/Sys/BswM" -I"C:/CristianTirziu/Internship/Project-repository/Project/avProj/Config" -I"C:/CristianTirziu/Internship/Project-repository/Project/avProj/Bsw/MCal/Int" -I"C:/CristianTirziu/Internship/Project-repository/Project/avProj/Rte" -I"C:/CristianTirziu/Internship/Project-repository/Project/avProj/Bsw/Sys/Tm" -I"C:/CristianTirziu/Internship/Project-repository/Project/avProj/Bsw/Sys/Os" -I"C:/CristianTirziu/Internship/Project-repository/Project/avProj/Bsw/Mem/NvM" -I"C:/CristianTirziu/Internship/Project-repository/Project/avProj/Bsw/Mem/Ea" -I"C:/CristianTirziu/Internship/Project-repository/Project/avProj/Bsw/Cdd/Cdd_Servo" -I"C:/CristianTirziu/Internship/Project-repository/Project/avProj/Bsw/Cdd/Cdd_Ultrasonic" -I"C:/CristianTirziu/Internship/Project-repository/Project/avProj/Asw/LED" -I"C:/CristianTirziu/Internship/Project-repository/Project/avProj/Asw/Access" -I"C:/CristianTirziu/Internship/Project-repository/Project/avProj/Asw/Engine" -I"C:/CristianTirziu/Internship/Project-repository/Project/avProj/Asw/Steering" -I"C:/CristianTirziu/Internship/Project-repository/Project/avProj/Asw/Brakes" -I"C:/CristianTirziu/Internship/Project-repository/Project/avProj/Asw/Lights/Blinker" -I"C:/CristianTirziu/Internship/Project-repository/Project/avProj/Asw/Lights/FrontLights" -I"C:/CristianTirziu/Internship/Project-repository/Project/avProj/Asw/Lights/RearLights" -I"C:/CristianTirziu/Internship/Project-repository/Project/avProj/Asw/Lights/InteriorLights" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Bsw-2f-MCal-2f-Fls

clean-Bsw-2f-MCal-2f-Fls:
	-$(RM) ./Bsw/MCal/Fls/stm32f3xx_hal_flash.cyclo ./Bsw/MCal/Fls/stm32f3xx_hal_flash.d ./Bsw/MCal/Fls/stm32f3xx_hal_flash.o ./Bsw/MCal/Fls/stm32f3xx_hal_flash.su ./Bsw/MCal/Fls/stm32f3xx_hal_flash_ex.cyclo ./Bsw/MCal/Fls/stm32f3xx_hal_flash_ex.d ./Bsw/MCal/Fls/stm32f3xx_hal_flash_ex.o ./Bsw/MCal/Fls/stm32f3xx_hal_flash_ex.su

.PHONY: clean-Bsw-2f-MCal-2f-Fls

