################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Tic\ Tac\ Toe.cpp 

OBJS += \
./src/Tic\ Tac\ Toe.o 

CPP_DEPS += \
./src/Tic\ Tac\ Toe.d 


# Each subdirectory must supply rules for building sources it contributes
src/Tic\ Tac\ Toe.o: ../src/Tic\ Tac\ Toe.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -std=c++11 -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"src/Tic Tac Toe.d" -MT"src/Tic\ Tac\ Toe.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


