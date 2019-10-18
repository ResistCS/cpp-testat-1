################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Test.cpp 

OBJS += \
./src/Test.o 

CPP_DEPS += \
./src/Test.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++1z -I"/home/resist/Semester3/C++/Testat/cpp-testat-1/PocketCalcLib" -I"/home/resist/Semester3/C++/Testat/cpp-testat-1/DigitsLib" -I"/home/resist/Semester3/C++/Testat/cpp-testat-1/CalcLib" -I"/home/resist/Semester3/C++/Testat/cpp-testat-1/CalculatorTest/cute" -O0 -g3 -Wall -c -fmessage-length=0 -Wno-attributes -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


