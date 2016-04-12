################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Ball.cpp \
../BallPlaneColDetect.cpp \
../BilliardsTable.cpp \
../DragForceGenerator.cpp \
../ForceGenerator.cpp \
../MyLoadTexture.cpp \
../Particle.cpp \
../ParticleContact.cpp \
../Plane.cpp \
../ReadJPEG.cpp \
../main.cpp \
../vector3.cpp \
../vfr.cpp 

OBJS += \
./Ball.o \
./BallPlaneColDetect.o \
./BilliardsTable.o \
./DragForceGenerator.o \
./ForceGenerator.o \
./MyLoadTexture.o \
./Particle.o \
./ParticleContact.o \
./Plane.o \
./ReadJPEG.o \
./main.o \
./vector3.o \
./vfr.o 

CPP_DEPS += \
./Ball.d \
./BallPlaneColDetect.d \
./BilliardsTable.d \
./DragForceGenerator.d \
./ForceGenerator.d \
./MyLoadTexture.d \
./Particle.d \
./ParticleContact.d \
./Plane.d \
./ReadJPEG.d \
./main.d \
./vector3.d \
./vfr.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -std=c++11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


