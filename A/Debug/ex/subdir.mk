################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../ex/ass.cpp \
../ex/b.cpp 

OBJS += \
./ex/ass.o \
./ex/b.o 

CPP_DEPS += \
./ex/ass.d \
./ex/b.d 


# Each subdirectory must supply rules for building sources it contributes
ex/%.o: ../ex/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/usr/local/include/opencv -Iusr/local/include -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


