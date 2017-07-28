################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Design_Openalr.cpp 

OBJS += \
./src/Design_Openalr.o 

CPP_DEPS += \
./src/Design_Openalr.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/usr/local/include -I/usr/local/src/openalpr/openalpr/src/openalpr -I/usr/local/src/openalpr/openalpr/src/openalpr/textdetection -I/usr/local/src/openalpr/openalpr/src/openalpr/detection -I/usr/local/include/opencv -I/usr/local/src/openalpr/openalpr -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


