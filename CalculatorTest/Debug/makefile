################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include src/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: CalculatorTest

dependents:
	-cd /home/resist/Semester3/C++/Testat/cpp-testat-1/CalcLib/Debug && $(MAKE) clean all
	-cd /home/resist/Semester3/C++/Testat/cpp-testat-1/DigitsLib/Debug && $(MAKE) clean all
	-cd /home/resist/Semester3/C++/Testat/cpp-testat-1/PocketCalcLib/Debug && $(MAKE) clean all

# Tool invocations
CalculatorTest: $(OBJS) $(USER_OBJS) /home/resist/Semester3/C++/Testat/cpp-testat-1/CalcLib/Debug/libCalcLib.a /home/resist/Semester3/C++/Testat/cpp-testat-1/DigitsLib/Debug/libDigitsLib.a /home/resist/Semester3/C++/Testat/cpp-testat-1/PocketCalcLib/Debug/libPocketCalcLib.a
	@echo 'Building target: $@'
	@echo 'Invoking: GCC C++ Linker'
	g++ -L"/home/resist/Semester3/C++/Testat/cpp-testat-1/PocketCalcLib/Debug" -L"/home/resist/Semester3/C++/Testat/cpp-testat-1/DigitsLib/Debug" -L"/home/resist/Semester3/C++/Testat/cpp-testat-1/CalcLib/Debug" -o "CalculatorTest" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(CC_DEPS)$(C++_DEPS)$(EXECUTABLES)$(C_UPPER_DEPS)$(CXX_DEPS)$(OBJS)$(CPP_DEPS)$(C_DEPS) CalculatorTest
	-@echo ' '

.PHONY: all clean dependents
/home/resist/Semester3/C++/Testat/cpp-testat-1/CalcLib/Debug/libCalcLib.a:
/home/resist/Semester3/C++/Testat/cpp-testat-1/DigitsLib/Debug/libDigitsLib.a:
/home/resist/Semester3/C++/Testat/cpp-testat-1/PocketCalcLib/Debug/libPocketCalcLib.a:

-include ../makefile.targets
