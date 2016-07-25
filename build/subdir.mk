################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../C.cpp \
../Language.cpp \
../Lexer.cpp \
../error.cpp \
../fs.cpp \
../main.cpp 

OBJS += \
./C.o \
./Language.o \
./Lexer.o \
./error.o \
./fs.o \
./main.o 

CPP_DEPS += \
./C.d \
./Language.d \
./Lexer.d \
./error.d \
./fs.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O2 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


