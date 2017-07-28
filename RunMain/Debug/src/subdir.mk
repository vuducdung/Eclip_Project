################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Motion_Detect.cpp \
../src/RunMain.cpp \
../src/videobuffer.cpp 

OBJS += \
./src/Motion_Detect.o \
./src/RunMain.o \
./src/videobuffer.o 

CPP_DEPS += \
./src/Motion_Detect.d \
./src/RunMain.d \
./src/videobuffer.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/usr/local/include -I/usr/local/src/openalpr/openalpr/src/openalpr -I/usr/local/src/openalpr/openalpr/src/video -I/usr/local/include/opencv -I/usr/local/src/openalpr/openalpr/src -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


