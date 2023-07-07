################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Asw/Steering/Steering.c 

OBJS += \
./Asw/Steering/Steering.o 

C_DEPS += \
./Asw/Steering/Steering.d 


# Each subdirectory must supply rules for building sources it contributes
Asw/Steering/%.o Asw/Steering/%.su Asw/Steering/%.cyclo: ../Asw/Steering/%.c Asw/Steering/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DSTM32F303xE -DDEBUG -DUSE_HAL_DRIVERS -c -I"C:/CristianTirziu/Internship/Project-repository/Project/avProj/Bsw/MCal/Mcu" -I"C:/CristianTirziu/Internship/Project-repository/Project/avProj/Bsw/MCal/Adc" -I"C:/CristianTirziu/Internship/Project-repository/Project/avProj/Bsw/MCal/Fls" -I"C:/CristianTirziu/Internship/Project-repository/Project/avProj/Bsw/MCal/I2c" -I"C:/CristianTirziu/Internship/Project-repository/Project/avProj/Bsw/MCal/Pwr" -I"C:/CristianTirziu/Internship/Project-repository/Project/avProj/Bsw/MCal/Spi" -I"C:/CristianTirziu/Internship/Project-repository/Project/avProj/Bsw/MCal/Uart" -I"C:/CristianTirziu/Internship/Project-repository/Project/avProj/Bsw/MCal/Dio" -I"C:/CristianTirziu/Internship/Project-repository/Project/avProj/Bsw/MCal/Dma" -I"C:/CristianTirziu/Internship/Project-repository/Project/avProj/Bsw/MCal/Gpt" -I"C:/CristianTirziu/Internship/Project-repository/Project/avProj/Bsw/Sys/EcuM" -I"C:/CristianTirziu/Internship/Project-repository/Project/avProj/Bsw/Sys/BswM" -I"C:/CristianTirziu/Internship/Project-repository/Project/avProj/Config" -I"C:/CristianTirziu/Internship/Project-repository/Project/avProj/Bsw/MCal/Int" -I"C:/CristianTirziu/Internship/Project-repository/Project/avProj/Rte" -I"C:/CristianTirziu/Internship/Project-repository/Project/avProj/Bsw/Sys/Tm" -I"C:/CristianTirziu/Internship/Project-repository/Project/avProj/Bsw/Sys/Os" -I"C:/CristianTirziu/Internship/Project-repository/Project/avProj/Bsw/Mem/NvM" -I"C:/CristianTirziu/Internship/Project-repository/Project/avProj/Bsw/Mem/Ea" -I"C:/CristianTirziu/Internship/Project-repository/Project/avProj/Bsw/Cdd/Cdd_Servo" -I"C:/CristianTirziu/Internship/Project-repository/Project/avProj/Bsw/Cdd/Cdd_Ultrasonic" -I"C:/CristianTirziu/Internship/Project-repository/Project/avProj/Asw/LED" -I"C:/CristianTirziu/Internship/Project-repository/Project/avProj/Asw/Access" -I"C:/CristianTirziu/Internship/Project-repository/Project/avProj/Asw/Engine" -I"C:/CristianTirziu/Internship/Project-repository/Project/avProj/Asw/Steering" -I"C:/CristianTirziu/Internship/Project-repository/Project/avProj/Asw/Brakes" -I"C:/CristianTirziu/Internship/Project-repository/Project/avProj/Asw/Lights/Blinker" -I"C:/CristianTirziu/Internship/Project-repository/Project/avProj/Asw/Lights/FrontLights" -I"C:/CristianTirziu/Internship/Project-repository/Project/avProj/Asw/Lights/RearLights" -I"C:/CristianTirziu/Internship/Project-repository/Project/avProj/Asw/Lights/InteriorLights" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Asw-2f-Steering

clean-Asw-2f-Steering:
	-$(RM) ./Asw/Steering/Steering.cyclo ./Asw/Steering/Steering.d ./Asw/Steering/Steering.o ./Asw/Steering/Steering.su

.PHONY: clean-Asw-2f-Steering

