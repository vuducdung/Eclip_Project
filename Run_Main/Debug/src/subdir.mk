################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Run_Main.cpp 

OBJS += \
./src/Run_Main.o 

CPP_DEPS += \
./src/Run_Main.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/usr/local/include -I/usr/local/include/opencv -I/usr/local/src/openalpr/openalpr/src -I/usr/local/src/openalpr/openalpr/src/openalpr -O0 -g3 -Wall -c  ../h786poj.jpg -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


