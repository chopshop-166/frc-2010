# Wind River Workbench generated Makefile.
# Do not edit!!!
#
# The file ".wrmakefile" is the template used by the Wind River Workbench to
# generate the makefiles of this project. Add user-specific build targets and
# make rules only(!) in this project's ".wrmakefile" file. These will then be
# automatically dumped into the makefiles.

WIND_HOME := $(subst \,/,$(WIND_HOME))
WIND_BASE := $(subst \,/,$(WIND_BASE))
WIND_USR := $(subst \,/,$(WIND_USR))

all : pre_recursion subdirs_all post_recursion pre_build main_all post_build

TRACE=0
TRACEON=$(TRACE:0=@)
TRACE_FLAG=$(TRACEON:1=)

MAKEFILE := Makefile

BUILD_SPEC = PPC603gnu
DEBUG_MODE = 1
SRC_DIR := .
BUILD_ROOT_DIR := 
PRJ_ROOT_DIR := C:/WindRiver/workspace/WPILib
WS_ROOT_DIR := C:/WindRiver/workspace

ALL_BUILD_SPECS := PPC32diab PPC32gnu PPC32sfdiab PPC32sfgnu \
	 PPC403diab PPC403gnu PPC405diab PPC405gnu \
	 PPC405sfdiab PPC405sfgnu PPC440diab PPC440gnu \
	 PPC440sfdiab PPC440sfgnu PPC603diab PPC603gnu \
	 PPC604diab PPC604gnu PPC85XXdiab PPC85XXgnu \
	 PPC85XXsfdiab PPC85XXsfgnu PPC860sfdiab PPC860sfgnu \
	 SIMLINUXdiab SIMLINUXgnu SIMNTdiab SIMNTgnu \
	 SIMSPARCSOLARISdiab SIMSPARCSOLARISgnu
ENABLED_BUILD_SPECS := PPC603gnu

ifeq ($(BUILD_SPEC),PPC32diab)
ifeq ($(DEBUG_MODE),1)
OBJ_DIR := PPC32diab_DEBUG
else
OBJ_DIR := PPC32diab
endif
endif
ifeq ($(BUILD_SPEC),PPC32gnu)
ifeq ($(DEBUG_MODE),1)
OBJ_DIR := PPC32gnu_DEBUG
else
OBJ_DIR := PPC32gnu
endif
endif
ifeq ($(BUILD_SPEC),PPC32sfdiab)
ifeq ($(DEBUG_MODE),1)
OBJ_DIR := PPC32sfdiab_DEBUG
else
OBJ_DIR := PPC32sfdiab
endif
endif
ifeq ($(BUILD_SPEC),PPC32sfgnu)
ifeq ($(DEBUG_MODE),1)
OBJ_DIR := PPC32sfgnu_DEBUG
else
OBJ_DIR := PPC32sfgnu
endif
endif
ifeq ($(BUILD_SPEC),PPC403diab)
ifeq ($(DEBUG_MODE),1)
OBJ_DIR := PPC403diab_DEBUG
else
OBJ_DIR := PPC403diab
endif
endif
ifeq ($(BUILD_SPEC),PPC403gnu)
ifeq ($(DEBUG_MODE),1)
OBJ_DIR := PPC403gnu_DEBUG
else
OBJ_DIR := PPC403gnu
endif
endif
ifeq ($(BUILD_SPEC),PPC405diab)
ifeq ($(DEBUG_MODE),1)
OBJ_DIR := PPC405diab_DEBUG
else
OBJ_DIR := PPC405diab
endif
endif
ifeq ($(BUILD_SPEC),PPC405gnu)
ifeq ($(DEBUG_MODE),1)
OBJ_DIR := PPC405gnu_DEBUG
else
OBJ_DIR := PPC405gnu
endif
endif
ifeq ($(BUILD_SPEC),PPC405sfdiab)
ifeq ($(DEBUG_MODE),1)
OBJ_DIR := PPC405sfdiab_DEBUG
else
OBJ_DIR := PPC405sfdiab
endif
endif
ifeq ($(BUILD_SPEC),PPC405sfgnu)
ifeq ($(DEBUG_MODE),1)
OBJ_DIR := PPC405sfgnu_DEBUG
else
OBJ_DIR := PPC405sfgnu
endif
endif
ifeq ($(BUILD_SPEC),PPC440diab)
ifeq ($(DEBUG_MODE),1)
OBJ_DIR := PPC440diab_DEBUG
else
OBJ_DIR := PPC440diab
endif
endif
ifeq ($(BUILD_SPEC),PPC440gnu)
ifeq ($(DEBUG_MODE),1)
OBJ_DIR := PPC440gnu_DEBUG
else
OBJ_DIR := PPC440gnu
endif
endif
ifeq ($(BUILD_SPEC),PPC440sfdiab)
ifeq ($(DEBUG_MODE),1)
OBJ_DIR := PPC440sfdiab_DEBUG
else
OBJ_DIR := PPC440sfdiab
endif
endif
ifeq ($(BUILD_SPEC),PPC440sfgnu)
ifeq ($(DEBUG_MODE),1)
OBJ_DIR := PPC440sfgnu_DEBUG
else
OBJ_DIR := PPC440sfgnu
endif
endif
ifeq ($(BUILD_SPEC),PPC603diab)
ifeq ($(DEBUG_MODE),1)
OBJ_DIR := PPC603diab_DEBUG
else
OBJ_DIR := PPC603diab
endif
endif
ifeq ($(BUILD_SPEC),PPC603gnu)
ifeq ($(DEBUG_MODE),1)
OBJ_DIR := PPC603gnu_DEBUG
else
OBJ_DIR := PPC603gnu
endif
endif
ifeq ($(BUILD_SPEC),PPC604diab)
ifeq ($(DEBUG_MODE),1)
OBJ_DIR := PPC604diab_DEBUG
else
OBJ_DIR := PPC604diab
endif
endif
ifeq ($(BUILD_SPEC),PPC604gnu)
ifeq ($(DEBUG_MODE),1)
OBJ_DIR := PPC604gnu_DEBUG
else
OBJ_DIR := PPC604gnu
endif
endif
ifeq ($(BUILD_SPEC),PPC85XXdiab)
ifeq ($(DEBUG_MODE),1)
OBJ_DIR := PPC85XXdiab_DEBUG
else
OBJ_DIR := PPC85XXdiab
endif
endif
ifeq ($(BUILD_SPEC),PPC85XXgnu)
ifeq ($(DEBUG_MODE),1)
OBJ_DIR := PPC85XXgnu_DEBUG
else
OBJ_DIR := PPC85XXgnu
endif
endif
ifeq ($(BUILD_SPEC),PPC85XXsfdiab)
ifeq ($(DEBUG_MODE),1)
OBJ_DIR := PPC85XXsfdiab_DEBUG
else
OBJ_DIR := PPC85XXsfdiab
endif
endif
ifeq ($(BUILD_SPEC),PPC85XXsfgnu)
ifeq ($(DEBUG_MODE),1)
OBJ_DIR := PPC85XXsfgnu_DEBUG
else
OBJ_DIR := PPC85XXsfgnu
endif
endif
ifeq ($(BUILD_SPEC),PPC860sfdiab)
ifeq ($(DEBUG_MODE),1)
OBJ_DIR := PPC860sfdiab_DEBUG
else
OBJ_DIR := PPC860sfdiab
endif
endif
ifeq ($(BUILD_SPEC),PPC860sfgnu)
ifeq ($(DEBUG_MODE),1)
OBJ_DIR := PPC860sfgnu_DEBUG
else
OBJ_DIR := PPC860sfgnu
endif
endif
ifeq ($(BUILD_SPEC),SIMLINUXdiab)
ifeq ($(DEBUG_MODE),1)
OBJ_DIR := SIMLINUXdiab_DEBUG
else
OBJ_DIR := SIMLINUXdiab
endif
endif
ifeq ($(BUILD_SPEC),SIMLINUXgnu)
ifeq ($(DEBUG_MODE),1)
OBJ_DIR := SIMLINUXgnu_DEBUG
else
OBJ_DIR := SIMLINUXgnu
endif
endif
ifeq ($(BUILD_SPEC),SIMNTdiab)
ifeq ($(DEBUG_MODE),1)
OBJ_DIR := SIMNTdiab_DEBUG
else
OBJ_DIR := SIMNTdiab
endif
endif
ifeq ($(BUILD_SPEC),SIMNTgnu)
ifeq ($(DEBUG_MODE),1)
OBJ_DIR := SIMNTgnu_DEBUG
else
OBJ_DIR := SIMNTgnu
endif
endif
ifeq ($(BUILD_SPEC),SIMSPARCSOLARISdiab)
ifeq ($(DEBUG_MODE),1)
OBJ_DIR := SIMSPARCSOLARISdiab_DEBUG
else
OBJ_DIR := SIMSPARCSOLARISdiab
endif
endif
ifeq ($(BUILD_SPEC),SIMSPARCSOLARISgnu)
ifeq ($(DEBUG_MODE),1)
OBJ_DIR := SIMSPARCSOLARISgnu_DEBUG
else
OBJ_DIR := SIMSPARCSOLARISgnu
endif
endif

DEP_FILES := $(OBJ_DIR)/PCVideoServer.d $(OBJ_DIR)/Gyro.d $(OBJ_DIR)/Timer.d \
	 $(OBJ_DIR)/DigitalInput.d $(OBJ_DIR)/Utility.d $(OBJ_DIR)/Jaguar.d \
	 $(OBJ_DIR)/Relay.d $(OBJ_DIR)/Compressor.d $(OBJ_DIR)/AnalogChannel.d \
	 $(OBJ_DIR)/Task.d $(OBJ_DIR)/HiTechnicCompass.d $(OBJ_DIR)/AnalogModule.d \
	 $(OBJ_DIR)/SerialPort.d $(OBJ_DIR)/Error.d $(OBJ_DIR)/FrcError.d \
	 $(OBJ_DIR)/ErrorBase.d $(OBJ_DIR)/Ultrasonic.d $(OBJ_DIR)/AnalogTriggerOutput.d \
	 $(OBJ_DIR)/AnalogTrigger.d $(OBJ_DIR)/AxisCamera.d $(OBJ_DIR)/Watchdog.d \
	 $(OBJ_DIR)/Solenoid.d $(OBJ_DIR)/PIDController.d $(OBJ_DIR)/Dashboard.d \
	 $(OBJ_DIR)/Counter.d $(OBJ_DIR)/SimpleRobot.d $(OBJ_DIR)/Accelerometer.d \
	 $(OBJ_DIR)/DigitalOutput.d $(OBJ_DIR)/BaeUtilities.d $(OBJ_DIR)/PWM.d \
	 $(OBJ_DIR)/Encoder.d $(OBJ_DIR)/VisionAPI.d $(OBJ_DIR)/DriverStation.d \
	 $(OBJ_DIR)/Module.d $(OBJ_DIR)/RobotDrive.d $(OBJ_DIR)/TrackAPI.d \
	 $(OBJ_DIR)/IterativeRobot.d $(OBJ_DIR)/I2C.d $(OBJ_DIR)/DigitalModule.d \
	 $(OBJ_DIR)/Notifier.d $(OBJ_DIR)/InterruptableSensorBase.d $(OBJ_DIR)/Resource.d \
	 $(OBJ_DIR)/Synchronized.d $(OBJ_DIR)/Joystick.d $(OBJ_DIR)/Victor.d \
	 $(OBJ_DIR)/RobotBase.d $(OBJ_DIR)/GearTooth.d $(OBJ_DIR)/DigitalSource.d \
	 $(OBJ_DIR)/Servo.d $(OBJ_DIR)/SensorBase.d
-include $(DEP_FILES)

ifeq ($(BUILD_SPEC),PPC32diab)
SUBDIRS :=
OBJECTS := $(OBJ_DIR)/PCVideoServer.o $(OBJ_DIR)/Gyro.o $(OBJ_DIR)/Timer.o \
	 $(OBJ_DIR)/DigitalInput.o $(OBJ_DIR)/Utility.o $(OBJ_DIR)/Jaguar.o \
	 $(OBJ_DIR)/Relay.o $(OBJ_DIR)/Compressor.o $(OBJ_DIR)/AnalogChannel.o \
	 $(OBJ_DIR)/Task.o $(OBJ_DIR)/HiTechnicCompass.o $(OBJ_DIR)/AnalogModule.o \
	 $(OBJ_DIR)/SerialPort.o $(OBJ_DIR)/Error.o $(OBJ_DIR)/FrcError.o \
	 $(OBJ_DIR)/ErrorBase.o $(OBJ_DIR)/Ultrasonic.o $(OBJ_DIR)/AnalogTriggerOutput.o \
	 $(OBJ_DIR)/AnalogTrigger.o $(OBJ_DIR)/AxisCamera.o $(OBJ_DIR)/Watchdog.o \
	 $(OBJ_DIR)/Solenoid.o $(OBJ_DIR)/PIDController.o $(OBJ_DIR)/Dashboard.o \
	 $(OBJ_DIR)/Counter.o $(OBJ_DIR)/SimpleRobot.o $(OBJ_DIR)/Accelerometer.o \
	 $(OBJ_DIR)/DigitalOutput.o $(OBJ_DIR)/BaeUtilities.o $(OBJ_DIR)/PWM.o \
	 $(OBJ_DIR)/Encoder.o $(OBJ_DIR)/VisionAPI.o $(OBJ_DIR)/DriverStation.o \
	 $(OBJ_DIR)/Module.o $(OBJ_DIR)/RobotDrive.o $(OBJ_DIR)/TrackAPI.o \
	 $(OBJ_DIR)/IterativeRobot.o $(OBJ_DIR)/I2C.o $(OBJ_DIR)/DigitalModule.o \
	 $(OBJ_DIR)/Notifier.o $(OBJ_DIR)/InterruptableSensorBase.o $(OBJ_DIR)/Resource.o \
	 $(OBJ_DIR)/Synchronized.o $(OBJ_DIR)/Joystick.o $(OBJ_DIR)/Victor.o \
	 $(OBJ_DIR)/RobotBase.o $(OBJ_DIR)/GearTooth.o $(OBJ_DIR)/DigitalSource.o \
	 $(OBJ_DIR)/Servo.o $(OBJ_DIR)/SensorBase.o

PROJECT_TARGETS := $(OBJ_DIR)/WPILib.a

SUB_OBJECTS :=
SUB_TARGETS :=
endif
ifeq ($(BUILD_SPEC),PPC32gnu)
SUBDIRS :=
OBJECTS := $(OBJ_DIR)/PCVideoServer.o $(OBJ_DIR)/Gyro.o $(OBJ_DIR)/Timer.o \
	 $(OBJ_DIR)/DigitalInput.o $(OBJ_DIR)/Utility.o $(OBJ_DIR)/Jaguar.o \
	 $(OBJ_DIR)/Relay.o $(OBJ_DIR)/Compressor.o $(OBJ_DIR)/AnalogChannel.o \
	 $(OBJ_DIR)/Task.o $(OBJ_DIR)/HiTechnicCompass.o $(OBJ_DIR)/AnalogModule.o \
	 $(OBJ_DIR)/SerialPort.o $(OBJ_DIR)/Error.o $(OBJ_DIR)/FrcError.o \
	 $(OBJ_DIR)/ErrorBase.o $(OBJ_DIR)/Ultrasonic.o $(OBJ_DIR)/AnalogTriggerOutput.o \
	 $(OBJ_DIR)/AnalogTrigger.o $(OBJ_DIR)/AxisCamera.o $(OBJ_DIR)/Watchdog.o \
	 $(OBJ_DIR)/Solenoid.o $(OBJ_DIR)/PIDController.o $(OBJ_DIR)/Dashboard.o \
	 $(OBJ_DIR)/Counter.o $(OBJ_DIR)/SimpleRobot.o $(OBJ_DIR)/Accelerometer.o \
	 $(OBJ_DIR)/DigitalOutput.o $(OBJ_DIR)/BaeUtilities.o $(OBJ_DIR)/PWM.o \
	 $(OBJ_DIR)/Encoder.o $(OBJ_DIR)/VisionAPI.o $(OBJ_DIR)/DriverStation.o \
	 $(OBJ_DIR)/Module.o $(OBJ_DIR)/RobotDrive.o $(OBJ_DIR)/TrackAPI.o \
	 $(OBJ_DIR)/IterativeRobot.o $(OBJ_DIR)/I2C.o $(OBJ_DIR)/DigitalModule.o \
	 $(OBJ_DIR)/Notifier.o $(OBJ_DIR)/InterruptableSensorBase.o $(OBJ_DIR)/Resource.o \
	 $(OBJ_DIR)/Synchronized.o $(OBJ_DIR)/Joystick.o $(OBJ_DIR)/Victor.o \
	 $(OBJ_DIR)/RobotBase.o $(OBJ_DIR)/GearTooth.o $(OBJ_DIR)/DigitalSource.o \
	 $(OBJ_DIR)/Servo.o $(OBJ_DIR)/SensorBase.o

PROJECT_TARGETS := $(OBJ_DIR)/WPILib.a

SUB_OBJECTS :=
SUB_TARGETS :=
endif
ifeq ($(BUILD_SPEC),PPC32sfdiab)
SUBDIRS :=
OBJECTS := $(OBJ_DIR)/PCVideoServer.o $(OBJ_DIR)/Gyro.o $(OBJ_DIR)/Timer.o \
	 $(OBJ_DIR)/DigitalInput.o $(OBJ_DIR)/Utility.o $(OBJ_DIR)/Jaguar.o \
	 $(OBJ_DIR)/Relay.o $(OBJ_DIR)/Compressor.o $(OBJ_DIR)/AnalogChannel.o \
	 $(OBJ_DIR)/Task.o $(OBJ_DIR)/HiTechnicCompass.o $(OBJ_DIR)/AnalogModule.o \
	 $(OBJ_DIR)/SerialPort.o $(OBJ_DIR)/Error.o $(OBJ_DIR)/FrcError.o \
	 $(OBJ_DIR)/ErrorBase.o $(OBJ_DIR)/Ultrasonic.o $(OBJ_DIR)/AnalogTriggerOutput.o \
	 $(OBJ_DIR)/AnalogTrigger.o $(OBJ_DIR)/AxisCamera.o $(OBJ_DIR)/Watchdog.o \
	 $(OBJ_DIR)/Solenoid.o $(OBJ_DIR)/PIDController.o $(OBJ_DIR)/Dashboard.o \
	 $(OBJ_DIR)/Counter.o $(OBJ_DIR)/SimpleRobot.o $(OBJ_DIR)/Accelerometer.o \
	 $(OBJ_DIR)/DigitalOutput.o $(OBJ_DIR)/BaeUtilities.o $(OBJ_DIR)/PWM.o \
	 $(OBJ_DIR)/Encoder.o $(OBJ_DIR)/VisionAPI.o $(OBJ_DIR)/DriverStation.o \
	 $(OBJ_DIR)/Module.o $(OBJ_DIR)/RobotDrive.o $(OBJ_DIR)/TrackAPI.o \
	 $(OBJ_DIR)/IterativeRobot.o $(OBJ_DIR)/I2C.o $(OBJ_DIR)/DigitalModule.o \
	 $(OBJ_DIR)/Notifier.o $(OBJ_DIR)/InterruptableSensorBase.o $(OBJ_DIR)/Resource.o \
	 $(OBJ_DIR)/Synchronized.o $(OBJ_DIR)/Joystick.o $(OBJ_DIR)/Victor.o \
	 $(OBJ_DIR)/RobotBase.o $(OBJ_DIR)/GearTooth.o $(OBJ_DIR)/DigitalSource.o \
	 $(OBJ_DIR)/Servo.o $(OBJ_DIR)/SensorBase.o

PROJECT_TARGETS := $(OBJ_DIR)/WPILib.a

SUB_OBJECTS :=
SUB_TARGETS :=
endif
ifeq ($(BUILD_SPEC),PPC32sfgnu)
SUBDIRS :=
OBJECTS := $(OBJ_DIR)/PCVideoServer.o $(OBJ_DIR)/Gyro.o $(OBJ_DIR)/Timer.o \
	 $(OBJ_DIR)/DigitalInput.o $(OBJ_DIR)/Utility.o $(OBJ_DIR)/Jaguar.o \
	 $(OBJ_DIR)/Relay.o $(OBJ_DIR)/Compressor.o $(OBJ_DIR)/AnalogChannel.o \
	 $(OBJ_DIR)/Task.o $(OBJ_DIR)/HiTechnicCompass.o $(OBJ_DIR)/AnalogModule.o \
	 $(OBJ_DIR)/SerialPort.o $(OBJ_DIR)/Error.o $(OBJ_DIR)/FrcError.o \
	 $(OBJ_DIR)/ErrorBase.o $(OBJ_DIR)/Ultrasonic.o $(OBJ_DIR)/AnalogTriggerOutput.o \
	 $(OBJ_DIR)/AnalogTrigger.o $(OBJ_DIR)/AxisCamera.o $(OBJ_DIR)/Watchdog.o \
	 $(OBJ_DIR)/Solenoid.o $(OBJ_DIR)/PIDController.o $(OBJ_DIR)/Dashboard.o \
	 $(OBJ_DIR)/Counter.o $(OBJ_DIR)/SimpleRobot.o $(OBJ_DIR)/Accelerometer.o \
	 $(OBJ_DIR)/DigitalOutput.o $(OBJ_DIR)/BaeUtilities.o $(OBJ_DIR)/PWM.o \
	 $(OBJ_DIR)/Encoder.o $(OBJ_DIR)/VisionAPI.o $(OBJ_DIR)/DriverStation.o \
	 $(OBJ_DIR)/Module.o $(OBJ_DIR)/RobotDrive.o $(OBJ_DIR)/TrackAPI.o \
	 $(OBJ_DIR)/IterativeRobot.o $(OBJ_DIR)/I2C.o $(OBJ_DIR)/DigitalModule.o \
	 $(OBJ_DIR)/Notifier.o $(OBJ_DIR)/InterruptableSensorBase.o $(OBJ_DIR)/Resource.o \
	 $(OBJ_DIR)/Synchronized.o $(OBJ_DIR)/Joystick.o $(OBJ_DIR)/Victor.o \
	 $(OBJ_DIR)/RobotBase.o $(OBJ_DIR)/GearTooth.o $(OBJ_DIR)/DigitalSource.o \
	 $(OBJ_DIR)/Servo.o $(OBJ_DIR)/SensorBase.o

PROJECT_TARGETS := $(OBJ_DIR)/WPILib.a

SUB_OBJECTS :=
SUB_TARGETS :=
endif
ifeq ($(BUILD_SPEC),PPC403diab)
SUBDIRS :=
OBJECTS := $(OBJ_DIR)/PCVideoServer.o $(OBJ_DIR)/Gyro.o $(OBJ_DIR)/Timer.o \
	 $(OBJ_DIR)/DigitalInput.o $(OBJ_DIR)/Utility.o $(OBJ_DIR)/Jaguar.o \
	 $(OBJ_DIR)/Relay.o $(OBJ_DIR)/Compressor.o $(OBJ_DIR)/AnalogChannel.o \
	 $(OBJ_DIR)/Task.o $(OBJ_DIR)/HiTechnicCompass.o $(OBJ_DIR)/AnalogModule.o \
	 $(OBJ_DIR)/SerialPort.o $(OBJ_DIR)/Error.o $(OBJ_DIR)/FrcError.o \
	 $(OBJ_DIR)/ErrorBase.o $(OBJ_DIR)/Ultrasonic.o $(OBJ_DIR)/AnalogTriggerOutput.o \
	 $(OBJ_DIR)/AnalogTrigger.o $(OBJ_DIR)/AxisCamera.o $(OBJ_DIR)/Watchdog.o \
	 $(OBJ_DIR)/Solenoid.o $(OBJ_DIR)/PIDController.o $(OBJ_DIR)/Dashboard.o \
	 $(OBJ_DIR)/Counter.o $(OBJ_DIR)/SimpleRobot.o $(OBJ_DIR)/Accelerometer.o \
	 $(OBJ_DIR)/DigitalOutput.o $(OBJ_DIR)/BaeUtilities.o $(OBJ_DIR)/PWM.o \
	 $(OBJ_DIR)/Encoder.o $(OBJ_DIR)/VisionAPI.o $(OBJ_DIR)/DriverStation.o \
	 $(OBJ_DIR)/Module.o $(OBJ_DIR)/RobotDrive.o $(OBJ_DIR)/TrackAPI.o \
	 $(OBJ_DIR)/IterativeRobot.o $(OBJ_DIR)/I2C.o $(OBJ_DIR)/DigitalModule.o \
	 $(OBJ_DIR)/Notifier.o $(OBJ_DIR)/InterruptableSensorBase.o $(OBJ_DIR)/Resource.o \
	 $(OBJ_DIR)/Synchronized.o $(OBJ_DIR)/Joystick.o $(OBJ_DIR)/Victor.o \
	 $(OBJ_DIR)/RobotBase.o $(OBJ_DIR)/GearTooth.o $(OBJ_DIR)/DigitalSource.o \
	 $(OBJ_DIR)/Servo.o $(OBJ_DIR)/SensorBase.o

PROJECT_TARGETS := $(OBJ_DIR)/WPILib.a

SUB_OBJECTS :=
SUB_TARGETS :=
endif
ifeq ($(BUILD_SPEC),PPC403gnu)
SUBDIRS :=
OBJECTS := $(OBJ_DIR)/PCVideoServer.o $(OBJ_DIR)/Gyro.o $(OBJ_DIR)/Timer.o \
	 $(OBJ_DIR)/DigitalInput.o $(OBJ_DIR)/Utility.o $(OBJ_DIR)/Jaguar.o \
	 $(OBJ_DIR)/Relay.o $(OBJ_DIR)/Compressor.o $(OBJ_DIR)/AnalogChannel.o \
	 $(OBJ_DIR)/Task.o $(OBJ_DIR)/HiTechnicCompass.o $(OBJ_DIR)/AnalogModule.o \
	 $(OBJ_DIR)/SerialPort.o $(OBJ_DIR)/Error.o $(OBJ_DIR)/FrcError.o \
	 $(OBJ_DIR)/ErrorBase.o $(OBJ_DIR)/Ultrasonic.o $(OBJ_DIR)/AnalogTriggerOutput.o \
	 $(OBJ_DIR)/AnalogTrigger.o $(OBJ_DIR)/AxisCamera.o $(OBJ_DIR)/Watchdog.o \
	 $(OBJ_DIR)/Solenoid.o $(OBJ_DIR)/PIDController.o $(OBJ_DIR)/Dashboard.o \
	 $(OBJ_DIR)/Counter.o $(OBJ_DIR)/SimpleRobot.o $(OBJ_DIR)/Accelerometer.o \
	 $(OBJ_DIR)/DigitalOutput.o $(OBJ_DIR)/BaeUtilities.o $(OBJ_DIR)/PWM.o \
	 $(OBJ_DIR)/Encoder.o $(OBJ_DIR)/VisionAPI.o $(OBJ_DIR)/DriverStation.o \
	 $(OBJ_DIR)/Module.o $(OBJ_DIR)/RobotDrive.o $(OBJ_DIR)/TrackAPI.o \
	 $(OBJ_DIR)/IterativeRobot.o $(OBJ_DIR)/I2C.o $(OBJ_DIR)/DigitalModule.o \
	 $(OBJ_DIR)/Notifier.o $(OBJ_DIR)/InterruptableSensorBase.o $(OBJ_DIR)/Resource.o \
	 $(OBJ_DIR)/Synchronized.o $(OBJ_DIR)/Joystick.o $(OBJ_DIR)/Victor.o \
	 $(OBJ_DIR)/RobotBase.o $(OBJ_DIR)/GearTooth.o $(OBJ_DIR)/DigitalSource.o \
	 $(OBJ_DIR)/Servo.o $(OBJ_DIR)/SensorBase.o

PROJECT_TARGETS := $(OBJ_DIR)/WPILib.a

SUB_OBJECTS :=
SUB_TARGETS :=
endif
ifeq ($(BUILD_SPEC),PPC405diab)
SUBDIRS :=
OBJECTS := $(OBJ_DIR)/PCVideoServer.o $(OBJ_DIR)/Gyro.o $(OBJ_DIR)/Timer.o \
	 $(OBJ_DIR)/DigitalInput.o $(OBJ_DIR)/Utility.o $(OBJ_DIR)/Jaguar.o \
	 $(OBJ_DIR)/Relay.o $(OBJ_DIR)/Compressor.o $(OBJ_DIR)/AnalogChannel.o \
	 $(OBJ_DIR)/Task.o $(OBJ_DIR)/HiTechnicCompass.o $(OBJ_DIR)/AnalogModule.o \
	 $(OBJ_DIR)/SerialPort.o $(OBJ_DIR)/Error.o $(OBJ_DIR)/FrcError.o \
	 $(OBJ_DIR)/ErrorBase.o $(OBJ_DIR)/Ultrasonic.o $(OBJ_DIR)/AnalogTriggerOutput.o \
	 $(OBJ_DIR)/AnalogTrigger.o $(OBJ_DIR)/AxisCamera.o $(OBJ_DIR)/Watchdog.o \
	 $(OBJ_DIR)/Solenoid.o $(OBJ_DIR)/PIDController.o $(OBJ_DIR)/Dashboard.o \
	 $(OBJ_DIR)/Counter.o $(OBJ_DIR)/SimpleRobot.o $(OBJ_DIR)/Accelerometer.o \
	 $(OBJ_DIR)/DigitalOutput.o $(OBJ_DIR)/BaeUtilities.o $(OBJ_DIR)/PWM.o \
	 $(OBJ_DIR)/Encoder.o $(OBJ_DIR)/VisionAPI.o $(OBJ_DIR)/DriverStation.o \
	 $(OBJ_DIR)/Module.o $(OBJ_DIR)/RobotDrive.o $(OBJ_DIR)/TrackAPI.o \
	 $(OBJ_DIR)/IterativeRobot.o $(OBJ_DIR)/I2C.o $(OBJ_DIR)/DigitalModule.o \
	 $(OBJ_DIR)/Notifier.o $(OBJ_DIR)/InterruptableSensorBase.o $(OBJ_DIR)/Resource.o \
	 $(OBJ_DIR)/Synchronized.o $(OBJ_DIR)/Joystick.o $(OBJ_DIR)/Victor.o \
	 $(OBJ_DIR)/RobotBase.o $(OBJ_DIR)/GearTooth.o $(OBJ_DIR)/DigitalSource.o \
	 $(OBJ_DIR)/Servo.o $(OBJ_DIR)/SensorBase.o

PROJECT_TARGETS := $(OBJ_DIR)/WPILib.a

SUB_OBJECTS :=
SUB_TARGETS :=
endif
ifeq ($(BUILD_SPEC),PPC405gnu)
SUBDIRS :=
OBJECTS := $(OBJ_DIR)/PCVideoServer.o $(OBJ_DIR)/Gyro.o $(OBJ_DIR)/Timer.o \
	 $(OBJ_DIR)/DigitalInput.o $(OBJ_DIR)/Utility.o $(OBJ_DIR)/Jaguar.o \
	 $(OBJ_DIR)/Relay.o $(OBJ_DIR)/Compressor.o $(OBJ_DIR)/AnalogChannel.o \
	 $(OBJ_DIR)/Task.o $(OBJ_DIR)/HiTechnicCompass.o $(OBJ_DIR)/AnalogModule.o \
	 $(OBJ_DIR)/SerialPort.o $(OBJ_DIR)/Error.o $(OBJ_DIR)/FrcError.o \
	 $(OBJ_DIR)/ErrorBase.o $(OBJ_DIR)/Ultrasonic.o $(OBJ_DIR)/AnalogTriggerOutput.o \
	 $(OBJ_DIR)/AnalogTrigger.o $(OBJ_DIR)/AxisCamera.o $(OBJ_DIR)/Watchdog.o \
	 $(OBJ_DIR)/Solenoid.o $(OBJ_DIR)/PIDController.o $(OBJ_DIR)/Dashboard.o \
	 $(OBJ_DIR)/Counter.o $(OBJ_DIR)/SimpleRobot.o $(OBJ_DIR)/Accelerometer.o \
	 $(OBJ_DIR)/DigitalOutput.o $(OBJ_DIR)/BaeUtilities.o $(OBJ_DIR)/PWM.o \
	 $(OBJ_DIR)/Encoder.o $(OBJ_DIR)/VisionAPI.o $(OBJ_DIR)/DriverStation.o \
	 $(OBJ_DIR)/Module.o $(OBJ_DIR)/RobotDrive.o $(OBJ_DIR)/TrackAPI.o \
	 $(OBJ_DIR)/IterativeRobot.o $(OBJ_DIR)/I2C.o $(OBJ_DIR)/DigitalModule.o \
	 $(OBJ_DIR)/Notifier.o $(OBJ_DIR)/InterruptableSensorBase.o $(OBJ_DIR)/Resource.o \
	 $(OBJ_DIR)/Synchronized.o $(OBJ_DIR)/Joystick.o $(OBJ_DIR)/Victor.o \
	 $(OBJ_DIR)/RobotBase.o $(OBJ_DIR)/GearTooth.o $(OBJ_DIR)/DigitalSource.o \
	 $(OBJ_DIR)/Servo.o $(OBJ_DIR)/SensorBase.o

PROJECT_TARGETS := $(OBJ_DIR)/WPILib.a

SUB_OBJECTS :=
SUB_TARGETS :=
endif
ifeq ($(BUILD_SPEC),PPC405sfdiab)
SUBDIRS :=
OBJECTS := $(OBJ_DIR)/PCVideoServer.o $(OBJ_DIR)/Gyro.o $(OBJ_DIR)/Timer.o \
	 $(OBJ_DIR)/DigitalInput.o $(OBJ_DIR)/Utility.o $(OBJ_DIR)/Jaguar.o \
	 $(OBJ_DIR)/Relay.o $(OBJ_DIR)/Compressor.o $(OBJ_DIR)/AnalogChannel.o \
	 $(OBJ_DIR)/Task.o $(OBJ_DIR)/HiTechnicCompass.o $(OBJ_DIR)/AnalogModule.o \
	 $(OBJ_DIR)/SerialPort.o $(OBJ_DIR)/Error.o $(OBJ_DIR)/FrcError.o \
	 $(OBJ_DIR)/ErrorBase.o $(OBJ_DIR)/Ultrasonic.o $(OBJ_DIR)/AnalogTriggerOutput.o \
	 $(OBJ_DIR)/AnalogTrigger.o $(OBJ_DIR)/AxisCamera.o $(OBJ_DIR)/Watchdog.o \
	 $(OBJ_DIR)/Solenoid.o $(OBJ_DIR)/PIDController.o $(OBJ_DIR)/Dashboard.o \
	 $(OBJ_DIR)/Counter.o $(OBJ_DIR)/SimpleRobot.o $(OBJ_DIR)/Accelerometer.o \
	 $(OBJ_DIR)/DigitalOutput.o $(OBJ_DIR)/BaeUtilities.o $(OBJ_DIR)/PWM.o \
	 $(OBJ_DIR)/Encoder.o $(OBJ_DIR)/VisionAPI.o $(OBJ_DIR)/DriverStation.o \
	 $(OBJ_DIR)/Module.o $(OBJ_DIR)/RobotDrive.o $(OBJ_DIR)/TrackAPI.o \
	 $(OBJ_DIR)/IterativeRobot.o $(OBJ_DIR)/I2C.o $(OBJ_DIR)/DigitalModule.o \
	 $(OBJ_DIR)/Notifier.o $(OBJ_DIR)/InterruptableSensorBase.o $(OBJ_DIR)/Resource.o \
	 $(OBJ_DIR)/Synchronized.o $(OBJ_DIR)/Joystick.o $(OBJ_DIR)/Victor.o \
	 $(OBJ_DIR)/RobotBase.o $(OBJ_DIR)/GearTooth.o $(OBJ_DIR)/DigitalSource.o \
	 $(OBJ_DIR)/Servo.o $(OBJ_DIR)/SensorBase.o

PROJECT_TARGETS := $(OBJ_DIR)/WPILib.a

SUB_OBJECTS :=
SUB_TARGETS :=
endif
ifeq ($(BUILD_SPEC),PPC405sfgnu)
SUBDIRS :=
OBJECTS := $(OBJ_DIR)/PCVideoServer.o $(OBJ_DIR)/Gyro.o $(OBJ_DIR)/Timer.o \
	 $(OBJ_DIR)/DigitalInput.o $(OBJ_DIR)/Utility.o $(OBJ_DIR)/Jaguar.o \
	 $(OBJ_DIR)/Relay.o $(OBJ_DIR)/Compressor.o $(OBJ_DIR)/AnalogChannel.o \
	 $(OBJ_DIR)/Task.o $(OBJ_DIR)/HiTechnicCompass.o $(OBJ_DIR)/AnalogModule.o \
	 $(OBJ_DIR)/SerialPort.o $(OBJ_DIR)/Error.o $(OBJ_DIR)/FrcError.o \
	 $(OBJ_DIR)/ErrorBase.o $(OBJ_DIR)/Ultrasonic.o $(OBJ_DIR)/AnalogTriggerOutput.o \
	 $(OBJ_DIR)/AnalogTrigger.o $(OBJ_DIR)/AxisCamera.o $(OBJ_DIR)/Watchdog.o \
	 $(OBJ_DIR)/Solenoid.o $(OBJ_DIR)/PIDController.o $(OBJ_DIR)/Dashboard.o \
	 $(OBJ_DIR)/Counter.o $(OBJ_DIR)/SimpleRobot.o $(OBJ_DIR)/Accelerometer.o \
	 $(OBJ_DIR)/DigitalOutput.o $(OBJ_DIR)/BaeUtilities.o $(OBJ_DIR)/PWM.o \
	 $(OBJ_DIR)/Encoder.o $(OBJ_DIR)/VisionAPI.o $(OBJ_DIR)/DriverStation.o \
	 $(OBJ_DIR)/Module.o $(OBJ_DIR)/RobotDrive.o $(OBJ_DIR)/TrackAPI.o \
	 $(OBJ_DIR)/IterativeRobot.o $(OBJ_DIR)/I2C.o $(OBJ_DIR)/DigitalModule.o \
	 $(OBJ_DIR)/Notifier.o $(OBJ_DIR)/InterruptableSensorBase.o $(OBJ_DIR)/Resource.o \
	 $(OBJ_DIR)/Synchronized.o $(OBJ_DIR)/Joystick.o $(OBJ_DIR)/Victor.o \
	 $(OBJ_DIR)/RobotBase.o $(OBJ_DIR)/GearTooth.o $(OBJ_DIR)/DigitalSource.o \
	 $(OBJ_DIR)/Servo.o $(OBJ_DIR)/SensorBase.o

PROJECT_TARGETS := $(OBJ_DIR)/WPILib.a

SUB_OBJECTS :=
SUB_TARGETS :=
endif
ifeq ($(BUILD_SPEC),PPC440diab)
SUBDIRS :=
OBJECTS := $(OBJ_DIR)/PCVideoServer.o $(OBJ_DIR)/Gyro.o $(OBJ_DIR)/Timer.o \
	 $(OBJ_DIR)/DigitalInput.o $(OBJ_DIR)/Utility.o $(OBJ_DIR)/Jaguar.o \
	 $(OBJ_DIR)/Relay.o $(OBJ_DIR)/Compressor.o $(OBJ_DIR)/AnalogChannel.o \
	 $(OBJ_DIR)/Task.o $(OBJ_DIR)/HiTechnicCompass.o $(OBJ_DIR)/AnalogModule.o \
	 $(OBJ_DIR)/SerialPort.o $(OBJ_DIR)/Error.o $(OBJ_DIR)/FrcError.o \
	 $(OBJ_DIR)/ErrorBase.o $(OBJ_DIR)/Ultrasonic.o $(OBJ_DIR)/AnalogTriggerOutput.o \
	 $(OBJ_DIR)/AnalogTrigger.o $(OBJ_DIR)/AxisCamera.o $(OBJ_DIR)/Watchdog.o \
	 $(OBJ_DIR)/Solenoid.o $(OBJ_DIR)/PIDController.o $(OBJ_DIR)/Dashboard.o \
	 $(OBJ_DIR)/Counter.o $(OBJ_DIR)/SimpleRobot.o $(OBJ_DIR)/Accelerometer.o \
	 $(OBJ_DIR)/DigitalOutput.o $(OBJ_DIR)/BaeUtilities.o $(OBJ_DIR)/PWM.o \
	 $(OBJ_DIR)/Encoder.o $(OBJ_DIR)/VisionAPI.o $(OBJ_DIR)/DriverStation.o \
	 $(OBJ_DIR)/Module.o $(OBJ_DIR)/RobotDrive.o $(OBJ_DIR)/TrackAPI.o \
	 $(OBJ_DIR)/IterativeRobot.o $(OBJ_DIR)/I2C.o $(OBJ_DIR)/DigitalModule.o \
	 $(OBJ_DIR)/Notifier.o $(OBJ_DIR)/InterruptableSensorBase.o $(OBJ_DIR)/Resource.o \
	 $(OBJ_DIR)/Synchronized.o $(OBJ_DIR)/Joystick.o $(OBJ_DIR)/Victor.o \
	 $(OBJ_DIR)/RobotBase.o $(OBJ_DIR)/GearTooth.o $(OBJ_DIR)/DigitalSource.o \
	 $(OBJ_DIR)/Servo.o $(OBJ_DIR)/SensorBase.o

PROJECT_TARGETS := $(OBJ_DIR)/WPILib.a

SUB_OBJECTS :=
SUB_TARGETS :=
endif
ifeq ($(BUILD_SPEC),PPC440gnu)
SUBDIRS :=
OBJECTS := $(OBJ_DIR)/PCVideoServer.o $(OBJ_DIR)/Gyro.o $(OBJ_DIR)/Timer.o \
	 $(OBJ_DIR)/DigitalInput.o $(OBJ_DIR)/Utility.o $(OBJ_DIR)/Jaguar.o \
	 $(OBJ_DIR)/Relay.o $(OBJ_DIR)/Compressor.o $(OBJ_DIR)/AnalogChannel.o \
	 $(OBJ_DIR)/Task.o $(OBJ_DIR)/HiTechnicCompass.o $(OBJ_DIR)/AnalogModule.o \
	 $(OBJ_DIR)/SerialPort.o $(OBJ_DIR)/Error.o $(OBJ_DIR)/FrcError.o \
	 $(OBJ_DIR)/ErrorBase.o $(OBJ_DIR)/Ultrasonic.o $(OBJ_DIR)/AnalogTriggerOutput.o \
	 $(OBJ_DIR)/AnalogTrigger.o $(OBJ_DIR)/AxisCamera.o $(OBJ_DIR)/Watchdog.o \
	 $(OBJ_DIR)/Solenoid.o $(OBJ_DIR)/PIDController.o $(OBJ_DIR)/Dashboard.o \
	 $(OBJ_DIR)/Counter.o $(OBJ_DIR)/SimpleRobot.o $(OBJ_DIR)/Accelerometer.o \
	 $(OBJ_DIR)/DigitalOutput.o $(OBJ_DIR)/BaeUtilities.o $(OBJ_DIR)/PWM.o \
	 $(OBJ_DIR)/Encoder.o $(OBJ_DIR)/VisionAPI.o $(OBJ_DIR)/DriverStation.o \
	 $(OBJ_DIR)/Module.o $(OBJ_DIR)/RobotDrive.o $(OBJ_DIR)/TrackAPI.o \
	 $(OBJ_DIR)/IterativeRobot.o $(OBJ_DIR)/I2C.o $(OBJ_DIR)/DigitalModule.o \
	 $(OBJ_DIR)/Notifier.o $(OBJ_DIR)/InterruptableSensorBase.o $(OBJ_DIR)/Resource.o \
	 $(OBJ_DIR)/Synchronized.o $(OBJ_DIR)/Joystick.o $(OBJ_DIR)/Victor.o \
	 $(OBJ_DIR)/RobotBase.o $(OBJ_DIR)/GearTooth.o $(OBJ_DIR)/DigitalSource.o \
	 $(OBJ_DIR)/Servo.o $(OBJ_DIR)/SensorBase.o

PROJECT_TARGETS := $(OBJ_DIR)/WPILib.a

SUB_OBJECTS :=
SUB_TARGETS :=
endif
ifeq ($(BUILD_SPEC),PPC440sfdiab)
SUBDIRS :=
OBJECTS := $(OBJ_DIR)/PCVideoServer.o $(OBJ_DIR)/Gyro.o $(OBJ_DIR)/Timer.o \
	 $(OBJ_DIR)/DigitalInput.o $(OBJ_DIR)/Utility.o $(OBJ_DIR)/Jaguar.o \
	 $(OBJ_DIR)/Relay.o $(OBJ_DIR)/Compressor.o $(OBJ_DIR)/AnalogChannel.o \
	 $(OBJ_DIR)/Task.o $(OBJ_DIR)/HiTechnicCompass.o $(OBJ_DIR)/AnalogModule.o \
	 $(OBJ_DIR)/SerialPort.o $(OBJ_DIR)/Error.o $(OBJ_DIR)/FrcError.o \
	 $(OBJ_DIR)/ErrorBase.o $(OBJ_DIR)/Ultrasonic.o $(OBJ_DIR)/AnalogTriggerOutput.o \
	 $(OBJ_DIR)/AnalogTrigger.o $(OBJ_DIR)/AxisCamera.o $(OBJ_DIR)/Watchdog.o \
	 $(OBJ_DIR)/Solenoid.o $(OBJ_DIR)/PIDController.o $(OBJ_DIR)/Dashboard.o \
	 $(OBJ_DIR)/Counter.o $(OBJ_DIR)/SimpleRobot.o $(OBJ_DIR)/Accelerometer.o \
	 $(OBJ_DIR)/DigitalOutput.o $(OBJ_DIR)/BaeUtilities.o $(OBJ_DIR)/PWM.o \
	 $(OBJ_DIR)/Encoder.o $(OBJ_DIR)/VisionAPI.o $(OBJ_DIR)/DriverStation.o \
	 $(OBJ_DIR)/Module.o $(OBJ_DIR)/RobotDrive.o $(OBJ_DIR)/TrackAPI.o \
	 $(OBJ_DIR)/IterativeRobot.o $(OBJ_DIR)/I2C.o $(OBJ_DIR)/DigitalModule.o \
	 $(OBJ_DIR)/Notifier.o $(OBJ_DIR)/InterruptableSensorBase.o $(OBJ_DIR)/Resource.o \
	 $(OBJ_DIR)/Synchronized.o $(OBJ_DIR)/Joystick.o $(OBJ_DIR)/Victor.o \
	 $(OBJ_DIR)/RobotBase.o $(OBJ_DIR)/GearTooth.o $(OBJ_DIR)/DigitalSource.o \
	 $(OBJ_DIR)/Servo.o $(OBJ_DIR)/SensorBase.o

PROJECT_TARGETS := $(OBJ_DIR)/WPILib.a

SUB_OBJECTS :=
SUB_TARGETS :=
endif
ifeq ($(BUILD_SPEC),PPC440sfgnu)
SUBDIRS :=
OBJECTS := $(OBJ_DIR)/PCVideoServer.o $(OBJ_DIR)/Gyro.o $(OBJ_DIR)/Timer.o \
	 $(OBJ_DIR)/DigitalInput.o $(OBJ_DIR)/Utility.o $(OBJ_DIR)/Jaguar.o \
	 $(OBJ_DIR)/Relay.o $(OBJ_DIR)/Compressor.o $(OBJ_DIR)/AnalogChannel.o \
	 $(OBJ_DIR)/Task.o $(OBJ_DIR)/HiTechnicCompass.o $(OBJ_DIR)/AnalogModule.o \
	 $(OBJ_DIR)/SerialPort.o $(OBJ_DIR)/Error.o $(OBJ_DIR)/FrcError.o \
	 $(OBJ_DIR)/ErrorBase.o $(OBJ_DIR)/Ultrasonic.o $(OBJ_DIR)/AnalogTriggerOutput.o \
	 $(OBJ_DIR)/AnalogTrigger.o $(OBJ_DIR)/AxisCamera.o $(OBJ_DIR)/Watchdog.o \
	 $(OBJ_DIR)/Solenoid.o $(OBJ_DIR)/PIDController.o $(OBJ_DIR)/Dashboard.o \
	 $(OBJ_DIR)/Counter.o $(OBJ_DIR)/SimpleRobot.o $(OBJ_DIR)/Accelerometer.o \
	 $(OBJ_DIR)/DigitalOutput.o $(OBJ_DIR)/BaeUtilities.o $(OBJ_DIR)/PWM.o \
	 $(OBJ_DIR)/Encoder.o $(OBJ_DIR)/VisionAPI.o $(OBJ_DIR)/DriverStation.o \
	 $(OBJ_DIR)/Module.o $(OBJ_DIR)/RobotDrive.o $(OBJ_DIR)/TrackAPI.o \
	 $(OBJ_DIR)/IterativeRobot.o $(OBJ_DIR)/I2C.o $(OBJ_DIR)/DigitalModule.o \
	 $(OBJ_DIR)/Notifier.o $(OBJ_DIR)/InterruptableSensorBase.o $(OBJ_DIR)/Resource.o \
	 $(OBJ_DIR)/Synchronized.o $(OBJ_DIR)/Joystick.o $(OBJ_DIR)/Victor.o \
	 $(OBJ_DIR)/RobotBase.o $(OBJ_DIR)/GearTooth.o $(OBJ_DIR)/DigitalSource.o \
	 $(OBJ_DIR)/Servo.o $(OBJ_DIR)/SensorBase.o

PROJECT_TARGETS := $(OBJ_DIR)/WPILib.a

SUB_OBJECTS :=
SUB_TARGETS :=
endif
ifeq ($(BUILD_SPEC),PPC603diab)
SUBDIRS :=
OBJECTS := $(OBJ_DIR)/PCVideoServer.o $(OBJ_DIR)/Gyro.o $(OBJ_DIR)/Timer.o \
	 $(OBJ_DIR)/DigitalInput.o $(OBJ_DIR)/Utility.o $(OBJ_DIR)/Jaguar.o \
	 $(OBJ_DIR)/Relay.o $(OBJ_DIR)/Compressor.o $(OBJ_DIR)/AnalogChannel.o \
	 $(OBJ_DIR)/Task.o $(OBJ_DIR)/HiTechnicCompass.o $(OBJ_DIR)/AnalogModule.o \
	 $(OBJ_DIR)/SerialPort.o $(OBJ_DIR)/Error.o $(OBJ_DIR)/FrcError.o \
	 $(OBJ_DIR)/ErrorBase.o $(OBJ_DIR)/Ultrasonic.o $(OBJ_DIR)/AnalogTriggerOutput.o \
	 $(OBJ_DIR)/AnalogTrigger.o $(OBJ_DIR)/AxisCamera.o $(OBJ_DIR)/Watchdog.o \
	 $(OBJ_DIR)/Solenoid.o $(OBJ_DIR)/PIDController.o $(OBJ_DIR)/Dashboard.o \
	 $(OBJ_DIR)/Counter.o $(OBJ_DIR)/SimpleRobot.o $(OBJ_DIR)/Accelerometer.o \
	 $(OBJ_DIR)/DigitalOutput.o $(OBJ_DIR)/BaeUtilities.o $(OBJ_DIR)/PWM.o \
	 $(OBJ_DIR)/Encoder.o $(OBJ_DIR)/VisionAPI.o $(OBJ_DIR)/DriverStation.o \
	 $(OBJ_DIR)/Module.o $(OBJ_DIR)/RobotDrive.o $(OBJ_DIR)/TrackAPI.o \
	 $(OBJ_DIR)/IterativeRobot.o $(OBJ_DIR)/I2C.o $(OBJ_DIR)/DigitalModule.o \
	 $(OBJ_DIR)/Notifier.o $(OBJ_DIR)/InterruptableSensorBase.o $(OBJ_DIR)/Resource.o \
	 $(OBJ_DIR)/Synchronized.o $(OBJ_DIR)/Joystick.o $(OBJ_DIR)/Victor.o \
	 $(OBJ_DIR)/RobotBase.o $(OBJ_DIR)/GearTooth.o $(OBJ_DIR)/DigitalSource.o \
	 $(OBJ_DIR)/Servo.o $(OBJ_DIR)/SensorBase.o

PROJECT_TARGETS := $(OBJ_DIR)/WPILib.a

SUB_OBJECTS :=
SUB_TARGETS :=
endif
ifeq ($(BUILD_SPEC),PPC603gnu)
SUBDIRS := "C:/WindRiver/workspace/WPILib/.settings" \
	 "C:/WindRiver/workspace/WPILib/CInterfaces" \
	 "C:/WindRiver/workspace/WPILib/ChipObject" \
	 "C:/WindRiver/workspace/WPILib/NetworkCommunication" \
	 "C:/WindRiver/workspace/WPILib/Scripts" \
	 "C:/WindRiver/workspace/WPILib/visa"
OBJECTS := $(OBJ_DIR)/PCVideoServer.o $(OBJ_DIR)/Gyro.o $(OBJ_DIR)/Timer.o \
	 $(OBJ_DIR)/DigitalInput.o $(OBJ_DIR)/Utility.o $(OBJ_DIR)/Jaguar.o \
	 $(OBJ_DIR)/Relay.o $(OBJ_DIR)/Compressor.o $(OBJ_DIR)/AnalogChannel.o \
	 $(OBJ_DIR)/Task.o $(OBJ_DIR)/HiTechnicCompass.o $(OBJ_DIR)/AnalogModule.o \
	 $(OBJ_DIR)/SerialPort.o $(OBJ_DIR)/Error.o $(OBJ_DIR)/FrcError.o \
	 $(OBJ_DIR)/ErrorBase.o $(OBJ_DIR)/Ultrasonic.o $(OBJ_DIR)/AnalogTriggerOutput.o \
	 $(OBJ_DIR)/AnalogTrigger.o $(OBJ_DIR)/AxisCamera.o $(OBJ_DIR)/Watchdog.o \
	 $(OBJ_DIR)/Solenoid.o $(OBJ_DIR)/PIDController.o $(OBJ_DIR)/Dashboard.o \
	 $(OBJ_DIR)/Counter.o $(OBJ_DIR)/SimpleRobot.o $(OBJ_DIR)/Accelerometer.o \
	 $(OBJ_DIR)/DigitalOutput.o $(OBJ_DIR)/BaeUtilities.o $(OBJ_DIR)/PWM.o \
	 $(OBJ_DIR)/Encoder.o $(OBJ_DIR)/VisionAPI.o $(OBJ_DIR)/DriverStation.o \
	 $(OBJ_DIR)/Module.o $(OBJ_DIR)/RobotDrive.o $(OBJ_DIR)/TrackAPI.o \
	 $(OBJ_DIR)/IterativeRobot.o $(OBJ_DIR)/I2C.o $(OBJ_DIR)/DigitalModule.o \
	 $(OBJ_DIR)/Notifier.o $(OBJ_DIR)/InterruptableSensorBase.o $(OBJ_DIR)/Resource.o \
	 $(OBJ_DIR)/Synchronized.o $(OBJ_DIR)/Joystick.o $(OBJ_DIR)/Victor.o \
	 $(OBJ_DIR)/RobotBase.o $(OBJ_DIR)/GearTooth.o $(OBJ_DIR)/DigitalSource.o \
	 $(OBJ_DIR)/Servo.o $(OBJ_DIR)/SensorBase.o

PROJECT_TARGETS := $(OBJ_DIR)/WPILib.a

SUB_OBJECTS := CInterfaces/$(OBJ_DIR)/CAnalogChannel.o \
	 CInterfaces/$(OBJ_DIR)/CCounter.o \
	 CInterfaces/$(OBJ_DIR)/SimpleCRobot.o \
	 CInterfaces/$(OBJ_DIR)/CAccelerometer.o \
	 CInterfaces/$(OBJ_DIR)/CJoystick.o \
	 CInterfaces/$(OBJ_DIR)/CTimer.o \
	 CInterfaces/$(OBJ_DIR)/CCompressor.o \
	 CInterfaces/$(OBJ_DIR)/CRobotDrive.o \
	 CInterfaces/$(OBJ_DIR)/CDigitalInput.o \
	 CInterfaces/$(OBJ_DIR)/CGearTooth.o \
	 CInterfaces/$(OBJ_DIR)/CGyro.o \
	 CInterfaces/$(OBJ_DIR)/CDigitalOutput.o \
	 CInterfaces/$(OBJ_DIR)/CSolenoid.o \
	 CInterfaces/$(OBJ_DIR)/CSerialPort.o \
	 CInterfaces/$(OBJ_DIR)/CRelay.o \
	 CInterfaces/$(OBJ_DIR)/CDriverStation.o \
	 CInterfaces/$(OBJ_DIR)/CVictor.o \
	 CInterfaces/$(OBJ_DIR)/CPWM.o \
	 CInterfaces/$(OBJ_DIR)/CEncoder.o \
	 CInterfaces/$(OBJ_DIR)/CUltrasonic.o \
	 CInterfaces/$(OBJ_DIR)/CJaguar.o \
	 CInterfaces/$(OBJ_DIR)/CServo.o
SUB_TARGETS :=
endif
ifeq ($(BUILD_SPEC),PPC604diab)
SUBDIRS :=
OBJECTS := $(OBJ_DIR)/PCVideoServer.o $(OBJ_DIR)/Gyro.o $(OBJ_DIR)/Timer.o \
	 $(OBJ_DIR)/DigitalInput.o $(OBJ_DIR)/Utility.o $(OBJ_DIR)/Jaguar.o \
	 $(OBJ_DIR)/Relay.o $(OBJ_DIR)/Compressor.o $(OBJ_DIR)/AnalogChannel.o \
	 $(OBJ_DIR)/Task.o $(OBJ_DIR)/HiTechnicCompass.o $(OBJ_DIR)/AnalogModule.o \
	 $(OBJ_DIR)/SerialPort.o $(OBJ_DIR)/Error.o $(OBJ_DIR)/FrcError.o \
	 $(OBJ_DIR)/ErrorBase.o $(OBJ_DIR)/Ultrasonic.o $(OBJ_DIR)/AnalogTriggerOutput.o \
	 $(OBJ_DIR)/AnalogTrigger.o $(OBJ_DIR)/AxisCamera.o $(OBJ_DIR)/Watchdog.o \
	 $(OBJ_DIR)/Solenoid.o $(OBJ_DIR)/PIDController.o $(OBJ_DIR)/Dashboard.o \
	 $(OBJ_DIR)/Counter.o $(OBJ_DIR)/SimpleRobot.o $(OBJ_DIR)/Accelerometer.o \
	 $(OBJ_DIR)/DigitalOutput.o $(OBJ_DIR)/BaeUtilities.o $(OBJ_DIR)/PWM.o \
	 $(OBJ_DIR)/Encoder.o $(OBJ_DIR)/VisionAPI.o $(OBJ_DIR)/DriverStation.o \
	 $(OBJ_DIR)/Module.o $(OBJ_DIR)/RobotDrive.o $(OBJ_DIR)/TrackAPI.o \
	 $(OBJ_DIR)/IterativeRobot.o $(OBJ_DIR)/I2C.o $(OBJ_DIR)/DigitalModule.o \
	 $(OBJ_DIR)/Notifier.o $(OBJ_DIR)/InterruptableSensorBase.o $(OBJ_DIR)/Resource.o \
	 $(OBJ_DIR)/Synchronized.o $(OBJ_DIR)/Joystick.o $(OBJ_DIR)/Victor.o \
	 $(OBJ_DIR)/RobotBase.o $(OBJ_DIR)/GearTooth.o $(OBJ_DIR)/DigitalSource.o \
	 $(OBJ_DIR)/Servo.o $(OBJ_DIR)/SensorBase.o

PROJECT_TARGETS := $(OBJ_DIR)/WPILib.a

SUB_OBJECTS :=
SUB_TARGETS :=
endif
ifeq ($(BUILD_SPEC),PPC604gnu)
SUBDIRS :=
OBJECTS := $(OBJ_DIR)/PCVideoServer.o $(OBJ_DIR)/Gyro.o $(OBJ_DIR)/Timer.o \
	 $(OBJ_DIR)/DigitalInput.o $(OBJ_DIR)/Utility.o $(OBJ_DIR)/Jaguar.o \
	 $(OBJ_DIR)/Relay.o $(OBJ_DIR)/Compressor.o $(OBJ_DIR)/AnalogChannel.o \
	 $(OBJ_DIR)/Task.o $(OBJ_DIR)/HiTechnicCompass.o $(OBJ_DIR)/AnalogModule.o \
	 $(OBJ_DIR)/SerialPort.o $(OBJ_DIR)/Error.o $(OBJ_DIR)/FrcError.o \
	 $(OBJ_DIR)/ErrorBase.o $(OBJ_DIR)/Ultrasonic.o $(OBJ_DIR)/AnalogTriggerOutput.o \
	 $(OBJ_DIR)/AnalogTrigger.o $(OBJ_DIR)/AxisCamera.o $(OBJ_DIR)/Watchdog.o \
	 $(OBJ_DIR)/Solenoid.o $(OBJ_DIR)/PIDController.o $(OBJ_DIR)/Dashboard.o \
	 $(OBJ_DIR)/Counter.o $(OBJ_DIR)/SimpleRobot.o $(OBJ_DIR)/Accelerometer.o \
	 $(OBJ_DIR)/DigitalOutput.o $(OBJ_DIR)/BaeUtilities.o $(OBJ_DIR)/PWM.o \
	 $(OBJ_DIR)/Encoder.o $(OBJ_DIR)/VisionAPI.o $(OBJ_DIR)/DriverStation.o \
	 $(OBJ_DIR)/Module.o $(OBJ_DIR)/RobotDrive.o $(OBJ_DIR)/TrackAPI.o \
	 $(OBJ_DIR)/IterativeRobot.o $(OBJ_DIR)/I2C.o $(OBJ_DIR)/DigitalModule.o \
	 $(OBJ_DIR)/Notifier.o $(OBJ_DIR)/InterruptableSensorBase.o $(OBJ_DIR)/Resource.o \
	 $(OBJ_DIR)/Synchronized.o $(OBJ_DIR)/Joystick.o $(OBJ_DIR)/Victor.o \
	 $(OBJ_DIR)/RobotBase.o $(OBJ_DIR)/GearTooth.o $(OBJ_DIR)/DigitalSource.o \
	 $(OBJ_DIR)/Servo.o $(OBJ_DIR)/SensorBase.o

PROJECT_TARGETS := $(OBJ_DIR)/WPILib.a

SUB_OBJECTS :=
SUB_TARGETS :=
endif
ifeq ($(BUILD_SPEC),PPC85XXdiab)
SUBDIRS :=
OBJECTS := $(OBJ_DIR)/PCVideoServer.o $(OBJ_DIR)/Gyro.o $(OBJ_DIR)/Timer.o \
	 $(OBJ_DIR)/DigitalInput.o $(OBJ_DIR)/Utility.o $(OBJ_DIR)/Jaguar.o \
	 $(OBJ_DIR)/Relay.o $(OBJ_DIR)/Compressor.o $(OBJ_DIR)/AnalogChannel.o \
	 $(OBJ_DIR)/Task.o $(OBJ_DIR)/HiTechnicCompass.o $(OBJ_DIR)/AnalogModule.o \
	 $(OBJ_DIR)/SerialPort.o $(OBJ_DIR)/Error.o $(OBJ_DIR)/FrcError.o \
	 $(OBJ_DIR)/ErrorBase.o $(OBJ_DIR)/Ultrasonic.o $(OBJ_DIR)/AnalogTriggerOutput.o \
	 $(OBJ_DIR)/AnalogTrigger.o $(OBJ_DIR)/AxisCamera.o $(OBJ_DIR)/Watchdog.o \
	 $(OBJ_DIR)/Solenoid.o $(OBJ_DIR)/PIDController.o $(OBJ_DIR)/Dashboard.o \
	 $(OBJ_DIR)/Counter.o $(OBJ_DIR)/SimpleRobot.o $(OBJ_DIR)/Accelerometer.o \
	 $(OBJ_DIR)/DigitalOutput.o $(OBJ_DIR)/BaeUtilities.o $(OBJ_DIR)/PWM.o \
	 $(OBJ_DIR)/Encoder.o $(OBJ_DIR)/VisionAPI.o $(OBJ_DIR)/DriverStation.o \
	 $(OBJ_DIR)/Module.o $(OBJ_DIR)/RobotDrive.o $(OBJ_DIR)/TrackAPI.o \
	 $(OBJ_DIR)/IterativeRobot.o $(OBJ_DIR)/I2C.o $(OBJ_DIR)/DigitalModule.o \
	 $(OBJ_DIR)/Notifier.o $(OBJ_DIR)/InterruptableSensorBase.o $(OBJ_DIR)/Resource.o \
	 $(OBJ_DIR)/Synchronized.o $(OBJ_DIR)/Joystick.o $(OBJ_DIR)/Victor.o \
	 $(OBJ_DIR)/RobotBase.o $(OBJ_DIR)/GearTooth.o $(OBJ_DIR)/DigitalSource.o \
	 $(OBJ_DIR)/Servo.o $(OBJ_DIR)/SensorBase.o

PROJECT_TARGETS := $(OBJ_DIR)/WPILib.a

SUB_OBJECTS :=
SUB_TARGETS :=
endif
ifeq ($(BUILD_SPEC),PPC85XXgnu)
SUBDIRS :=
OBJECTS := $(OBJ_DIR)/PCVideoServer.o $(OBJ_DIR)/Gyro.o $(OBJ_DIR)/Timer.o \
	 $(OBJ_DIR)/DigitalInput.o $(OBJ_DIR)/Utility.o $(OBJ_DIR)/Jaguar.o \
	 $(OBJ_DIR)/Relay.o $(OBJ_DIR)/Compressor.o $(OBJ_DIR)/AnalogChannel.o \
	 $(OBJ_DIR)/Task.o $(OBJ_DIR)/HiTechnicCompass.o $(OBJ_DIR)/AnalogModule.o \
	 $(OBJ_DIR)/SerialPort.o $(OBJ_DIR)/Error.o $(OBJ_DIR)/FrcError.o \
	 $(OBJ_DIR)/ErrorBase.o $(OBJ_DIR)/Ultrasonic.o $(OBJ_DIR)/AnalogTriggerOutput.o \
	 $(OBJ_DIR)/AnalogTrigger.o $(OBJ_DIR)/AxisCamera.o $(OBJ_DIR)/Watchdog.o \
	 $(OBJ_DIR)/Solenoid.o $(OBJ_DIR)/PIDController.o $(OBJ_DIR)/Dashboard.o \
	 $(OBJ_DIR)/Counter.o $(OBJ_DIR)/SimpleRobot.o $(OBJ_DIR)/Accelerometer.o \
	 $(OBJ_DIR)/DigitalOutput.o $(OBJ_DIR)/BaeUtilities.o $(OBJ_DIR)/PWM.o \
	 $(OBJ_DIR)/Encoder.o $(OBJ_DIR)/VisionAPI.o $(OBJ_DIR)/DriverStation.o \
	 $(OBJ_DIR)/Module.o $(OBJ_DIR)/RobotDrive.o $(OBJ_DIR)/TrackAPI.o \
	 $(OBJ_DIR)/IterativeRobot.o $(OBJ_DIR)/I2C.o $(OBJ_DIR)/DigitalModule.o \
	 $(OBJ_DIR)/Notifier.o $(OBJ_DIR)/InterruptableSensorBase.o $(OBJ_DIR)/Resource.o \
	 $(OBJ_DIR)/Synchronized.o $(OBJ_DIR)/Joystick.o $(OBJ_DIR)/Victor.o \
	 $(OBJ_DIR)/RobotBase.o $(OBJ_DIR)/GearTooth.o $(OBJ_DIR)/DigitalSource.o \
	 $(OBJ_DIR)/Servo.o $(OBJ_DIR)/SensorBase.o

PROJECT_TARGETS := $(OBJ_DIR)/WPILib.a

SUB_OBJECTS :=
SUB_TARGETS :=
endif
ifeq ($(BUILD_SPEC),PPC85XXsfdiab)
SUBDIRS :=
OBJECTS := $(OBJ_DIR)/PCVideoServer.o $(OBJ_DIR)/Gyro.o $(OBJ_DIR)/Timer.o \
	 $(OBJ_DIR)/DigitalInput.o $(OBJ_DIR)/Utility.o $(OBJ_DIR)/Jaguar.o \
	 $(OBJ_DIR)/Relay.o $(OBJ_DIR)/Compressor.o $(OBJ_DIR)/AnalogChannel.o \
	 $(OBJ_DIR)/Task.o $(OBJ_DIR)/HiTechnicCompass.o $(OBJ_DIR)/AnalogModule.o \
	 $(OBJ_DIR)/SerialPort.o $(OBJ_DIR)/Error.o $(OBJ_DIR)/FrcError.o \
	 $(OBJ_DIR)/ErrorBase.o $(OBJ_DIR)/Ultrasonic.o $(OBJ_DIR)/AnalogTriggerOutput.o \
	 $(OBJ_DIR)/AnalogTrigger.o $(OBJ_DIR)/AxisCamera.o $(OBJ_DIR)/Watchdog.o \
	 $(OBJ_DIR)/Solenoid.o $(OBJ_DIR)/PIDController.o $(OBJ_DIR)/Dashboard.o \
	 $(OBJ_DIR)/Counter.o $(OBJ_DIR)/SimpleRobot.o $(OBJ_DIR)/Accelerometer.o \
	 $(OBJ_DIR)/DigitalOutput.o $(OBJ_DIR)/BaeUtilities.o $(OBJ_DIR)/PWM.o \
	 $(OBJ_DIR)/Encoder.o $(OBJ_DIR)/VisionAPI.o $(OBJ_DIR)/DriverStation.o \
	 $(OBJ_DIR)/Module.o $(OBJ_DIR)/RobotDrive.o $(OBJ_DIR)/TrackAPI.o \
	 $(OBJ_DIR)/IterativeRobot.o $(OBJ_DIR)/I2C.o $(OBJ_DIR)/DigitalModule.o \
	 $(OBJ_DIR)/Notifier.o $(OBJ_DIR)/InterruptableSensorBase.o $(OBJ_DIR)/Resource.o \
	 $(OBJ_DIR)/Synchronized.o $(OBJ_DIR)/Joystick.o $(OBJ_DIR)/Victor.o \
	 $(OBJ_DIR)/RobotBase.o $(OBJ_DIR)/GearTooth.o $(OBJ_DIR)/DigitalSource.o \
	 $(OBJ_DIR)/Servo.o $(OBJ_DIR)/SensorBase.o

PROJECT_TARGETS := $(OBJ_DIR)/WPILib.a

SUB_OBJECTS :=
SUB_TARGETS :=
endif
ifeq ($(BUILD_SPEC),PPC85XXsfgnu)
SUBDIRS :=
OBJECTS := $(OBJ_DIR)/PCVideoServer.o $(OBJ_DIR)/Gyro.o $(OBJ_DIR)/Timer.o \
	 $(OBJ_DIR)/DigitalInput.o $(OBJ_DIR)/Utility.o $(OBJ_DIR)/Jaguar.o \
	 $(OBJ_DIR)/Relay.o $(OBJ_DIR)/Compressor.o $(OBJ_DIR)/AnalogChannel.o \
	 $(OBJ_DIR)/Task.o $(OBJ_DIR)/HiTechnicCompass.o $(OBJ_DIR)/AnalogModule.o \
	 $(OBJ_DIR)/SerialPort.o $(OBJ_DIR)/Error.o $(OBJ_DIR)/FrcError.o \
	 $(OBJ_DIR)/ErrorBase.o $(OBJ_DIR)/Ultrasonic.o $(OBJ_DIR)/AnalogTriggerOutput.o \
	 $(OBJ_DIR)/AnalogTrigger.o $(OBJ_DIR)/AxisCamera.o $(OBJ_DIR)/Watchdog.o \
	 $(OBJ_DIR)/Solenoid.o $(OBJ_DIR)/PIDController.o $(OBJ_DIR)/Dashboard.o \
	 $(OBJ_DIR)/Counter.o $(OBJ_DIR)/SimpleRobot.o $(OBJ_DIR)/Accelerometer.o \
	 $(OBJ_DIR)/DigitalOutput.o $(OBJ_DIR)/BaeUtilities.o $(OBJ_DIR)/PWM.o \
	 $(OBJ_DIR)/Encoder.o $(OBJ_DIR)/VisionAPI.o $(OBJ_DIR)/DriverStation.o \
	 $(OBJ_DIR)/Module.o $(OBJ_DIR)/RobotDrive.o $(OBJ_DIR)/TrackAPI.o \
	 $(OBJ_DIR)/IterativeRobot.o $(OBJ_DIR)/I2C.o $(OBJ_DIR)/DigitalModule.o \
	 $(OBJ_DIR)/Notifier.o $(OBJ_DIR)/InterruptableSensorBase.o $(OBJ_DIR)/Resource.o \
	 $(OBJ_DIR)/Synchronized.o $(OBJ_DIR)/Joystick.o $(OBJ_DIR)/Victor.o \
	 $(OBJ_DIR)/RobotBase.o $(OBJ_DIR)/GearTooth.o $(OBJ_DIR)/DigitalSource.o \
	 $(OBJ_DIR)/Servo.o $(OBJ_DIR)/SensorBase.o

PROJECT_TARGETS := $(OBJ_DIR)/WPILib.a

SUB_OBJECTS :=
SUB_TARGETS :=
endif
ifeq ($(BUILD_SPEC),PPC860sfdiab)
SUBDIRS :=
OBJECTS := $(OBJ_DIR)/PCVideoServer.o $(OBJ_DIR)/Gyro.o $(OBJ_DIR)/Timer.o \
	 $(OBJ_DIR)/DigitalInput.o $(OBJ_DIR)/Utility.o $(OBJ_DIR)/Jaguar.o \
	 $(OBJ_DIR)/Relay.o $(OBJ_DIR)/Compressor.o $(OBJ_DIR)/AnalogChannel.o \
	 $(OBJ_DIR)/Task.o $(OBJ_DIR)/HiTechnicCompass.o $(OBJ_DIR)/AnalogModule.o \
	 $(OBJ_DIR)/SerialPort.o $(OBJ_DIR)/Error.o $(OBJ_DIR)/FrcError.o \
	 $(OBJ_DIR)/ErrorBase.o $(OBJ_DIR)/Ultrasonic.o $(OBJ_DIR)/AnalogTriggerOutput.o \
	 $(OBJ_DIR)/AnalogTrigger.o $(OBJ_DIR)/AxisCamera.o $(OBJ_DIR)/Watchdog.o \
	 $(OBJ_DIR)/Solenoid.o $(OBJ_DIR)/PIDController.o $(OBJ_DIR)/Dashboard.o \
	 $(OBJ_DIR)/Counter.o $(OBJ_DIR)/SimpleRobot.o $(OBJ_DIR)/Accelerometer.o \
	 $(OBJ_DIR)/DigitalOutput.o $(OBJ_DIR)/BaeUtilities.o $(OBJ_DIR)/PWM.o \
	 $(OBJ_DIR)/Encoder.o $(OBJ_DIR)/VisionAPI.o $(OBJ_DIR)/DriverStation.o \
	 $(OBJ_DIR)/Module.o $(OBJ_DIR)/RobotDrive.o $(OBJ_DIR)/TrackAPI.o \
	 $(OBJ_DIR)/IterativeRobot.o $(OBJ_DIR)/I2C.o $(OBJ_DIR)/DigitalModule.o \
	 $(OBJ_DIR)/Notifier.o $(OBJ_DIR)/InterruptableSensorBase.o $(OBJ_DIR)/Resource.o \
	 $(OBJ_DIR)/Synchronized.o $(OBJ_DIR)/Joystick.o $(OBJ_DIR)/Victor.o \
	 $(OBJ_DIR)/RobotBase.o $(OBJ_DIR)/GearTooth.o $(OBJ_DIR)/DigitalSource.o \
	 $(OBJ_DIR)/Servo.o $(OBJ_DIR)/SensorBase.o

PROJECT_TARGETS := $(OBJ_DIR)/WPILib.a

SUB_OBJECTS :=
SUB_TARGETS :=
endif
ifeq ($(BUILD_SPEC),PPC860sfgnu)
SUBDIRS :=
OBJECTS := $(OBJ_DIR)/PCVideoServer.o $(OBJ_DIR)/Gyro.o $(OBJ_DIR)/Timer.o \
	 $(OBJ_DIR)/DigitalInput.o $(OBJ_DIR)/Utility.o $(OBJ_DIR)/Jaguar.o \
	 $(OBJ_DIR)/Relay.o $(OBJ_DIR)/Compressor.o $(OBJ_DIR)/AnalogChannel.o \
	 $(OBJ_DIR)/Task.o $(OBJ_DIR)/HiTechnicCompass.o $(OBJ_DIR)/AnalogModule.o \
	 $(OBJ_DIR)/SerialPort.o $(OBJ_DIR)/Error.o $(OBJ_DIR)/FrcError.o \
	 $(OBJ_DIR)/ErrorBase.o $(OBJ_DIR)/Ultrasonic.o $(OBJ_DIR)/AnalogTriggerOutput.o \
	 $(OBJ_DIR)/AnalogTrigger.o $(OBJ_DIR)/AxisCamera.o $(OBJ_DIR)/Watchdog.o \
	 $(OBJ_DIR)/Solenoid.o $(OBJ_DIR)/PIDController.o $(OBJ_DIR)/Dashboard.o \
	 $(OBJ_DIR)/Counter.o $(OBJ_DIR)/SimpleRobot.o $(OBJ_DIR)/Accelerometer.o \
	 $(OBJ_DIR)/DigitalOutput.o $(OBJ_DIR)/BaeUtilities.o $(OBJ_DIR)/PWM.o \
	 $(OBJ_DIR)/Encoder.o $(OBJ_DIR)/VisionAPI.o $(OBJ_DIR)/DriverStation.o \
	 $(OBJ_DIR)/Module.o $(OBJ_DIR)/RobotDrive.o $(OBJ_DIR)/TrackAPI.o \
	 $(OBJ_DIR)/IterativeRobot.o $(OBJ_DIR)/I2C.o $(OBJ_DIR)/DigitalModule.o \
	 $(OBJ_DIR)/Notifier.o $(OBJ_DIR)/InterruptableSensorBase.o $(OBJ_DIR)/Resource.o \
	 $(OBJ_DIR)/Synchronized.o $(OBJ_DIR)/Joystick.o $(OBJ_DIR)/Victor.o \
	 $(OBJ_DIR)/RobotBase.o $(OBJ_DIR)/GearTooth.o $(OBJ_DIR)/DigitalSource.o \
	 $(OBJ_DIR)/Servo.o $(OBJ_DIR)/SensorBase.o

PROJECT_TARGETS := $(OBJ_DIR)/WPILib.a

SUB_OBJECTS :=
SUB_TARGETS :=
endif
ifeq ($(BUILD_SPEC),SIMLINUXdiab)
SUBDIRS :=
OBJECTS := $(OBJ_DIR)/PCVideoServer.o $(OBJ_DIR)/Gyro.o $(OBJ_DIR)/Timer.o \
	 $(OBJ_DIR)/DigitalInput.o $(OBJ_DIR)/Utility.o $(OBJ_DIR)/Jaguar.o \
	 $(OBJ_DIR)/Relay.o $(OBJ_DIR)/Compressor.o $(OBJ_DIR)/AnalogChannel.o \
	 $(OBJ_DIR)/Task.o $(OBJ_DIR)/HiTechnicCompass.o $(OBJ_DIR)/AnalogModule.o \
	 $(OBJ_DIR)/SerialPort.o $(OBJ_DIR)/Error.o $(OBJ_DIR)/FrcError.o \
	 $(OBJ_DIR)/ErrorBase.o $(OBJ_DIR)/Ultrasonic.o $(OBJ_DIR)/AnalogTriggerOutput.o \
	 $(OBJ_DIR)/AnalogTrigger.o $(OBJ_DIR)/AxisCamera.o $(OBJ_DIR)/Watchdog.o \
	 $(OBJ_DIR)/Solenoid.o $(OBJ_DIR)/PIDController.o $(OBJ_DIR)/Dashboard.o \
	 $(OBJ_DIR)/Counter.o $(OBJ_DIR)/SimpleRobot.o $(OBJ_DIR)/Accelerometer.o \
	 $(OBJ_DIR)/DigitalOutput.o $(OBJ_DIR)/BaeUtilities.o $(OBJ_DIR)/PWM.o \
	 $(OBJ_DIR)/Encoder.o $(OBJ_DIR)/VisionAPI.o $(OBJ_DIR)/DriverStation.o \
	 $(OBJ_DIR)/Module.o $(OBJ_DIR)/RobotDrive.o $(OBJ_DIR)/TrackAPI.o \
	 $(OBJ_DIR)/IterativeRobot.o $(OBJ_DIR)/I2C.o $(OBJ_DIR)/DigitalModule.o \
	 $(OBJ_DIR)/Notifier.o $(OBJ_DIR)/InterruptableSensorBase.o $(OBJ_DIR)/Resource.o \
	 $(OBJ_DIR)/Synchronized.o $(OBJ_DIR)/Joystick.o $(OBJ_DIR)/Victor.o \
	 $(OBJ_DIR)/RobotBase.o $(OBJ_DIR)/GearTooth.o $(OBJ_DIR)/DigitalSource.o \
	 $(OBJ_DIR)/Servo.o $(OBJ_DIR)/SensorBase.o

PROJECT_TARGETS := $(OBJ_DIR)/WPILib.a

SUB_OBJECTS :=
SUB_TARGETS :=
endif
ifeq ($(BUILD_SPEC),SIMLINUXgnu)
SUBDIRS :=
OBJECTS := $(OBJ_DIR)/PCVideoServer.o $(OBJ_DIR)/Gyro.o $(OBJ_DIR)/Timer.o \
	 $(OBJ_DIR)/DigitalInput.o $(OBJ_DIR)/Utility.o $(OBJ_DIR)/Jaguar.o \
	 $(OBJ_DIR)/Relay.o $(OBJ_DIR)/Compressor.o $(OBJ_DIR)/AnalogChannel.o \
	 $(OBJ_DIR)/Task.o $(OBJ_DIR)/HiTechnicCompass.o $(OBJ_DIR)/AnalogModule.o \
	 $(OBJ_DIR)/SerialPort.o $(OBJ_DIR)/Error.o $(OBJ_DIR)/FrcError.o \
	 $(OBJ_DIR)/ErrorBase.o $(OBJ_DIR)/Ultrasonic.o $(OBJ_DIR)/AnalogTriggerOutput.o \
	 $(OBJ_DIR)/AnalogTrigger.o $(OBJ_DIR)/AxisCamera.o $(OBJ_DIR)/Watchdog.o \
	 $(OBJ_DIR)/Solenoid.o $(OBJ_DIR)/PIDController.o $(OBJ_DIR)/Dashboard.o \
	 $(OBJ_DIR)/Counter.o $(OBJ_DIR)/SimpleRobot.o $(OBJ_DIR)/Accelerometer.o \
	 $(OBJ_DIR)/DigitalOutput.o $(OBJ_DIR)/BaeUtilities.o $(OBJ_DIR)/PWM.o \
	 $(OBJ_DIR)/Encoder.o $(OBJ_DIR)/VisionAPI.o $(OBJ_DIR)/DriverStation.o \
	 $(OBJ_DIR)/Module.o $(OBJ_DIR)/RobotDrive.o $(OBJ_DIR)/TrackAPI.o \
	 $(OBJ_DIR)/IterativeRobot.o $(OBJ_DIR)/I2C.o $(OBJ_DIR)/DigitalModule.o \
	 $(OBJ_DIR)/Notifier.o $(OBJ_DIR)/InterruptableSensorBase.o $(OBJ_DIR)/Resource.o \
	 $(OBJ_DIR)/Synchronized.o $(OBJ_DIR)/Joystick.o $(OBJ_DIR)/Victor.o \
	 $(OBJ_DIR)/RobotBase.o $(OBJ_DIR)/GearTooth.o $(OBJ_DIR)/DigitalSource.o \
	 $(OBJ_DIR)/Servo.o $(OBJ_DIR)/SensorBase.o

PROJECT_TARGETS := $(OBJ_DIR)/WPILib.a

SUB_OBJECTS :=
SUB_TARGETS :=
endif
ifeq ($(BUILD_SPEC),SIMNTdiab)
SUBDIRS :=
OBJECTS := $(OBJ_DIR)/PCVideoServer.o $(OBJ_DIR)/Gyro.o $(OBJ_DIR)/Timer.o \
	 $(OBJ_DIR)/DigitalInput.o $(OBJ_DIR)/Utility.o $(OBJ_DIR)/Jaguar.o \
	 $(OBJ_DIR)/Relay.o $(OBJ_DIR)/Compressor.o $(OBJ_DIR)/AnalogChannel.o \
	 $(OBJ_DIR)/Task.o $(OBJ_DIR)/HiTechnicCompass.o $(OBJ_DIR)/AnalogModule.o \
	 $(OBJ_DIR)/SerialPort.o $(OBJ_DIR)/Error.o $(OBJ_DIR)/FrcError.o \
	 $(OBJ_DIR)/ErrorBase.o $(OBJ_DIR)/Ultrasonic.o $(OBJ_DIR)/AnalogTriggerOutput.o \
	 $(OBJ_DIR)/AnalogTrigger.o $(OBJ_DIR)/AxisCamera.o $(OBJ_DIR)/Watchdog.o \
	 $(OBJ_DIR)/Solenoid.o $(OBJ_DIR)/PIDController.o $(OBJ_DIR)/Dashboard.o \
	 $(OBJ_DIR)/Counter.o $(OBJ_DIR)/SimpleRobot.o $(OBJ_DIR)/Accelerometer.o \
	 $(OBJ_DIR)/DigitalOutput.o $(OBJ_DIR)/BaeUtilities.o $(OBJ_DIR)/PWM.o \
	 $(OBJ_DIR)/Encoder.o $(OBJ_DIR)/VisionAPI.o $(OBJ_DIR)/DriverStation.o \
	 $(OBJ_DIR)/Module.o $(OBJ_DIR)/RobotDrive.o $(OBJ_DIR)/TrackAPI.o \
	 $(OBJ_DIR)/IterativeRobot.o $(OBJ_DIR)/I2C.o $(OBJ_DIR)/DigitalModule.o \
	 $(OBJ_DIR)/Notifier.o $(OBJ_DIR)/InterruptableSensorBase.o $(OBJ_DIR)/Resource.o \
	 $(OBJ_DIR)/Synchronized.o $(OBJ_DIR)/Joystick.o $(OBJ_DIR)/Victor.o \
	 $(OBJ_DIR)/RobotBase.o $(OBJ_DIR)/GearTooth.o $(OBJ_DIR)/DigitalSource.o \
	 $(OBJ_DIR)/Servo.o $(OBJ_DIR)/SensorBase.o

PROJECT_TARGETS := $(OBJ_DIR)/WPILib.a

SUB_OBJECTS :=
SUB_TARGETS :=
endif
ifeq ($(BUILD_SPEC),SIMNTgnu)
SUBDIRS :=
OBJECTS := $(OBJ_DIR)/PCVideoServer.o $(OBJ_DIR)/Gyro.o $(OBJ_DIR)/Timer.o \
	 $(OBJ_DIR)/DigitalInput.o $(OBJ_DIR)/Utility.o $(OBJ_DIR)/Jaguar.o \
	 $(OBJ_DIR)/Relay.o $(OBJ_DIR)/Compressor.o $(OBJ_DIR)/AnalogChannel.o \
	 $(OBJ_DIR)/Task.o $(OBJ_DIR)/HiTechnicCompass.o $(OBJ_DIR)/AnalogModule.o \
	 $(OBJ_DIR)/SerialPort.o $(OBJ_DIR)/Error.o $(OBJ_DIR)/FrcError.o \
	 $(OBJ_DIR)/ErrorBase.o $(OBJ_DIR)/Ultrasonic.o $(OBJ_DIR)/AnalogTriggerOutput.o \
	 $(OBJ_DIR)/AnalogTrigger.o $(OBJ_DIR)/AxisCamera.o $(OBJ_DIR)/Watchdog.o \
	 $(OBJ_DIR)/Solenoid.o $(OBJ_DIR)/PIDController.o $(OBJ_DIR)/Dashboard.o \
	 $(OBJ_DIR)/Counter.o $(OBJ_DIR)/SimpleRobot.o $(OBJ_DIR)/Accelerometer.o \
	 $(OBJ_DIR)/DigitalOutput.o $(OBJ_DIR)/BaeUtilities.o $(OBJ_DIR)/PWM.o \
	 $(OBJ_DIR)/Encoder.o $(OBJ_DIR)/VisionAPI.o $(OBJ_DIR)/DriverStation.o \
	 $(OBJ_DIR)/Module.o $(OBJ_DIR)/RobotDrive.o $(OBJ_DIR)/TrackAPI.o \
	 $(OBJ_DIR)/IterativeRobot.o $(OBJ_DIR)/I2C.o $(OBJ_DIR)/DigitalModule.o \
	 $(OBJ_DIR)/Notifier.o $(OBJ_DIR)/InterruptableSensorBase.o $(OBJ_DIR)/Resource.o \
	 $(OBJ_DIR)/Synchronized.o $(OBJ_DIR)/Joystick.o $(OBJ_DIR)/Victor.o \
	 $(OBJ_DIR)/RobotBase.o $(OBJ_DIR)/GearTooth.o $(OBJ_DIR)/DigitalSource.o \
	 $(OBJ_DIR)/Servo.o $(OBJ_DIR)/SensorBase.o

PROJECT_TARGETS := $(OBJ_DIR)/WPILib.a

SUB_OBJECTS :=
SUB_TARGETS :=
endif
ifeq ($(BUILD_SPEC),SIMSPARCSOLARISdiab)
SUBDIRS :=
OBJECTS := $(OBJ_DIR)/PCVideoServer.o $(OBJ_DIR)/Gyro.o $(OBJ_DIR)/Timer.o \
	 $(OBJ_DIR)/DigitalInput.o $(OBJ_DIR)/Utility.o $(OBJ_DIR)/Jaguar.o \
	 $(OBJ_DIR)/Relay.o $(OBJ_DIR)/Compressor.o $(OBJ_DIR)/AnalogChannel.o \
	 $(OBJ_DIR)/Task.o $(OBJ_DIR)/HiTechnicCompass.o $(OBJ_DIR)/AnalogModule.o \
	 $(OBJ_DIR)/SerialPort.o $(OBJ_DIR)/Error.o $(OBJ_DIR)/FrcError.o \
	 $(OBJ_DIR)/ErrorBase.o $(OBJ_DIR)/Ultrasonic.o $(OBJ_DIR)/AnalogTriggerOutput.o \
	 $(OBJ_DIR)/AnalogTrigger.o $(OBJ_DIR)/AxisCamera.o $(OBJ_DIR)/Watchdog.o \
	 $(OBJ_DIR)/Solenoid.o $(OBJ_DIR)/PIDController.o $(OBJ_DIR)/Dashboard.o \
	 $(OBJ_DIR)/Counter.o $(OBJ_DIR)/SimpleRobot.o $(OBJ_DIR)/Accelerometer.o \
	 $(OBJ_DIR)/DigitalOutput.o $(OBJ_DIR)/BaeUtilities.o $(OBJ_DIR)/PWM.o \
	 $(OBJ_DIR)/Encoder.o $(OBJ_DIR)/VisionAPI.o $(OBJ_DIR)/DriverStation.o \
	 $(OBJ_DIR)/Module.o $(OBJ_DIR)/RobotDrive.o $(OBJ_DIR)/TrackAPI.o \
	 $(OBJ_DIR)/IterativeRobot.o $(OBJ_DIR)/I2C.o $(OBJ_DIR)/DigitalModule.o \
	 $(OBJ_DIR)/Notifier.o $(OBJ_DIR)/InterruptableSensorBase.o $(OBJ_DIR)/Resource.o \
	 $(OBJ_DIR)/Synchronized.o $(OBJ_DIR)/Joystick.o $(OBJ_DIR)/Victor.o \
	 $(OBJ_DIR)/RobotBase.o $(OBJ_DIR)/GearTooth.o $(OBJ_DIR)/DigitalSource.o \
	 $(OBJ_DIR)/Servo.o $(OBJ_DIR)/SensorBase.o

PROJECT_TARGETS := $(OBJ_DIR)/WPILib.a

SUB_OBJECTS :=
SUB_TARGETS :=
endif
ifeq ($(BUILD_SPEC),SIMSPARCSOLARISgnu)
SUBDIRS :=
OBJECTS := $(OBJ_DIR)/PCVideoServer.o $(OBJ_DIR)/Gyro.o $(OBJ_DIR)/Timer.o \
	 $(OBJ_DIR)/DigitalInput.o $(OBJ_DIR)/Utility.o $(OBJ_DIR)/Jaguar.o \
	 $(OBJ_DIR)/Relay.o $(OBJ_DIR)/Compressor.o $(OBJ_DIR)/AnalogChannel.o \
	 $(OBJ_DIR)/Task.o $(OBJ_DIR)/HiTechnicCompass.o $(OBJ_DIR)/AnalogModule.o \
	 $(OBJ_DIR)/SerialPort.o $(OBJ_DIR)/Error.o $(OBJ_DIR)/FrcError.o \
	 $(OBJ_DIR)/ErrorBase.o $(OBJ_DIR)/Ultrasonic.o $(OBJ_DIR)/AnalogTriggerOutput.o \
	 $(OBJ_DIR)/AnalogTrigger.o $(OBJ_DIR)/AxisCamera.o $(OBJ_DIR)/Watchdog.o \
	 $(OBJ_DIR)/Solenoid.o $(OBJ_DIR)/PIDController.o $(OBJ_DIR)/Dashboard.o \
	 $(OBJ_DIR)/Counter.o $(OBJ_DIR)/SimpleRobot.o $(OBJ_DIR)/Accelerometer.o \
	 $(OBJ_DIR)/DigitalOutput.o $(OBJ_DIR)/BaeUtilities.o $(OBJ_DIR)/PWM.o \
	 $(OBJ_DIR)/Encoder.o $(OBJ_DIR)/VisionAPI.o $(OBJ_DIR)/DriverStation.o \
	 $(OBJ_DIR)/Module.o $(OBJ_DIR)/RobotDrive.o $(OBJ_DIR)/TrackAPI.o \
	 $(OBJ_DIR)/IterativeRobot.o $(OBJ_DIR)/I2C.o $(OBJ_DIR)/DigitalModule.o \
	 $(OBJ_DIR)/Notifier.o $(OBJ_DIR)/InterruptableSensorBase.o $(OBJ_DIR)/Resource.o \
	 $(OBJ_DIR)/Synchronized.o $(OBJ_DIR)/Joystick.o $(OBJ_DIR)/Victor.o \
	 $(OBJ_DIR)/RobotBase.o $(OBJ_DIR)/GearTooth.o $(OBJ_DIR)/DigitalSource.o \
	 $(OBJ_DIR)/Servo.o $(OBJ_DIR)/SensorBase.o

PROJECT_TARGETS := $(OBJ_DIR)/WPILib.a

SUB_OBJECTS :=
SUB_TARGETS :=
endif

PROJECT_TYPE = DKM
DEFINES = 
EXPAND_DBG = 0

ifeq ($(BUILD_SPEC),PPC32diab)
VX_CPU_FAMILY = ppc
CPU = PPC32
TOOL_FAMILY = diab
TOOL = diab
TOOL_PATH = 
CC_ARCH_SPEC = -tPPCFH:vxworks63 -Xstmw-slow -DPPC32_fp60x
LIBPATH = 
LIBS = 

IDE_INCLUDES = -I$(WIND_BASE)/target/h -I$(WIND_BASE)/target/h/wrn/coreip 

IDE_LIBRARIES = 
endif

ifeq ($(BUILD_SPEC),PPC32gnu)
VX_CPU_FAMILY = ppc
CPU = PPC32
TOOL_FAMILY = gnu
TOOL = gnu
TOOL_PATH = 
CC_ARCH_SPEC = -mhard-float -mstrict-align -mno-implicit-fp -DPPC32_fp60x
LIBPATH = 
LIBS = 

IDE_INCLUDES = -I$(WIND_BASE)/target/h -I$(WIND_BASE)/target/h/wrn/coreip 

IDE_LIBRARIES = 
endif

ifeq ($(BUILD_SPEC),PPC32sfdiab)
VX_CPU_FAMILY = ppc
CPU = PPC32
TOOL_FAMILY = diab
TOOL = sfdiab
TOOL_PATH = 
CC_ARCH_SPEC = -tPPCFS:vxworks63
LIBPATH = 
LIBS = 

IDE_INCLUDES = -I$(WIND_BASE)/target/h -I$(WIND_BASE)/target/h/wrn/coreip 

IDE_LIBRARIES = 
endif

ifeq ($(BUILD_SPEC),PPC32sfgnu)
VX_CPU_FAMILY = ppc
CPU = PPC32
TOOL_FAMILY = gnu
TOOL = sfgnu
TOOL_PATH = 
CC_ARCH_SPEC = -msoft-float -mstrict-align
LIBPATH = 
LIBS = 

IDE_INCLUDES = -I$(WIND_BASE)/target/h -I$(WIND_BASE)/target/h/wrn/coreip 

IDE_LIBRARIES = 
endif

ifeq ($(BUILD_SPEC),PPC403diab)
VX_CPU_FAMILY = ppc
CPU = PPC403
TOOL_FAMILY = diab
TOOL = diab
TOOL_PATH = 
CC_ARCH_SPEC = -tPPC403FS:vxworks63
LIBPATH = 
LIBS = 

IDE_INCLUDES = -I$(WIND_BASE)/target/h -I$(WIND_BASE)/target/h/wrn/coreip 

IDE_LIBRARIES = 
endif

ifeq ($(BUILD_SPEC),PPC403gnu)
VX_CPU_FAMILY = ppc
CPU = PPC403
TOOL_FAMILY = gnu
TOOL = gnu
TOOL_PATH = 
CC_ARCH_SPEC = -mcpu=403 -mstrict-align -msoft-float
LIBPATH = 
LIBS = 

IDE_INCLUDES = -I$(WIND_BASE)/target/h -I$(WIND_BASE)/target/h/wrn/coreip 

IDE_LIBRARIES = 
endif

ifeq ($(BUILD_SPEC),PPC405diab)
VX_CPU_FAMILY = ppc
CPU = PPC405
TOOL_FAMILY = diab
TOOL = diab
TOOL_PATH = 
CC_ARCH_SPEC = -tPPC405FS:vxworks63
LIBPATH = 
LIBS = 

IDE_INCLUDES = -I$(WIND_BASE)/target/h -I$(WIND_BASE)/target/h/wrn/coreip 

IDE_LIBRARIES = 
endif

ifeq ($(BUILD_SPEC),PPC405gnu)
VX_CPU_FAMILY = ppc
CPU = PPC405
TOOL_FAMILY = gnu
TOOL = gnu
TOOL_PATH = 
CC_ARCH_SPEC = -mcpu=405 -mstrict-align -msoft-float
LIBPATH = 
LIBS = 

IDE_INCLUDES = -I$(WIND_BASE)/target/h -I$(WIND_BASE)/target/h/wrn/coreip 

IDE_LIBRARIES = 
endif

ifeq ($(BUILD_SPEC),PPC405sfdiab)
VX_CPU_FAMILY = ppc
CPU = PPC405
TOOL_FAMILY = diab
TOOL = sfdiab
TOOL_PATH = 
CC_ARCH_SPEC = -tPPC405FS:vxworks63
LIBPATH = 
LIBS = 

IDE_INCLUDES = -I$(WIND_BASE)/target/h -I$(WIND_BASE)/target/h/wrn/coreip 

IDE_LIBRARIES = 
endif

ifeq ($(BUILD_SPEC),PPC405sfgnu)
VX_CPU_FAMILY = ppc
CPU = PPC405
TOOL_FAMILY = gnu
TOOL = sfgnu
TOOL_PATH = 
CC_ARCH_SPEC = -mcpu=405 -mstrict-align -msoft-float
LIBPATH = 
LIBS = 

IDE_INCLUDES = -I$(WIND_BASE)/target/h -I$(WIND_BASE)/target/h/wrn/coreip 

IDE_LIBRARIES = 
endif

ifeq ($(BUILD_SPEC),PPC440diab)
VX_CPU_FAMILY = ppc
CPU = PPC440
TOOL_FAMILY = diab
TOOL = diab
TOOL_PATH = 
CC_ARCH_SPEC = -tPPC440FH:vxworks63
LIBPATH = 
LIBS = 

IDE_INCLUDES = -I$(WIND_BASE)/target/h -I$(WIND_BASE)/target/h/wrn/coreip 

IDE_LIBRARIES = 
endif

ifeq ($(BUILD_SPEC),PPC440gnu)
VX_CPU_FAMILY = ppc
CPU = PPC440
TOOL_FAMILY = gnu
TOOL = gnu
TOOL_PATH = 
CC_ARCH_SPEC = -mcpu=440 -mstrict-align -msoft-float
LIBPATH = 
LIBS = 

IDE_INCLUDES = -I$(WIND_BASE)/target/h -I$(WIND_BASE)/target/h/wrn/coreip 

IDE_LIBRARIES = 
endif

ifeq ($(BUILD_SPEC),PPC440sfdiab)
VX_CPU_FAMILY = ppc
CPU = PPC440
TOOL_FAMILY = diab
TOOL = sfdiab
TOOL_PATH = 
CC_ARCH_SPEC = -tPPC440FS:vxworks63
LIBPATH = 
LIBS = 

IDE_INCLUDES = -I$(WIND_BASE)/target/h -I$(WIND_BASE)/target/h/wrn/coreip 

IDE_LIBRARIES = 
endif

ifeq ($(BUILD_SPEC),PPC440sfgnu)
VX_CPU_FAMILY = ppc
CPU = PPC440
TOOL_FAMILY = gnu
TOOL = sfgnu
TOOL_PATH = 
CC_ARCH_SPEC = -mcpu=440 -mstrict-align -msoft-float
LIBPATH = 
LIBS = 

IDE_INCLUDES = -I$(WIND_BASE)/target/h -I$(WIND_BASE)/target/h/wrn/coreip 

IDE_LIBRARIES = 
endif

ifeq ($(BUILD_SPEC),PPC603diab)
VX_CPU_FAMILY = ppc
CPU = PPC603
TOOL_FAMILY = diab
TOOL = diab
TOOL_PATH = 
CC_ARCH_SPEC = -tPPC603FH:vxworks63
LIBPATH = 
LIBS = 

IDE_INCLUDES = -I$(WIND_BASE)/target/h -I$(WIND_BASE)/target/h/wrn/coreip 

IDE_LIBRARIES = 
endif

ifeq ($(BUILD_SPEC),PPC603gnu)
VX_CPU_FAMILY = ppc
CPU = PPC603
TOOL_FAMILY = gnu
TOOL = gnu
TOOL_PATH = 
CC_ARCH_SPEC = -mcpu=603 -mstrict-align -mno-implicit-fp -mlongcall
LIBPATH = 
LIBS = 

IDE_INCLUDES = -I$(WIND_BASE)/target/h -I$(WIND_BASE)/target/h/wrn/coreip 

IDE_LIBRARIES = 
endif

ifeq ($(BUILD_SPEC),PPC604diab)
VX_CPU_FAMILY = ppc
CPU = PPC604
TOOL_FAMILY = diab
TOOL = diab
TOOL_PATH = 
CC_ARCH_SPEC = -tPPC604FH:vxworks63
LIBPATH = 
LIBS = 

IDE_INCLUDES = -I$(WIND_BASE)/target/h -I$(WIND_BASE)/target/h/wrn/coreip 

IDE_LIBRARIES = 
endif

ifeq ($(BUILD_SPEC),PPC604gnu)
VX_CPU_FAMILY = ppc
CPU = PPC604
TOOL_FAMILY = gnu
TOOL = gnu
TOOL_PATH = 
CC_ARCH_SPEC = -mcpu=604 -mstrict-align -mno-implicit-fp
LIBPATH = 
LIBS = 

IDE_INCLUDES = -I$(WIND_BASE)/target/h -I$(WIND_BASE)/target/h/wrn/coreip 

IDE_LIBRARIES = 
endif

ifeq ($(BUILD_SPEC),PPC85XXdiab)
VX_CPU_FAMILY = ppc
CPU = PPC85XX
TOOL_FAMILY = diab
TOOL = diab
TOOL_PATH = 
CC_ARCH_SPEC = -tPPCE500FS:vxworks63
LIBPATH = 
LIBS = 

IDE_INCLUDES = -I$(WIND_BASE)/target/h -I$(WIND_BASE)/target/h/wrn/coreip 

IDE_LIBRARIES = 
endif

ifeq ($(BUILD_SPEC),PPC85XXgnu)
VX_CPU_FAMILY = ppc
CPU = PPC85XX
TOOL_FAMILY = gnu
TOOL = gnu
TOOL_PATH = 
CC_ARCH_SPEC = -mcpu=8540 -mstrict-align -msoft-float -mabi=no-spe
LIBPATH = 
LIBS = 

IDE_INCLUDES = -I$(WIND_BASE)/target/h -I$(WIND_BASE)/target/h/wrn/coreip 

IDE_LIBRARIES = 
endif

ifeq ($(BUILD_SPEC),PPC85XXsfdiab)
VX_CPU_FAMILY = ppc
CPU = PPC85XX
TOOL_FAMILY = diab
TOOL = sfdiab
TOOL_PATH = 
CC_ARCH_SPEC = -tPPCE500FS:vxworks63
LIBPATH = 
LIBS = 

IDE_INCLUDES = -I$(WIND_BASE)/target/h -I$(WIND_BASE)/target/h/wrn/coreip 

IDE_LIBRARIES = 
endif

ifeq ($(BUILD_SPEC),PPC85XXsfgnu)
VX_CPU_FAMILY = ppc
CPU = PPC85XX
TOOL_FAMILY = gnu
TOOL = sfgnu
TOOL_PATH = 
CC_ARCH_SPEC = -mcpu=8540 -mstrict-align -msoft-float -mabi=no-spe
LIBPATH = 
LIBS = 

IDE_INCLUDES = -I$(WIND_BASE)/target/h -I$(WIND_BASE)/target/h/wrn/coreip 

IDE_LIBRARIES = 
endif

ifeq ($(BUILD_SPEC),PPC860sfdiab)
VX_CPU_FAMILY = ppc
CPU = PPC860
TOOL_FAMILY = diab
TOOL = sfdiab
TOOL_PATH = 
CC_ARCH_SPEC = -tPPC860FS:vxworks63
LIBPATH = 
LIBS = 

IDE_INCLUDES = -I$(WIND_BASE)/target/h -I$(WIND_BASE)/target/h/wrn/coreip 

IDE_LIBRARIES = 
endif

ifeq ($(BUILD_SPEC),PPC860sfgnu)
VX_CPU_FAMILY = ppc
CPU = PPC860
TOOL_FAMILY = gnu
TOOL = sfgnu
TOOL_PATH = 
CC_ARCH_SPEC = -mcpu=860 -mstrict-align -msoft-float
LIBPATH = 
LIBS = 

IDE_INCLUDES = -I$(WIND_BASE)/target/h -I$(WIND_BASE)/target/h/wrn/coreip 

IDE_LIBRARIES = 
endif

ifeq ($(BUILD_SPEC),SIMLINUXdiab)
VX_CPU_FAMILY = simlinux
CPU = SIMLINUX
TOOL_FAMILY = diab
TOOL = diab
TOOL_PATH = 
CC_ARCH_SPEC = -tX86LH:vxworks63
LIBPATH = 
LIBS = 

IDE_INCLUDES = -I$(WIND_BASE)/target/h -I$(WIND_BASE)/target/h/wrn/coreip 

IDE_LIBRARIES = 
endif

ifeq ($(BUILD_SPEC),SIMLINUXgnu)
VX_CPU_FAMILY = simlinux
CPU = SIMLINUX
TOOL_FAMILY = gnu
TOOL = gnu
TOOL_PATH = 
CC_ARCH_SPEC = -mtune=i486 -march=i486
LIBPATH = 
LIBS = 

IDE_INCLUDES = -I$(WIND_BASE)/target/h -I$(WIND_BASE)/target/h/wrn/coreip 

IDE_LIBRARIES = 
endif

ifeq ($(BUILD_SPEC),SIMNTdiab)
VX_CPU_FAMILY = simpc
CPU = SIMNT
TOOL_FAMILY = diab
TOOL = diab
TOOL_PATH = 
CC_ARCH_SPEC = -tX86LH:vxworks63
LIBPATH = 
LIBS = 

IDE_INCLUDES = -I$(WIND_BASE)/target/h -I$(WIND_BASE)/target/h/wrn/coreip 

IDE_LIBRARIES = 
endif

ifeq ($(BUILD_SPEC),SIMNTgnu)
VX_CPU_FAMILY = simpc
CPU = SIMNT
TOOL_FAMILY = gnu
TOOL = gnu
TOOL_PATH = 
CC_ARCH_SPEC = -mtune=i486 -march=i486
LIBPATH = 
LIBS = 

IDE_INCLUDES = -I$(WIND_BASE)/target/h -I$(WIND_BASE)/target/h/wrn/coreip 

IDE_LIBRARIES = 
endif

ifeq ($(BUILD_SPEC),SIMSPARCSOLARISdiab)
VX_CPU_FAMILY = simso
CPU = SIMSPARCSOLARIS
TOOL_FAMILY = diab
TOOL = diab
TOOL_PATH = 
CC_ARCH_SPEC = -tSPARCFH:vxworks63
LIBPATH = 
LIBS = 

IDE_INCLUDES = -I$(WIND_BASE)/target/h -I$(WIND_BASE)/target/h/wrn/coreip 

IDE_LIBRARIES = 
endif

ifeq ($(BUILD_SPEC),SIMSPARCSOLARISgnu)
VX_CPU_FAMILY = simso
CPU = SIMSPARCSOLARIS
TOOL_FAMILY = gnu
TOOL = gnu
TOOL_PATH = 
CC_ARCH_SPEC = 
LIBPATH = 
LIBS = 

IDE_INCLUDES = -I$(WIND_BASE)/target/h -I$(WIND_BASE)/target/h/wrn/coreip 

IDE_LIBRARIES = 
endif


ifeq ($(BUILD_SPEC),PPC32diab)
ifeq ($(DEBUG_MODE),1)
DEBUGFLAGS_C-Compiler = -g
else
DEBUGFLAGS_C-Compiler = -XO -Xsize-opt
endif
$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c
	$(TRACE_FLAG)echo "building $@"; $(TOOL_PATH)dcc $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -W:c:,-Xclib-optim-off -Xansi -Xlocal-data-area-static-only -Xforce-declarations  -Xmake-dependency=0xd $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"

endif
ifeq ($(BUILD_SPEC),PPC32gnu)
ifeq ($(DEBUG_MODE),1)
DEBUGFLAGS_C-Compiler = -g
else
DEBUGFLAGS_C-Compiler = -O2 -fstrength-reduce -fno-builtin
endif
$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c
	$(TRACE_FLAG)echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -ansi  -Wall  -MD -MP $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"

endif
ifeq ($(BUILD_SPEC),PPC32sfdiab)
ifeq ($(DEBUG_MODE),1)
DEBUGFLAGS_C-Compiler = -g
else
DEBUGFLAGS_C-Compiler = -XO -Xsize-opt
endif
$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c
	$(TRACE_FLAG)echo "building $@"; $(TOOL_PATH)dcc $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -W:c:,-Xclib-optim-off -Xansi -Xlocal-data-area-static-only -Xstsw-slow -Xforce-declarations  -Xmake-dependency=0xd $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"

endif
ifeq ($(BUILD_SPEC),PPC32sfgnu)
ifeq ($(DEBUG_MODE),1)
DEBUGFLAGS_C-Compiler = -g
else
DEBUGFLAGS_C-Compiler = -O2 -fstrength-reduce -fno-builtin
endif
$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c
	$(TRACE_FLAG)echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -ansi  -Wall  -MD -MP $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"

endif
ifeq ($(BUILD_SPEC),PPC403diab)
ifeq ($(DEBUG_MODE),1)
DEBUGFLAGS_C-Compiler = -g
else
DEBUGFLAGS_C-Compiler = -XO -Xsize-opt
endif
$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c
	$(TRACE_FLAG)echo "building $@"; $(TOOL_PATH)dcc $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -W:c:,-Xclib-optim-off -Xansi -Xlocal-data-area-static-only -Xforce-declarations  -Xmake-dependency=0xd $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"

endif
ifeq ($(BUILD_SPEC),PPC403gnu)
ifeq ($(DEBUG_MODE),1)
DEBUGFLAGS_C-Compiler = -g
else
DEBUGFLAGS_C-Compiler = -O2 -fstrength-reduce -fno-builtin
endif
$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c
	$(TRACE_FLAG)echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -ansi  -Wall  -MD -MP $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"

endif
ifeq ($(BUILD_SPEC),PPC405diab)
ifeq ($(DEBUG_MODE),1)
DEBUGFLAGS_C-Compiler = -g
else
DEBUGFLAGS_C-Compiler = -XO -Xsize-opt
endif
$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c
	$(TRACE_FLAG)echo "building $@"; $(TOOL_PATH)dcc $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -W:c:,-Xclib-optim-off -Xansi -Xlocal-data-area-static-only -Xforce-declarations  -Xmake-dependency=0xd $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"

endif
ifeq ($(BUILD_SPEC),PPC405gnu)
ifeq ($(DEBUG_MODE),1)
DEBUGFLAGS_C-Compiler = -g
else
DEBUGFLAGS_C-Compiler = -O2 -fstrength-reduce -fno-builtin
endif
$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c
	$(TRACE_FLAG)echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -ansi  -Wall  -MD -MP $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"

endif
ifeq ($(BUILD_SPEC),PPC405sfdiab)
ifeq ($(DEBUG_MODE),1)
DEBUGFLAGS_C-Compiler = -g
else
DEBUGFLAGS_C-Compiler = -XO -Xsize-opt
endif
$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c
	$(TRACE_FLAG)echo "building $@"; $(TOOL_PATH)dcc $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -W:c:,-Xclib-optim-off -Xansi -Xlocal-data-area-static-only -Xforce-declarations  -Xmake-dependency=0xd $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"

endif
ifeq ($(BUILD_SPEC),PPC405sfgnu)
ifeq ($(DEBUG_MODE),1)
DEBUGFLAGS_C-Compiler = -g
else
DEBUGFLAGS_C-Compiler = -O2 -fstrength-reduce -fno-builtin
endif
$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c
	$(TRACE_FLAG)echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -ansi  -Wall  -MD -MP $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"

endif
ifeq ($(BUILD_SPEC),PPC440diab)
ifeq ($(DEBUG_MODE),1)
DEBUGFLAGS_C-Compiler = -g
else
DEBUGFLAGS_C-Compiler = -XO -Xsize-opt
endif
$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c
	$(TRACE_FLAG)echo "building $@"; $(TOOL_PATH)dcc $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -W:c:,-Xclib-optim-off -Xansi -Xlocal-data-area-static-only -Xforce-declarations  -Xmake-dependency=0xd $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"

endif
ifeq ($(BUILD_SPEC),PPC440gnu)
ifeq ($(DEBUG_MODE),1)
DEBUGFLAGS_C-Compiler = -g
else
DEBUGFLAGS_C-Compiler = -O2 -fstrength-reduce -fno-builtin
endif
$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c
	$(TRACE_FLAG)echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -ansi  -Wall  -MD -MP $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"

endif
ifeq ($(BUILD_SPEC),PPC440sfdiab)
ifeq ($(DEBUG_MODE),1)
DEBUGFLAGS_C-Compiler = -g
else
DEBUGFLAGS_C-Compiler = -XO -Xsize-opt
endif
$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c
	$(TRACE_FLAG)echo "building $@"; $(TOOL_PATH)dcc $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -W:c:,-Xclib-optim-off -Xansi -Xlocal-data-area-static-only -Xforce-declarations  -Xmake-dependency=0xd $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"

endif
ifeq ($(BUILD_SPEC),PPC440sfgnu)
ifeq ($(DEBUG_MODE),1)
DEBUGFLAGS_C-Compiler = -g
else
DEBUGFLAGS_C-Compiler = -O2 -fstrength-reduce -fno-builtin
endif
$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c
	$(TRACE_FLAG)echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -ansi  -Wall  -MD -MP $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"

endif
ifeq ($(BUILD_SPEC),PPC603diab)
ifeq ($(DEBUG_MODE),1)
DEBUGFLAGS_C-Compiler = -g
else
DEBUGFLAGS_C-Compiler = -XO -Xsize-opt
endif
$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c
	$(TRACE_FLAG)echo "building $@"; $(TOOL_PATH)dcc $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -W:c:,-Xclib-optim-off -Xansi -Xlocal-data-area-static-only -Xforce-declarations  -Xmake-dependency=0xd $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"

endif
ifeq ($(BUILD_SPEC),PPC603gnu)
ifeq ($(DEBUG_MODE),1)
DEBUGFLAGS_C-Compiler = -g
else
DEBUGFLAGS_C-Compiler = -O2 -fstrength-reduce -fno-builtin
endif
$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c
	$(TRACE_FLAG)echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -ansi  -Wall  -MD -MP $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"

endif
ifeq ($(BUILD_SPEC),PPC604diab)
ifeq ($(DEBUG_MODE),1)
DEBUGFLAGS_C-Compiler = -g
else
DEBUGFLAGS_C-Compiler = -XO -Xsize-opt
endif
$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c
	$(TRACE_FLAG)echo "building $@"; $(TOOL_PATH)dcc $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -W:c:,-Xclib-optim-off -Xansi -Xlocal-data-area-static-only -Xforce-declarations  -Xmake-dependency=0xd $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"

endif
ifeq ($(BUILD_SPEC),PPC604gnu)
ifeq ($(DEBUG_MODE),1)
DEBUGFLAGS_C-Compiler = -g
else
DEBUGFLAGS_C-Compiler = -O2 -fstrength-reduce -fno-builtin
endif
$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c
	$(TRACE_FLAG)echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -ansi  -Wall  -MD -MP $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"

endif
ifeq ($(BUILD_SPEC),PPC85XXdiab)
ifeq ($(DEBUG_MODE),1)
DEBUGFLAGS_C-Compiler = -g
else
DEBUGFLAGS_C-Compiler = -XO -Xsize-opt
endif
$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c
	$(TRACE_FLAG)echo "building $@"; $(TOOL_PATH)dcc $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -W:c:,-Xclib-optim-off -Xansi -Xlocal-data-area-static-only -Xforce-declarations  -Xmake-dependency=0xd $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"

endif
ifeq ($(BUILD_SPEC),PPC85XXgnu)
ifeq ($(DEBUG_MODE),1)
DEBUGFLAGS_C-Compiler = -g
else
DEBUGFLAGS_C-Compiler = -O2 -fstrength-reduce -fno-builtin
endif
$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c
	$(TRACE_FLAG)echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -ansi  -Wall  -MD -MP $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"

endif
ifeq ($(BUILD_SPEC),PPC85XXsfdiab)
ifeq ($(DEBUG_MODE),1)
DEBUGFLAGS_C-Compiler = -g
else
DEBUGFLAGS_C-Compiler = -XO -Xsize-opt
endif
$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c
	$(TRACE_FLAG)echo "building $@"; $(TOOL_PATH)dcc $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -W:c:,-Xclib-optim-off -Xansi -Xlocal-data-area-static-only -Xforce-declarations  -Xmake-dependency=0xd $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"

endif
ifeq ($(BUILD_SPEC),PPC85XXsfgnu)
ifeq ($(DEBUG_MODE),1)
DEBUGFLAGS_C-Compiler = -g
else
DEBUGFLAGS_C-Compiler = -O2 -fstrength-reduce -fno-builtin
endif
$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c
	$(TRACE_FLAG)echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -ansi  -Wall  -MD -MP $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"

endif
ifeq ($(BUILD_SPEC),PPC860sfdiab)
ifeq ($(DEBUG_MODE),1)
DEBUGFLAGS_C-Compiler = -g
else
DEBUGFLAGS_C-Compiler = -XO -Xsize-opt
endif
$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c
	$(TRACE_FLAG)echo "building $@"; $(TOOL_PATH)dcc $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -W:c:,-Xclib-optim-off -Xansi -Xlocal-data-area-static-only -Xforce-declarations  -Xmake-dependency=0xd $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"

endif
ifeq ($(BUILD_SPEC),PPC860sfgnu)
ifeq ($(DEBUG_MODE),1)
DEBUGFLAGS_C-Compiler = -g
else
DEBUGFLAGS_C-Compiler = -O2 -fstrength-reduce -fno-builtin
endif
$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c
	$(TRACE_FLAG)echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -ansi  -Wall  -MD -MP $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"

endif
ifeq ($(BUILD_SPEC),SIMLINUXdiab)
ifeq ($(DEBUG_MODE),1)
DEBUGFLAGS_C-Compiler = -g
else
DEBUGFLAGS_C-Compiler = -XO -Xsize-opt
endif
$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c
	$(TRACE_FLAG)echo "building $@"; $(TOOL_PATH)dcc $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -W:c:,-Xclib-optim-off -Xansi -Xlocal-data-area-static-only -Xforce-declarations  -Xmake-dependency=0xd $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"

endif
ifeq ($(BUILD_SPEC),SIMLINUXgnu)
ifeq ($(DEBUG_MODE),1)
DEBUGFLAGS_C-Compiler = -g
else
DEBUGFLAGS_C-Compiler = -O2 -nostdlib -fno-builtin -fno-defer-pop
endif
$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c
	$(TRACE_FLAG)echo "building $@"; $(TOOL_PATH)ccpentium $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -ansi  -Wall  -MD -MP $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"

endif
ifeq ($(BUILD_SPEC),SIMNTdiab)
ifeq ($(DEBUG_MODE),1)
DEBUGFLAGS_C-Compiler = -g
else
DEBUGFLAGS_C-Compiler = -XO -Xsize-opt
endif
$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c
	$(TRACE_FLAG)echo "building $@"; $(TOOL_PATH)dcc $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -W:c:,-Xclib-optim-off -Xansi -Xlocal-data-area-static-only -Xforce-declarations  -Xmake-dependency=0xd $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"

endif
ifeq ($(BUILD_SPEC),SIMNTgnu)
ifeq ($(DEBUG_MODE),1)
DEBUGFLAGS_C-Compiler = -g
else
DEBUGFLAGS_C-Compiler = -O2 -nostdlib -fno-builtin -fno-defer-pop
endif
$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c
	$(TRACE_FLAG)echo "building $@"; $(TOOL_PATH)ccpentium $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -ansi  -Wall  -MD -MP $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"

endif
ifeq ($(BUILD_SPEC),SIMSPARCSOLARISdiab)
ifeq ($(DEBUG_MODE),1)
DEBUGFLAGS_C-Compiler = -g
else
DEBUGFLAGS_C-Compiler = -XO -Xsize-opt
endif
$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c
	$(TRACE_FLAG)echo "building $@"; $(TOOL_PATH)dcc $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -W:c:,-Xclib-optim-off -Xansi -Xlocal-data-area-static-only -Xforce-declarations  -Xmake-dependency=0xd $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"

endif
ifeq ($(BUILD_SPEC),SIMSPARCSOLARISgnu)
ifeq ($(DEBUG_MODE),1)
DEBUGFLAGS_C-Compiler = -g
else
DEBUGFLAGS_C-Compiler = -O2 -fstrength-reduce -fno-builtin
endif
$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c
	$(TRACE_FLAG)echo "building $@"; $(TOOL_PATH)ccsparc $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -ansi  -Wall  -MD -MP $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"

endif
ifeq ($(BUILD_SPEC),PPC32diab)
ifeq ($(DEBUG_MODE),1)
DEBUGFLAGS_C++-Compiler = -g
else
DEBUGFLAGS_C++-Compiler = -XO -Xsize-opt
endif
$(OBJ_DIR)/%.o : $(SRC_DIR)/%.cpp
	$(TRACE_FLAG)echo "building $@"; $(TOOL_PATH)dcc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -W:c:,-Xclib-optim-off -Xansi -Xlocal-data-area-static-only -Xforce-declarations  -Xmake-dependency=0xd $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.C
	$(TRACE_FLAG)echo "building $@"; $(TOOL_PATH)dcc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -W:c:,-Xclib-optim-off -Xansi -Xlocal-data-area-static-only -Xforce-declarations  -Xmake-dependency=0xd $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.cxx
	$(TRACE_FLAG)echo "building $@"; $(TOOL_PATH)dcc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -W:c:,-Xclib-optim-off -Xansi -Xlocal-data-area-static-only -Xforce-declarations  -Xmake-dependency=0xd $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.cc
	$(TRACE_FLAG)echo "building $@"; $(TOOL_PATH)dcc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -W:c:,-Xclib-optim-off -Xansi -Xlocal-data-area-static-only -Xforce-declarations  -Xmake-dependency=0xd $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"

endif
ifeq ($(BUILD_SPEC),PPC32gnu)
ifeq ($(DEBUG_MODE),1)
DEBUGFLAGS_C++-Compiler = -g
else
DEBUGFLAGS_C++-Compiler = -O2 -fstrength-reduce -fno-builtin
endif
$(OBJ_DIR)/%.o : $(SRC_DIR)/%.cpp
	$(TRACE_FLAG)echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.C
	$(TRACE_FLAG)echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.cxx
	$(TRACE_FLAG)echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.cc
	$(TRACE_FLAG)echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"

endif
ifeq ($(BUILD_SPEC),PPC32sfdiab)
ifeq ($(DEBUG_MODE),1)
DEBUGFLAGS_C++-Compiler = -g
else
DEBUGFLAGS_C++-Compiler = -XO -Xsize-opt
endif
$(OBJ_DIR)/%.o : $(SRC_DIR)/%.cpp
	$(TRACE_FLAG)echo "building $@"; $(TOOL_PATH)dcc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -W:c:,-Xclib-optim-off -Xansi -Xlocal-data-area-static-only -Xstsw-slow -Xforce-declarations  -Xmake-dependency=0xd $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.C
	$(TRACE_FLAG)echo "building $@"; $(TOOL_PATH)dcc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -W:c:,-Xclib-optim-off -Xansi -Xlocal-data-area-static-only -Xstsw-slow -Xforce-declarations  -Xmake-dependency=0xd $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.cxx
	$(TRACE_FLAG)echo "building $@"; $(TOOL_PATH)dcc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -W:c:,-Xclib-optim-off -Xansi -Xlocal-data-area-static-only -Xstsw-slow -Xforce-declarations  -Xmake-dependency=0xd $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.cc
	$(TRACE_FLAG)echo "building $@"; $(TOOL_PATH)dcc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -W:c:,-Xclib-optim-off -Xansi -Xlocal-data-area-static-only -Xstsw-slow -Xforce-declarations  -Xmake-dependency=0xd $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"

endif
ifeq ($(BUILD_SPEC),PPC32sfgnu)
ifeq ($(DEBUG_MODE),1)
DEBUGFLAGS_C++-Compiler = -g
else
DEBUGFLAGS_C++-Compiler = -O2 -fstrength-reduce -fno-builtin
endif
$(OBJ_DIR)/%.o : $(SRC_DIR)/%.cpp
	$(TRACE_FLAG)echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.C
	$(TRACE_FLAG)echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.cxx
	$(TRACE_FLAG)echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.cc
	$(TRACE_FLAG)echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"

endif
ifeq ($(BUILD_SPEC),PPC403diab)
ifeq ($(DEBUG_MODE),1)
DEBUGFLAGS_C++-Compiler = -g
else
DEBUGFLAGS_C++-Compiler = -XO -Xsize-opt
endif
$(OBJ_DIR)/%.o : $(SRC_DIR)/%.cpp
	$(TRACE_FLAG)echo "building $@"; $(TOOL_PATH)dcc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -W:c:,-Xclib-optim-off -Xansi -Xlocal-data-area-static-only -Xforce-declarations  -Xmake-dependency=0xd $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.C
	$(TRACE_FLAG)echo "building $@"; $(TOOL_PATH)dcc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -W:c:,-Xclib-optim-off -Xansi -Xlocal-data-area-static-only -Xforce-declarations  -Xmake-dependency=0xd $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.cxx
	$(TRACE_FLAG)echo "building $@"; $(TOOL_PATH)dcc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -W:c:,-Xclib-optim-off -Xansi -Xlocal-data-area-static-only -Xforce-declarations  -Xmake-dependency=0xd $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.cc
	$(TRACE_FLAG)echo "building $@"; $(TOOL_PATH)dcc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -W:c:,-Xclib-optim-off -Xansi -Xlocal-data-area-static-only -Xforce-declarations  -Xmake-dependency=0xd $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"

endif
ifeq ($(BUILD_SPEC),PPC403gnu)
ifeq ($(DEBUG_MODE),1)
DEBUGFLAGS_C++-Compiler = -g
else
DEBUGFLAGS_C++-Compiler = -O2 -fstrength-reduce -fno-builtin
endif
$(OBJ_DIR)/%.o : $(SRC_DIR)/%.cpp
	$(TRACE_FLAG)echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.C
	$(TRACE_FLAG)echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.cxx
	$(TRACE_FLAG)echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.cc
	$(TRACE_FLAG)echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"

endif
ifeq ($(BUILD_SPEC),PPC405diab)
ifeq ($(DEBUG_MODE),1)
DEBUGFLAGS_C++-Compiler = -g
else
DEBUGFLAGS_C++-Compiler = -XO -Xsize-opt
endif
$(OBJ_DIR)/%.o : $(SRC_DIR)/%.cpp
	$(TRACE_FLAG)echo "building $@"; $(TOOL_PATH)dcc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -W:c:,-Xclib-optim-off -Xansi -Xlocal-data-area-static-only -Xforce-declarations  -Xmake-dependency=0xd $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.C
	$(TRACE_FLAG)echo "building $@"; $(TOOL_PATH)dcc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -W:c:,-Xclib-optim-off -Xansi -Xlocal-data-area-static-only -Xforce-declarations  -Xmake-dependency=0xd $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.cxx
	$(TRACE_FLAG)echo "building $@"; $(TOOL_PATH)dcc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -W:c:,-Xclib-optim-off -Xansi -Xlocal-data-area-static-only -Xforce-declarations  -Xmake-dependency=0xd $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.cc
	$(TRACE_FLAG)echo "building $@"; $(TOOL_PATH)dcc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -W:c:,-Xclib-optim-off -Xansi -Xlocal-data-area-static-only -Xforce-declarations  -Xmake-dependency=0xd $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"

endif
ifeq ($(BUILD_SPEC),PPC405gnu)
ifeq ($(DEBUG_MODE),1)
DEBUGFLAGS_C++-Compiler = -g
else
DEBUGFLAGS_C++-Compiler = -O2 -fstrength-reduce -fno-builtin
endif
$(OBJ_DIR)/%.o : $(SRC_DIR)/%.cpp
	$(TRACE_FLAG)echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.C
	$(TRACE_FLAG)echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.cxx
	$(TRACE_FLAG)echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.cc
	$(TRACE_FLAG)echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"

endif
ifeq ($(BUILD_SPEC),PPC405sfdiab)
ifeq ($(DEBUG_MODE),1)
DEBUGFLAGS_C++-Compiler = -g
else
DEBUGFLAGS_C++-Compiler = -XO -Xsize-opt
endif
$(OBJ_DIR)/%.o : $(SRC_DIR)/%.cpp
	$(TRACE_FLAG)echo "building $@"; $(TOOL_PATH)dcc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -W:c:,-Xclib-optim-off -Xansi -Xlocal-data-area-static-only -Xforce-declarations  -Xmake-dependency=0xd $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.C
	$(TRACE_FLAG)echo "building $@"; $(TOOL_PATH)dcc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -W:c:,-Xclib-optim-off -Xansi -Xlocal-data-area-static-only -Xforce-declarations  -Xmake-dependency=0xd $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.cxx
	$(TRACE_FLAG)echo "building $@"; $(TOOL_PATH)dcc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -W:c:,-Xclib-optim-off -Xansi -Xlocal-data-area-static-only -Xforce-declarations  -Xmake-dependency=0xd $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.cc
	$(TRACE_FLAG)echo "building $@"; $(TOOL_PATH)dcc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -W:c:,-Xclib-optim-off -Xansi -Xlocal-data-area-static-only -Xforce-declarations  -Xmake-dependency=0xd $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"

endif
ifeq ($(BUILD_SPEC),PPC405sfgnu)
ifeq ($(DEBUG_MODE),1)
DEBUGFLAGS_C++-Compiler = -g
else
DEBUGFLAGS_C++-Compiler = -O2 -fstrength-reduce -fno-builtin
endif
$(OBJ_DIR)/%.o : $(SRC_DIR)/%.cpp
	$(TRACE_FLAG)echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.C
	$(TRACE_FLAG)echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.cxx
	$(TRACE_FLAG)echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.cc
	$(TRACE_FLAG)echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"

endif
ifeq ($(BUILD_SPEC),PPC440diab)
ifeq ($(DEBUG_MODE),1)
DEBUGFLAGS_C++-Compiler = -g
else
DEBUGFLAGS_C++-Compiler = -XO -Xsize-opt
endif
$(OBJ_DIR)/%.o : $(SRC_DIR)/%.cpp
	$(TRACE_FLAG)echo "building $@"; $(TOOL_PATH)dcc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -W:c:,-Xclib-optim-off -Xansi -Xlocal-data-area-static-only -Xforce-declarations  -Xmake-dependency=0xd $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.C
	$(TRACE_FLAG)echo "building $@"; $(TOOL_PATH)dcc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -W:c:,-Xclib-optim-off -Xansi -Xlocal-data-area-static-only -Xforce-declarations  -Xmake-dependency=0xd $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.cxx
	$(TRACE_FLAG)echo "building $@"; $(TOOL_PATH)dcc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -W:c:,-Xclib-optim-off -Xansi -Xlocal-data-area-static-only -Xforce-declarations  -Xmake-dependency=0xd $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.cc
	$(TRACE_FLAG)echo "building $@"; $(TOOL_PATH)dcc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -W:c:,-Xclib-optim-off -Xansi -Xlocal-data-area-static-only -Xforce-declarations  -Xmake-dependency=0xd $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"

endif
ifeq ($(BUILD_SPEC),PPC440gnu)
ifeq ($(DEBUG_MODE),1)
DEBUGFLAGS_C++-Compiler = -g
else
DEBUGFLAGS_C++-Compiler = -O2 -fstrength-reduce -fno-builtin
endif
$(OBJ_DIR)/%.o : $(SRC_DIR)/%.cpp
	$(TRACE_FLAG)echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.C
	$(TRACE_FLAG)echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.cxx
	$(TRACE_FLAG)echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.cc
	$(TRACE_FLAG)echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"

endif
ifeq ($(BUILD_SPEC),PPC440sfdiab)
ifeq ($(DEBUG_MODE),1)
DEBUGFLAGS_C++-Compiler = -g
else
DEBUGFLAGS_C++-Compiler = -XO -Xsize-opt
endif
$(OBJ_DIR)/%.o : $(SRC_DIR)/%.cpp
	$(TRACE_FLAG)echo "building $@"; $(TOOL_PATH)dcc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -W:c:,-Xclib-optim-off -Xansi -Xlocal-data-area-static-only -Xforce-declarations  -Xmake-dependency=0xd $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.C
	$(TRACE_FLAG)echo "building $@"; $(TOOL_PATH)dcc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -W:c:,-Xclib-optim-off -Xansi -Xlocal-data-area-static-only -Xforce-declarations  -Xmake-dependency=0xd $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.cxx
	$(TRACE_FLAG)echo "building $@"; $(TOOL_PATH)dcc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -W:c:,-Xclib-optim-off -Xansi -Xlocal-data-area-static-only -Xforce-declarations  -Xmake-dependency=0xd $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.cc
	$(TRACE_FLAG)echo "building $@"; $(TOOL_PATH)dcc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -W:c:,-Xclib-optim-off -Xansi -Xlocal-data-area-static-only -Xforce-declarations  -Xmake-dependency=0xd $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"

endif
ifeq ($(BUILD_SPEC),PPC440sfgnu)
ifeq ($(DEBUG_MODE),1)
DEBUGFLAGS_C++-Compiler = -g
else
DEBUGFLAGS_C++-Compiler = -O2 -fstrength-reduce -fno-builtin
endif
$(OBJ_DIR)/%.o : $(SRC_DIR)/%.cpp
	$(TRACE_FLAG)echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.C
	$(TRACE_FLAG)echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.cxx
	$(TRACE_FLAG)echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.cc
	$(TRACE_FLAG)echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"

endif
ifeq ($(BUILD_SPEC),PPC603diab)
ifeq ($(DEBUG_MODE),1)
DEBUGFLAGS_C++-Compiler = -g
else
DEBUGFLAGS_C++-Compiler = -XO -Xsize-opt
endif
$(OBJ_DIR)/%.o : $(SRC_DIR)/%.cpp
	$(TRACE_FLAG)echo "building $@"; $(TOOL_PATH)dcc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -W:c:,-Xclib-optim-off -Xansi -Xlocal-data-area-static-only -Xforce-declarations  -Xmake-dependency=0xd $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.C
	$(TRACE_FLAG)echo "building $@"; $(TOOL_PATH)dcc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -W:c:,-Xclib-optim-off -Xansi -Xlocal-data-area-static-only -Xforce-declarations  -Xmake-dependency=0xd $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.cxx
	$(TRACE_FLAG)echo "building $@"; $(TOOL_PATH)dcc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -W:c:,-Xclib-optim-off -Xansi -Xlocal-data-area-static-only -Xforce-declarations  -Xmake-dependency=0xd $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.cc
	$(TRACE_FLAG)echo "building $@"; $(TOOL_PATH)dcc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -W:c:,-Xclib-optim-off -Xansi -Xlocal-data-area-static-only -Xforce-declarations  -Xmake-dependency=0xd $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"

endif
ifeq ($(BUILD_SPEC),PPC603gnu)
ifeq ($(DEBUG_MODE),1)
DEBUGFLAGS_C++-Compiler = -g
else
DEBUGFLAGS_C++-Compiler = -O2 -fstrength-reduce -fno-builtin
endif
$(OBJ_DIR)/%.o : $(SRC_DIR)/%.cpp
	$(TRACE_FLAG) $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL -D'SVN_REV="$(shell svnversion -n .)"' $(DEFINES) -o "$@" -c "$<"

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.C
	$(TRACE_FLAG) $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL -D'SVN_REV="$(shell svnversion -n .)"' $(DEFINES) -o "$@" -c "$<"

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.cxx
	$(TRACE_FLAG) $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL -D'SVN_REV="$(shell svnversion -n .)"' $(DEFINES) -o "$@" -c "$<"

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.cc
	$(TRACE_FLAG) $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL -D'SVN_REV="$(shell svnversion -n .)"' $(DEFINES) -o "$@" -c "$<"

endif
ifeq ($(BUILD_SPEC),PPC604diab)
ifeq ($(DEBUG_MODE),1)
DEBUGFLAGS_C++-Compiler = -g
else
DEBUGFLAGS_C++-Compiler = -XO -Xsize-opt
endif
$(OBJ_DIR)/%.o : $(SRC_DIR)/%.cpp
	$(TRACE_FLAG)echo "building $@"; $(TOOL_PATH)dcc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -W:c:,-Xclib-optim-off -Xansi -Xlocal-data-area-static-only -Xforce-declarations  -Xmake-dependency=0xd $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.C
	$(TRACE_FLAG)echo "building $@"; $(TOOL_PATH)dcc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -W:c:,-Xclib-optim-off -Xansi -Xlocal-data-area-static-only -Xforce-declarations  -Xmake-dependency=0xd $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.cxx
	$(TRACE_FLAG)echo "building $@"; $(TOOL_PATH)dcc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -W:c:,-Xclib-optim-off -Xansi -Xlocal-data-area-static-only -Xforce-declarations  -Xmake-dependency=0xd $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.cc
	$(TRACE_FLAG)echo "building $@"; $(TOOL_PATH)dcc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -W:c:,-Xclib-optim-off -Xansi -Xlocal-data-area-static-only -Xforce-declarations  -Xmake-dependency=0xd $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"

endif
ifeq ($(BUILD_SPEC),PPC604gnu)
ifeq ($(DEBUG_MODE),1)
DEBUGFLAGS_C++-Compiler = -g
else
DEBUGFLAGS_C++-Compiler = -O2 -fstrength-reduce -fno-builtin
endif
$(OBJ_DIR)/%.o : $(SRC_DIR)/%.cpp
	$(TRACE_FLAG)echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.C
	$(TRACE_FLAG)echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.cxx
	$(TRACE_FLAG)echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.cc
	$(TRACE_FLAG)echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"

endif
ifeq ($(BUILD_SPEC),PPC85XXdiab)
ifeq ($(DEBUG_MODE),1)
DEBUGFLAGS_C++-Compiler = -g
else
DEBUGFLAGS_C++-Compiler = -XO -Xsize-opt
endif
$(OBJ_DIR)/%.o : $(SRC_DIR)/%.cpp
	$(TRACE_FLAG)echo "building $@"; $(TOOL_PATH)dcc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -W:c:,-Xclib-optim-off -Xansi -Xlocal-data-area-static-only -Xforce-declarations  -Xmake-dependency=0xd $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.C
	$(TRACE_FLAG)echo "building $@"; $(TOOL_PATH)dcc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -W:c:,-Xclib-optim-off -Xansi -Xlocal-data-area-static-only -Xforce-declarations  -Xmake-dependency=0xd $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.cxx
	$(TRACE_FLAG)echo "building $@"; $(TOOL_PATH)dcc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -W:c:,-Xclib-optim-off -Xansi -Xlocal-data-area-static-only -Xforce-declarations  -Xmake-dependency=0xd $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.cc
	$(TRACE_FLAG)echo "building $@"; $(TOOL_PATH)dcc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -W:c:,-Xclib-optim-off -Xansi -Xlocal-data-area-static-only -Xforce-declarations  -Xmake-dependency=0xd $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"

endif
ifeq ($(BUILD_SPEC),PPC85XXgnu)
ifeq ($(DEBUG_MODE),1)
DEBUGFLAGS_C++-Compiler = -g
else
DEBUGFLAGS_C++-Compiler = -O2 -fstrength-reduce -fno-builtin
endif
$(OBJ_DIR)/%.o : $(SRC_DIR)/%.cpp
	$(TRACE_FLAG)echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.C
	$(TRACE_FLAG)echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.cxx
	$(TRACE_FLAG)echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.cc
	$(TRACE_FLAG)echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"

endif
ifeq ($(BUILD_SPEC),PPC85XXsfdiab)
ifeq ($(DEBUG_MODE),1)
DEBUGFLAGS_C++-Compiler = -g
else
DEBUGFLAGS_C++-Compiler = -XO -Xsize-opt
endif
$(OBJ_DIR)/%.o : $(SRC_DIR)/%.cpp
	$(TRACE_FLAG)echo "building $@"; $(TOOL_PATH)dcc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -W:c:,-Xclib-optim-off -Xansi -Xlocal-data-area-static-only -Xforce-declarations  -Xmake-dependency=0xd $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.C
	$(TRACE_FLAG)echo "building $@"; $(TOOL_PATH)dcc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -W:c:,-Xclib-optim-off -Xansi -Xlocal-data-area-static-only -Xforce-declarations  -Xmake-dependency=0xd $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.cxx
	$(TRACE_FLAG)echo "building $@"; $(TOOL_PATH)dcc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -W:c:,-Xclib-optim-off -Xansi -Xlocal-data-area-static-only -Xforce-declarations  -Xmake-dependency=0xd $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.cc
	$(TRACE_FLAG)echo "building $@"; $(TOOL_PATH)dcc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -W:c:,-Xclib-optim-off -Xansi -Xlocal-data-area-static-only -Xforce-declarations  -Xmake-dependency=0xd $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"

endif
ifeq ($(BUILD_SPEC),PPC85XXsfgnu)
ifeq ($(DEBUG_MODE),1)
DEBUGFLAGS_C++-Compiler = -g
else
DEBUGFLAGS_C++-Compiler = -O2 -fstrength-reduce -fno-builtin
endif
$(OBJ_DIR)/%.o : $(SRC_DIR)/%.cpp
	$(TRACE_FLAG)echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.C
	$(TRACE_FLAG)echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.cxx
	$(TRACE_FLAG)echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.cc
	$(TRACE_FLAG)echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"

endif
ifeq ($(BUILD_SPEC),PPC860sfdiab)
ifeq ($(DEBUG_MODE),1)
DEBUGFLAGS_C++-Compiler = -g
else
DEBUGFLAGS_C++-Compiler = -XO -Xsize-opt
endif
$(OBJ_DIR)/%.o : $(SRC_DIR)/%.cpp
	$(TRACE_FLAG)echo "building $@"; $(TOOL_PATH)dcc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -W:c:,-Xclib-optim-off -Xansi -Xlocal-data-area-static-only -Xforce-declarations  -Xmake-dependency=0xd $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.C
	$(TRACE_FLAG)echo "building $@"; $(TOOL_PATH)dcc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -W:c:,-Xclib-optim-off -Xansi -Xlocal-data-area-static-only -Xforce-declarations  -Xmake-dependency=0xd $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.cxx
	$(TRACE_FLAG)echo "building $@"; $(TOOL_PATH)dcc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -W:c:,-Xclib-optim-off -Xansi -Xlocal-data-area-static-only -Xforce-declarations  -Xmake-dependency=0xd $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.cc
	$(TRACE_FLAG)echo "building $@"; $(TOOL_PATH)dcc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -W:c:,-Xclib-optim-off -Xansi -Xlocal-data-area-static-only -Xforce-declarations  -Xmake-dependency=0xd $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"

endif
ifeq ($(BUILD_SPEC),PPC860sfgnu)
ifeq ($(DEBUG_MODE),1)
DEBUGFLAGS_C++-Compiler = -g
else
DEBUGFLAGS_C++-Compiler = -O2 -fstrength-reduce -fno-builtin
endif
$(OBJ_DIR)/%.o : $(SRC_DIR)/%.cpp
	$(TRACE_FLAG)echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.C
	$(TRACE_FLAG)echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.cxx
	$(TRACE_FLAG)echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.cc
	$(TRACE_FLAG)echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"

endif
ifeq ($(BUILD_SPEC),SIMLINUXdiab)
ifeq ($(DEBUG_MODE),1)
DEBUGFLAGS_C++-Compiler = -g
else
DEBUGFLAGS_C++-Compiler = -XO -Xsize-opt
endif
$(OBJ_DIR)/%.o : $(SRC_DIR)/%.cpp
	$(TRACE_FLAG)echo "building $@"; $(TOOL_PATH)dcc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -W:c:,-Xclib-optim-off -Xansi -Xlocal-data-area-static-only -Xforce-declarations  -Xmake-dependency=0xd $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.C
	$(TRACE_FLAG)echo "building $@"; $(TOOL_PATH)dcc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -W:c:,-Xclib-optim-off -Xansi -Xlocal-data-area-static-only -Xforce-declarations  -Xmake-dependency=0xd $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.cxx
	$(TRACE_FLAG)echo "building $@"; $(TOOL_PATH)dcc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -W:c:,-Xclib-optim-off -Xansi -Xlocal-data-area-static-only -Xforce-declarations  -Xmake-dependency=0xd $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.cc
	$(TRACE_FLAG)echo "building $@"; $(TOOL_PATH)dcc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -W:c:,-Xclib-optim-off -Xansi -Xlocal-data-area-static-only -Xforce-declarations  -Xmake-dependency=0xd $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"

endif
ifeq ($(BUILD_SPEC),SIMLINUXgnu)
ifeq ($(DEBUG_MODE),1)
DEBUGFLAGS_C++-Compiler = -g
else
DEBUGFLAGS_C++-Compiler = -O2 -nostdlib -fno-builtin -fno-defer-pop
endif
$(OBJ_DIR)/%.o : $(SRC_DIR)/%.cpp
	$(TRACE_FLAG)echo "building $@"; $(TOOL_PATH)ccpentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.C
	$(TRACE_FLAG)echo "building $@"; $(TOOL_PATH)ccpentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.cxx
	$(TRACE_FLAG)echo "building $@"; $(TOOL_PATH)ccpentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.cc
	$(TRACE_FLAG)echo "building $@"; $(TOOL_PATH)ccpentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"

endif
ifeq ($(BUILD_SPEC),SIMNTdiab)
ifeq ($(DEBUG_MODE),1)
DEBUGFLAGS_C++-Compiler = -g
else
DEBUGFLAGS_C++-Compiler = -XO -Xsize-opt
endif
$(OBJ_DIR)/%.o : $(SRC_DIR)/%.cpp
	$(TRACE_FLAG)echo "building $@"; $(TOOL_PATH)dcc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -W:c:,-Xclib-optim-off -Xansi -Xlocal-data-area-static-only -Xforce-declarations  -Xmake-dependency=0xd $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.C
	$(TRACE_FLAG)echo "building $@"; $(TOOL_PATH)dcc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -W:c:,-Xclib-optim-off -Xansi -Xlocal-data-area-static-only -Xforce-declarations  -Xmake-dependency=0xd $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.cxx
	$(TRACE_FLAG)echo "building $@"; $(TOOL_PATH)dcc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -W:c:,-Xclib-optim-off -Xansi -Xlocal-data-area-static-only -Xforce-declarations  -Xmake-dependency=0xd $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.cc
	$(TRACE_FLAG)echo "building $@"; $(TOOL_PATH)dcc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -W:c:,-Xclib-optim-off -Xansi -Xlocal-data-area-static-only -Xforce-declarations  -Xmake-dependency=0xd $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"

endif
ifeq ($(BUILD_SPEC),SIMNTgnu)
ifeq ($(DEBUG_MODE),1)
DEBUGFLAGS_C++-Compiler = -g
else
DEBUGFLAGS_C++-Compiler = -O2 -nostdlib -fno-builtin -fno-defer-pop
endif
$(OBJ_DIR)/%.o : $(SRC_DIR)/%.cpp
	$(TRACE_FLAG)echo "building $@"; $(TOOL_PATH)ccpentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.C
	$(TRACE_FLAG)echo "building $@"; $(TOOL_PATH)ccpentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.cxx
	$(TRACE_FLAG)echo "building $@"; $(TOOL_PATH)ccpentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.cc
	$(TRACE_FLAG)echo "building $@"; $(TOOL_PATH)ccpentium $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"

endif
ifeq ($(BUILD_SPEC),SIMSPARCSOLARISdiab)
ifeq ($(DEBUG_MODE),1)
DEBUGFLAGS_C++-Compiler = -g
else
DEBUGFLAGS_C++-Compiler = -XO -Xsize-opt
endif
$(OBJ_DIR)/%.o : $(SRC_DIR)/%.cpp
	$(TRACE_FLAG)echo "building $@"; $(TOOL_PATH)dcc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -W:c:,-Xclib-optim-off -Xansi -Xlocal-data-area-static-only -Xforce-declarations  -Xmake-dependency=0xd $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.C
	$(TRACE_FLAG)echo "building $@"; $(TOOL_PATH)dcc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -W:c:,-Xclib-optim-off -Xansi -Xlocal-data-area-static-only -Xforce-declarations  -Xmake-dependency=0xd $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.cxx
	$(TRACE_FLAG)echo "building $@"; $(TOOL_PATH)dcc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -W:c:,-Xclib-optim-off -Xansi -Xlocal-data-area-static-only -Xforce-declarations  -Xmake-dependency=0xd $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.cc
	$(TRACE_FLAG)echo "building $@"; $(TOOL_PATH)dcc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -W:c:,-Xclib-optim-off -Xansi -Xlocal-data-area-static-only -Xforce-declarations  -Xmake-dependency=0xd $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"

endif
ifeq ($(BUILD_SPEC),SIMSPARCSOLARISgnu)
ifeq ($(DEBUG_MODE),1)
DEBUGFLAGS_C++-Compiler = -g
else
DEBUGFLAGS_C++-Compiler = -O2 -fstrength-reduce -fno-builtin
endif
$(OBJ_DIR)/%.o : $(SRC_DIR)/%.cpp
	$(TRACE_FLAG)echo "building $@"; $(TOOL_PATH)ccsparc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.C
	$(TRACE_FLAG)echo "building $@"; $(TOOL_PATH)ccsparc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.cxx
	$(TRACE_FLAG)echo "building $@"; $(TOOL_PATH)ccsparc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.cc
	$(TRACE_FLAG)echo "building $@"; $(TOOL_PATH)ccsparc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"

endif
ifeq ($(BUILD_SPEC),PPC32diab)
ifeq ($(DEBUG_MODE),1)
DEBUGFLAGS_Assembler = -g
else
DEBUGFLAGS_Assembler = -XO -Xsize-opt
endif
$(OBJ_DIR)/%.o : $(SRC_DIR)/%.s
	$(TRACE_FLAG)echo "building $@"; $(TOOL_PATH)dcc $(DEBUGFLAGS_Assembler) $(CC_ARCH_SPEC) -W:c:,-Xclib-optim-off -Xansi -Xlocal-data-area-static-only -Xpreprocess-assembly -Xcpp-no-space  -Xmake-dependency=0xd $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"

endif
ifeq ($(BUILD_SPEC),PPC32gnu)
ifeq ($(DEBUG_MODE),1)
DEBUGFLAGS_Assembler = -g
else
DEBUGFLAGS_Assembler = -O2 -fstrength-reduce -fno-builtin
endif
$(OBJ_DIR)/%.o : $(SRC_DIR)/%.s
	$(TRACE_FLAG)echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_Assembler) $(CC_ARCH_SPEC) -ansi   -xassembler-with-cpp -MD -MP $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"

endif
ifeq ($(BUILD_SPEC),PPC32sfdiab)
ifeq ($(DEBUG_MODE),1)
DEBUGFLAGS_Assembler = -g
else
DEBUGFLAGS_Assembler = -XO -Xsize-opt
endif
$(OBJ_DIR)/%.o : $(SRC_DIR)/%.s
	$(TRACE_FLAG)echo "building $@"; $(TOOL_PATH)dcc $(DEBUGFLAGS_Assembler) $(CC_ARCH_SPEC) -W:c:,-Xclib-optim-off -Xansi -Xlocal-data-area-static-only -Xstsw-slow -Xpreprocess-assembly -Xcpp-no-space  -Xmake-dependency=0xd $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"

endif
ifeq ($(BUILD_SPEC),PPC32sfgnu)
ifeq ($(DEBUG_MODE),1)
DEBUGFLAGS_Assembler = -g
else
DEBUGFLAGS_Assembler = -O2 -fstrength-reduce -fno-builtin
endif
$(OBJ_DIR)/%.o : $(SRC_DIR)/%.s
	$(TRACE_FLAG)echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_Assembler) $(CC_ARCH_SPEC) -ansi   -xassembler-with-cpp -MD -MP $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"

endif
ifeq ($(BUILD_SPEC),PPC403diab)
ifeq ($(DEBUG_MODE),1)
DEBUGFLAGS_Assembler = -g
else
DEBUGFLAGS_Assembler = -XO -Xsize-opt
endif
$(OBJ_DIR)/%.o : $(SRC_DIR)/%.s
	$(TRACE_FLAG)echo "building $@"; $(TOOL_PATH)dcc $(DEBUGFLAGS_Assembler) $(CC_ARCH_SPEC) -W:c:,-Xclib-optim-off -Xansi -Xlocal-data-area-static-only -Xpreprocess-assembly -Xcpp-no-space  -Xmake-dependency=0xd $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"

endif
ifeq ($(BUILD_SPEC),PPC403gnu)
ifeq ($(DEBUG_MODE),1)
DEBUGFLAGS_Assembler = -g
else
DEBUGFLAGS_Assembler = -O2 -fstrength-reduce -fno-builtin
endif
$(OBJ_DIR)/%.o : $(SRC_DIR)/%.s
	$(TRACE_FLAG)echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_Assembler) $(CC_ARCH_SPEC) -ansi   -xassembler-with-cpp -MD -MP $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"

endif
ifeq ($(BUILD_SPEC),PPC405diab)
ifeq ($(DEBUG_MODE),1)
DEBUGFLAGS_Assembler = -g
else
DEBUGFLAGS_Assembler = -XO -Xsize-opt
endif
$(OBJ_DIR)/%.o : $(SRC_DIR)/%.s
	$(TRACE_FLAG)echo "building $@"; $(TOOL_PATH)dcc $(DEBUGFLAGS_Assembler) $(CC_ARCH_SPEC) -W:c:,-Xclib-optim-off -Xansi -Xlocal-data-area-static-only -Xpreprocess-assembly -Xcpp-no-space  -Xmake-dependency=0xd $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"

endif
ifeq ($(BUILD_SPEC),PPC405gnu)
ifeq ($(DEBUG_MODE),1)
DEBUGFLAGS_Assembler = -g
else
DEBUGFLAGS_Assembler = -O2 -fstrength-reduce -fno-builtin
endif
$(OBJ_DIR)/%.o : $(SRC_DIR)/%.s
	$(TRACE_FLAG)echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_Assembler) $(CC_ARCH_SPEC) -ansi   -xassembler-with-cpp -MD -MP $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"

endif
ifeq ($(BUILD_SPEC),PPC405sfdiab)
ifeq ($(DEBUG_MODE),1)
DEBUGFLAGS_Assembler = -g
else
DEBUGFLAGS_Assembler = -XO -Xsize-opt
endif
$(OBJ_DIR)/%.o : $(SRC_DIR)/%.s
	$(TRACE_FLAG)echo "building $@"; $(TOOL_PATH)dcc $(DEBUGFLAGS_Assembler) $(CC_ARCH_SPEC) -W:c:,-Xclib-optim-off -Xansi -Xlocal-data-area-static-only -Xpreprocess-assembly -Xcpp-no-space  -Xmake-dependency=0xd $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"

endif
ifeq ($(BUILD_SPEC),PPC405sfgnu)
ifeq ($(DEBUG_MODE),1)
DEBUGFLAGS_Assembler = -g
else
DEBUGFLAGS_Assembler = -O2 -fstrength-reduce -fno-builtin
endif
$(OBJ_DIR)/%.o : $(SRC_DIR)/%.s
	$(TRACE_FLAG)echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_Assembler) $(CC_ARCH_SPEC) -ansi   -xassembler-with-cpp -MD -MP $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"

endif
ifeq ($(BUILD_SPEC),PPC440diab)
ifeq ($(DEBUG_MODE),1)
DEBUGFLAGS_Assembler = -g
else
DEBUGFLAGS_Assembler = -XO -Xsize-opt
endif
$(OBJ_DIR)/%.o : $(SRC_DIR)/%.s
	$(TRACE_FLAG)echo "building $@"; $(TOOL_PATH)dcc $(DEBUGFLAGS_Assembler) $(CC_ARCH_SPEC) -W:c:,-Xclib-optim-off -Xansi -Xlocal-data-area-static-only -Xpreprocess-assembly -Xcpp-no-space  -Xmake-dependency=0xd $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"

endif
ifeq ($(BUILD_SPEC),PPC440gnu)
ifeq ($(DEBUG_MODE),1)
DEBUGFLAGS_Assembler = -g
else
DEBUGFLAGS_Assembler = -O2 -fstrength-reduce -fno-builtin
endif
$(OBJ_DIR)/%.o : $(SRC_DIR)/%.s
	$(TRACE_FLAG)echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_Assembler) $(CC_ARCH_SPEC) -ansi   -xassembler-with-cpp -MD -MP $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"

endif
ifeq ($(BUILD_SPEC),PPC440sfdiab)
ifeq ($(DEBUG_MODE),1)
DEBUGFLAGS_Assembler = -g
else
DEBUGFLAGS_Assembler = -XO -Xsize-opt
endif
$(OBJ_DIR)/%.o : $(SRC_DIR)/%.s
	$(TRACE_FLAG)echo "building $@"; $(TOOL_PATH)dcc $(DEBUGFLAGS_Assembler) $(CC_ARCH_SPEC) -W:c:,-Xclib-optim-off -Xansi -Xlocal-data-area-static-only -Xpreprocess-assembly -Xcpp-no-space  -Xmake-dependency=0xd $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"

endif
ifeq ($(BUILD_SPEC),PPC440sfgnu)
ifeq ($(DEBUG_MODE),1)
DEBUGFLAGS_Assembler = -g
else
DEBUGFLAGS_Assembler = -O2 -fstrength-reduce -fno-builtin
endif
$(OBJ_DIR)/%.o : $(SRC_DIR)/%.s
	$(TRACE_FLAG)echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_Assembler) $(CC_ARCH_SPEC) -ansi   -xassembler-with-cpp -MD -MP $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"

endif
ifeq ($(BUILD_SPEC),PPC603diab)
ifeq ($(DEBUG_MODE),1)
DEBUGFLAGS_Assembler = -g
else
DEBUGFLAGS_Assembler = -XO -Xsize-opt
endif
$(OBJ_DIR)/%.o : $(SRC_DIR)/%.s
	$(TRACE_FLAG)echo "building $@"; $(TOOL_PATH)dcc $(DEBUGFLAGS_Assembler) $(CC_ARCH_SPEC) -W:c:,-Xclib-optim-off -Xansi -Xlocal-data-area-static-only -Xpreprocess-assembly -Xcpp-no-space  -Xmake-dependency=0xd $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"

endif
ifeq ($(BUILD_SPEC),PPC603gnu)
ifeq ($(DEBUG_MODE),1)
DEBUGFLAGS_Assembler = -g
else
DEBUGFLAGS_Assembler = -O2 -fstrength-reduce -fno-builtin
endif
$(OBJ_DIR)/%.o : $(SRC_DIR)/%.s
	$(TRACE_FLAG)echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_Assembler) $(CC_ARCH_SPEC) -ansi   -xassembler-with-cpp -MD -MP $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"

endif
ifeq ($(BUILD_SPEC),PPC604diab)
ifeq ($(DEBUG_MODE),1)
DEBUGFLAGS_Assembler = -g
else
DEBUGFLAGS_Assembler = -XO -Xsize-opt
endif
$(OBJ_DIR)/%.o : $(SRC_DIR)/%.s
	$(TRACE_FLAG)echo "building $@"; $(TOOL_PATH)dcc $(DEBUGFLAGS_Assembler) $(CC_ARCH_SPEC) -W:c:,-Xclib-optim-off -Xansi -Xlocal-data-area-static-only -Xpreprocess-assembly -Xcpp-no-space  -Xmake-dependency=0xd $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"

endif
ifeq ($(BUILD_SPEC),PPC604gnu)
ifeq ($(DEBUG_MODE),1)
DEBUGFLAGS_Assembler = -g
else
DEBUGFLAGS_Assembler = -O2 -fstrength-reduce -fno-builtin
endif
$(OBJ_DIR)/%.o : $(SRC_DIR)/%.s
	$(TRACE_FLAG)echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_Assembler) $(CC_ARCH_SPEC) -ansi   -xassembler-with-cpp -MD -MP $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"

endif
ifeq ($(BUILD_SPEC),PPC85XXdiab)
ifeq ($(DEBUG_MODE),1)
DEBUGFLAGS_Assembler = -g
else
DEBUGFLAGS_Assembler = -XO -Xsize-opt
endif
$(OBJ_DIR)/%.o : $(SRC_DIR)/%.s
	$(TRACE_FLAG)echo "building $@"; $(TOOL_PATH)dcc $(DEBUGFLAGS_Assembler) $(CC_ARCH_SPEC) -W:c:,-Xclib-optim-off -Xansi -Xlocal-data-area-static-only -Xpreprocess-assembly -Xcpp-no-space  -Xmake-dependency=0xd $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"

endif
ifeq ($(BUILD_SPEC),PPC85XXgnu)
ifeq ($(DEBUG_MODE),1)
DEBUGFLAGS_Assembler = -g
else
DEBUGFLAGS_Assembler = -O2 -fstrength-reduce -fno-builtin
endif
$(OBJ_DIR)/%.o : $(SRC_DIR)/%.s
	$(TRACE_FLAG)echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_Assembler) $(CC_ARCH_SPEC) -ansi   -xassembler-with-cpp -MD -MP $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"

endif
ifeq ($(BUILD_SPEC),PPC85XXsfdiab)
ifeq ($(DEBUG_MODE),1)
DEBUGFLAGS_Assembler = -g
else
DEBUGFLAGS_Assembler = -XO -Xsize-opt
endif
$(OBJ_DIR)/%.o : $(SRC_DIR)/%.s
	$(TRACE_FLAG)echo "building $@"; $(TOOL_PATH)dcc $(DEBUGFLAGS_Assembler) $(CC_ARCH_SPEC) -W:c:,-Xclib-optim-off -Xansi -Xlocal-data-area-static-only -Xpreprocess-assembly -Xcpp-no-space  -Xmake-dependency=0xd $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"

endif
ifeq ($(BUILD_SPEC),PPC85XXsfgnu)
ifeq ($(DEBUG_MODE),1)
DEBUGFLAGS_Assembler = -g
else
DEBUGFLAGS_Assembler = -O2 -fstrength-reduce -fno-builtin
endif
$(OBJ_DIR)/%.o : $(SRC_DIR)/%.s
	$(TRACE_FLAG)echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_Assembler) $(CC_ARCH_SPEC) -ansi   -xassembler-with-cpp -MD -MP $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"

endif
ifeq ($(BUILD_SPEC),PPC860sfdiab)
ifeq ($(DEBUG_MODE),1)
DEBUGFLAGS_Assembler = -g
else
DEBUGFLAGS_Assembler = -XO -Xsize-opt
endif
$(OBJ_DIR)/%.o : $(SRC_DIR)/%.s
	$(TRACE_FLAG)echo "building $@"; $(TOOL_PATH)dcc $(DEBUGFLAGS_Assembler) $(CC_ARCH_SPEC) -W:c:,-Xclib-optim-off -Xansi -Xlocal-data-area-static-only -Xpreprocess-assembly -Xcpp-no-space  -Xmake-dependency=0xd $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"

endif
ifeq ($(BUILD_SPEC),PPC860sfgnu)
ifeq ($(DEBUG_MODE),1)
DEBUGFLAGS_Assembler = -g
else
DEBUGFLAGS_Assembler = -O2 -fstrength-reduce -fno-builtin
endif
$(OBJ_DIR)/%.o : $(SRC_DIR)/%.s
	$(TRACE_FLAG)echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_Assembler) $(CC_ARCH_SPEC) -ansi   -xassembler-with-cpp -MD -MP $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"

endif
ifeq ($(BUILD_SPEC),SIMLINUXdiab)
ifeq ($(DEBUG_MODE),1)
DEBUGFLAGS_Assembler = -g
else
DEBUGFLAGS_Assembler = -XO -Xsize-opt
endif
$(OBJ_DIR)/%.o : $(SRC_DIR)/%.s
	$(TRACE_FLAG)echo "building $@"; $(TOOL_PATH)dcc $(DEBUGFLAGS_Assembler) $(CC_ARCH_SPEC) -W:c:,-Xclib-optim-off -Xansi -Xlocal-data-area-static-only -Xpreprocess-assembly -Xcpp-no-space -Wa,-Xmnem-mit -Xmake-dependency=0xd $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"

endif
ifeq ($(BUILD_SPEC),SIMLINUXgnu)
ifeq ($(DEBUG_MODE),1)
DEBUGFLAGS_Assembler = -g
else
DEBUGFLAGS_Assembler = -O2 -nostdlib -fno-builtin -fno-defer-pop
endif
$(OBJ_DIR)/%.o : $(SRC_DIR)/%.s
	$(TRACE_FLAG)echo "building $@"; $(TOOL_PATH)ccpentium $(DEBUGFLAGS_Assembler) $(CC_ARCH_SPEC) -ansi   -xassembler-with-cpp -MD -MP $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"

endif
ifeq ($(BUILD_SPEC),SIMNTdiab)
ifeq ($(DEBUG_MODE),1)
DEBUGFLAGS_Assembler = -g
else
DEBUGFLAGS_Assembler = -XO -Xsize-opt
endif
$(OBJ_DIR)/%.o : $(SRC_DIR)/%.s
	$(TRACE_FLAG)echo "building $@"; $(TOOL_PATH)dcc $(DEBUGFLAGS_Assembler) $(CC_ARCH_SPEC) -W:c:,-Xclib-optim-off -Xansi -Xlocal-data-area-static-only -Xpreprocess-assembly -Xcpp-no-space -Wa,-Xmnem-mit -Xmake-dependency=0xd $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"

endif
ifeq ($(BUILD_SPEC),SIMNTgnu)
ifeq ($(DEBUG_MODE),1)
DEBUGFLAGS_Assembler = -g
else
DEBUGFLAGS_Assembler = -O2 -nostdlib -fno-builtin -fno-defer-pop
endif
$(OBJ_DIR)/%.o : $(SRC_DIR)/%.s
	$(TRACE_FLAG)echo "building $@"; $(TOOL_PATH)ccpentium $(DEBUGFLAGS_Assembler) $(CC_ARCH_SPEC) -ansi   -xassembler-with-cpp -MD -MP $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"

endif
ifeq ($(BUILD_SPEC),SIMSPARCSOLARISdiab)
ifeq ($(DEBUG_MODE),1)
DEBUGFLAGS_Assembler = -g
else
DEBUGFLAGS_Assembler = -XO -Xsize-opt
endif
$(OBJ_DIR)/%.o : $(SRC_DIR)/%.s
	$(TRACE_FLAG)echo "building $@"; $(TOOL_PATH)dcc $(DEBUGFLAGS_Assembler) $(CC_ARCH_SPEC) -W:c:,-Xclib-optim-off -Xansi -Xlocal-data-area-static-only -Xpreprocess-assembly -Xcpp-no-space  -Xmake-dependency=0xd $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"

endif
ifeq ($(BUILD_SPEC),SIMSPARCSOLARISgnu)
ifeq ($(DEBUG_MODE),1)
DEBUGFLAGS_Assembler = -g
else
DEBUGFLAGS_Assembler = -O2 -fstrength-reduce -fno-builtin
endif
$(OBJ_DIR)/%.o : $(SRC_DIR)/%.s
	$(TRACE_FLAG)echo "building $@"; $(TOOL_PATH)ccsparc $(DEBUGFLAGS_Assembler) $(CC_ARCH_SPEC) -ansi   -xassembler-with-cpp -MD -MP $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"

endif

ifeq ($(BUILD_SPEC),PPC32diab)
ifeq ($(DEBUG_MODE),1)
DEBUGFLAGS_WPILib = 
else
DEBUGFLAGS_WPILib = 
endif
$(OBJ_DIR)/WPILib.a : $(OBJECTS) $(SUB_OBJECTS)
	$(TRACE_FLAG)echo "building $@"; $(TOOL_PATH)dar crus "$@" $(OBJECTS) $(SUB_OBJECTS)

target_WPILib : subdirs_all check_objectdir $(OBJ_DIR)/WPILib.a
endif
ifeq ($(BUILD_SPEC),PPC32gnu)
ifeq ($(DEBUG_MODE),1)
DEBUGFLAGS_WPILib = 
else
DEBUGFLAGS_WPILib = 
endif
$(OBJ_DIR)/WPILib.a : $(OBJECTS) $(SUB_OBJECTS)
	$(TRACE_FLAG)echo "building $@"; $(TOOL_PATH)arppc crus "$@" $(OBJECTS) $(SUB_OBJECTS)

target_WPILib : subdirs_all check_objectdir $(OBJ_DIR)/WPILib.a
endif
ifeq ($(BUILD_SPEC),PPC32sfdiab)
ifeq ($(DEBUG_MODE),1)
DEBUGFLAGS_WPILib = 
else
DEBUGFLAGS_WPILib = 
endif
$(OBJ_DIR)/WPILib.a : $(OBJECTS) $(SUB_OBJECTS)
	$(TRACE_FLAG)echo "building $@"; $(TOOL_PATH)dar crus "$@" $(OBJECTS) $(SUB_OBJECTS)

target_WPILib : subdirs_all check_objectdir $(OBJ_DIR)/WPILib.a
endif
ifeq ($(BUILD_SPEC),PPC32sfgnu)
ifeq ($(DEBUG_MODE),1)
DEBUGFLAGS_WPILib = 
else
DEBUGFLAGS_WPILib = 
endif
$(OBJ_DIR)/WPILib.a : $(OBJECTS) $(SUB_OBJECTS)
	$(TRACE_FLAG)echo "building $@"; $(TOOL_PATH)arppc crus "$@" $(OBJECTS) $(SUB_OBJECTS)

target_WPILib : subdirs_all check_objectdir $(OBJ_DIR)/WPILib.a
endif
ifeq ($(BUILD_SPEC),PPC403diab)
ifeq ($(DEBUG_MODE),1)
DEBUGFLAGS_WPILib = 
else
DEBUGFLAGS_WPILib = 
endif
$(OBJ_DIR)/WPILib.a : $(OBJECTS) $(SUB_OBJECTS)
	$(TRACE_FLAG)echo "building $@"; $(TOOL_PATH)dar crus "$@" $(OBJECTS) $(SUB_OBJECTS)

target_WPILib : subdirs_all check_objectdir $(OBJ_DIR)/WPILib.a
endif
ifeq ($(BUILD_SPEC),PPC403gnu)
ifeq ($(DEBUG_MODE),1)
DEBUGFLAGS_WPILib = 
else
DEBUGFLAGS_WPILib = 
endif
$(OBJ_DIR)/WPILib.a : $(OBJECTS) $(SUB_OBJECTS)
	$(TRACE_FLAG)echo "building $@"; $(TOOL_PATH)arppc crus "$@" $(OBJECTS) $(SUB_OBJECTS)

target_WPILib : subdirs_all check_objectdir $(OBJ_DIR)/WPILib.a
endif
ifeq ($(BUILD_SPEC),PPC405diab)
ifeq ($(DEBUG_MODE),1)
DEBUGFLAGS_WPILib = 
else
DEBUGFLAGS_WPILib = 
endif
$(OBJ_DIR)/WPILib.a : $(OBJECTS) $(SUB_OBJECTS)
	$(TRACE_FLAG)echo "building $@"; $(TOOL_PATH)dar crus "$@" $(OBJECTS) $(SUB_OBJECTS)

target_WPILib : subdirs_all check_objectdir $(OBJ_DIR)/WPILib.a
endif
ifeq ($(BUILD_SPEC),PPC405gnu)
ifeq ($(DEBUG_MODE),1)
DEBUGFLAGS_WPILib = 
else
DEBUGFLAGS_WPILib = 
endif
$(OBJ_DIR)/WPILib.a : $(OBJECTS) $(SUB_OBJECTS)
	$(TRACE_FLAG)echo "building $@"; $(TOOL_PATH)arppc crus "$@" $(OBJECTS) $(SUB_OBJECTS)

target_WPILib : subdirs_all check_objectdir $(OBJ_DIR)/WPILib.a
endif
ifeq ($(BUILD_SPEC),PPC405sfdiab)
ifeq ($(DEBUG_MODE),1)
DEBUGFLAGS_WPILib = 
else
DEBUGFLAGS_WPILib = 
endif
$(OBJ_DIR)/WPILib.a : $(OBJECTS) $(SUB_OBJECTS)
	$(TRACE_FLAG)echo "building $@"; $(TOOL_PATH)dar crus "$@" $(OBJECTS) $(SUB_OBJECTS)

target_WPILib : subdirs_all check_objectdir $(OBJ_DIR)/WPILib.a
endif
ifeq ($(BUILD_SPEC),PPC405sfgnu)
ifeq ($(DEBUG_MODE),1)
DEBUGFLAGS_WPILib = 
else
DEBUGFLAGS_WPILib = 
endif
$(OBJ_DIR)/WPILib.a : $(OBJECTS) $(SUB_OBJECTS)
	$(TRACE_FLAG)echo "building $@"; $(TOOL_PATH)arppc crus "$@" $(OBJECTS) $(SUB_OBJECTS)

target_WPILib : subdirs_all check_objectdir $(OBJ_DIR)/WPILib.a
endif
ifeq ($(BUILD_SPEC),PPC440diab)
ifeq ($(DEBUG_MODE),1)
DEBUGFLAGS_WPILib = 
else
DEBUGFLAGS_WPILib = 
endif
$(OBJ_DIR)/WPILib.a : $(OBJECTS) $(SUB_OBJECTS)
	$(TRACE_FLAG)echo "building $@"; $(TOOL_PATH)dar crus "$@" $(OBJECTS) $(SUB_OBJECTS)

target_WPILib : subdirs_all check_objectdir $(OBJ_DIR)/WPILib.a
endif
ifeq ($(BUILD_SPEC),PPC440gnu)
ifeq ($(DEBUG_MODE),1)
DEBUGFLAGS_WPILib = 
else
DEBUGFLAGS_WPILib = 
endif
$(OBJ_DIR)/WPILib.a : $(OBJECTS) $(SUB_OBJECTS)
	$(TRACE_FLAG)echo "building $@"; $(TOOL_PATH)arppc crus "$@" $(OBJECTS) $(SUB_OBJECTS)

target_WPILib : subdirs_all check_objectdir $(OBJ_DIR)/WPILib.a
endif
ifeq ($(BUILD_SPEC),PPC440sfdiab)
ifeq ($(DEBUG_MODE),1)
DEBUGFLAGS_WPILib = 
else
DEBUGFLAGS_WPILib = 
endif
$(OBJ_DIR)/WPILib.a : $(OBJECTS) $(SUB_OBJECTS)
	$(TRACE_FLAG)echo "building $@"; $(TOOL_PATH)dar crus "$@" $(OBJECTS) $(SUB_OBJECTS)

target_WPILib : subdirs_all check_objectdir $(OBJ_DIR)/WPILib.a
endif
ifeq ($(BUILD_SPEC),PPC440sfgnu)
ifeq ($(DEBUG_MODE),1)
DEBUGFLAGS_WPILib = 
else
DEBUGFLAGS_WPILib = 
endif
$(OBJ_DIR)/WPILib.a : $(OBJECTS) $(SUB_OBJECTS)
	$(TRACE_FLAG)echo "building $@"; $(TOOL_PATH)arppc crus "$@" $(OBJECTS) $(SUB_OBJECTS)

target_WPILib : subdirs_all check_objectdir $(OBJ_DIR)/WPILib.a
endif
ifeq ($(BUILD_SPEC),PPC603diab)
ifeq ($(DEBUG_MODE),1)
DEBUGFLAGS_WPILib = 
else
DEBUGFLAGS_WPILib = 
endif
$(OBJ_DIR)/WPILib.a : $(OBJECTS) $(SUB_OBJECTS)
	$(TRACE_FLAG)echo "building $@"; $(TOOL_PATH)dar crus "$@" $(OBJECTS) $(SUB_OBJECTS)

target_WPILib : subdirs_all check_objectdir $(OBJ_DIR)/WPILib.a
endif
ifeq ($(BUILD_SPEC),PPC603gnu)
ifeq ($(DEBUG_MODE),1)
DEBUGFLAGS_WPILib = 
else
DEBUGFLAGS_WPILib = 
endif
$(OBJ_DIR)/WPILib.a : $(OBJECTS) $(SUB_OBJECTS)
	$(TRACE_FLAG)echo "building $@"; $(TOOL_PATH)arppc crus "$@" $(OBJECTS) $(SUB_OBJECTS)

target_WPILib : subdirs_all check_objectdir $(OBJ_DIR)/WPILib.a
endif
ifeq ($(BUILD_SPEC),PPC604diab)
ifeq ($(DEBUG_MODE),1)
DEBUGFLAGS_WPILib = 
else
DEBUGFLAGS_WPILib = 
endif
$(OBJ_DIR)/WPILib.a : $(OBJECTS) $(SUB_OBJECTS)
	$(TRACE_FLAG)echo "building $@"; $(TOOL_PATH)dar crus "$@" $(OBJECTS) $(SUB_OBJECTS)

target_WPILib : subdirs_all check_objectdir $(OBJ_DIR)/WPILib.a
endif
ifeq ($(BUILD_SPEC),PPC604gnu)
ifeq ($(DEBUG_MODE),1)
DEBUGFLAGS_WPILib = 
else
DEBUGFLAGS_WPILib = 
endif
$(OBJ_DIR)/WPILib.a : $(OBJECTS) $(SUB_OBJECTS)
	$(TRACE_FLAG)echo "building $@"; $(TOOL_PATH)arppc crus "$@" $(OBJECTS) $(SUB_OBJECTS)

target_WPILib : subdirs_all check_objectdir $(OBJ_DIR)/WPILib.a
endif
ifeq ($(BUILD_SPEC),PPC85XXdiab)
ifeq ($(DEBUG_MODE),1)
DEBUGFLAGS_WPILib = 
else
DEBUGFLAGS_WPILib = 
endif
$(OBJ_DIR)/WPILib.a : $(OBJECTS) $(SUB_OBJECTS)
	$(TRACE_FLAG)echo "building $@"; $(TOOL_PATH)dar crus "$@" $(OBJECTS) $(SUB_OBJECTS)

target_WPILib : subdirs_all check_objectdir $(OBJ_DIR)/WPILib.a
endif
ifeq ($(BUILD_SPEC),PPC85XXgnu)
ifeq ($(DEBUG_MODE),1)
DEBUGFLAGS_WPILib = 
else
DEBUGFLAGS_WPILib = 
endif
$(OBJ_DIR)/WPILib.a : $(OBJECTS) $(SUB_OBJECTS)
	$(TRACE_FLAG)echo "building $@"; $(TOOL_PATH)arppc crus "$@" $(OBJECTS) $(SUB_OBJECTS)

target_WPILib : subdirs_all check_objectdir $(OBJ_DIR)/WPILib.a
endif
ifeq ($(BUILD_SPEC),PPC85XXsfdiab)
ifeq ($(DEBUG_MODE),1)
DEBUGFLAGS_WPILib = 
else
DEBUGFLAGS_WPILib = 
endif
$(OBJ_DIR)/WPILib.a : $(OBJECTS) $(SUB_OBJECTS)
	$(TRACE_FLAG)echo "building $@"; $(TOOL_PATH)dar crus "$@" $(OBJECTS) $(SUB_OBJECTS)

target_WPILib : subdirs_all check_objectdir $(OBJ_DIR)/WPILib.a
endif
ifeq ($(BUILD_SPEC),PPC85XXsfgnu)
ifeq ($(DEBUG_MODE),1)
DEBUGFLAGS_WPILib = 
else
DEBUGFLAGS_WPILib = 
endif
$(OBJ_DIR)/WPILib.a : $(OBJECTS) $(SUB_OBJECTS)
	$(TRACE_FLAG)echo "building $@"; $(TOOL_PATH)arppc crus "$@" $(OBJECTS) $(SUB_OBJECTS)

target_WPILib : subdirs_all check_objectdir $(OBJ_DIR)/WPILib.a
endif
ifeq ($(BUILD_SPEC),PPC860sfdiab)
ifeq ($(DEBUG_MODE),1)
DEBUGFLAGS_WPILib = 
else
DEBUGFLAGS_WPILib = 
endif
$(OBJ_DIR)/WPILib.a : $(OBJECTS) $(SUB_OBJECTS)
	$(TRACE_FLAG)echo "building $@"; $(TOOL_PATH)dar crus "$@" $(OBJECTS) $(SUB_OBJECTS)

target_WPILib : subdirs_all check_objectdir $(OBJ_DIR)/WPILib.a
endif
ifeq ($(BUILD_SPEC),PPC860sfgnu)
ifeq ($(DEBUG_MODE),1)
DEBUGFLAGS_WPILib = 
else
DEBUGFLAGS_WPILib = 
endif
$(OBJ_DIR)/WPILib.a : $(OBJECTS) $(SUB_OBJECTS)
	$(TRACE_FLAG)echo "building $@"; $(TOOL_PATH)arppc crus "$@" $(OBJECTS) $(SUB_OBJECTS)

target_WPILib : subdirs_all check_objectdir $(OBJ_DIR)/WPILib.a
endif
ifeq ($(BUILD_SPEC),SIMLINUXdiab)
ifeq ($(DEBUG_MODE),1)
DEBUGFLAGS_WPILib = 
else
DEBUGFLAGS_WPILib = 
endif
$(OBJ_DIR)/WPILib.a : $(OBJECTS) $(SUB_OBJECTS)
	$(TRACE_FLAG)echo "building $@"; $(TOOL_PATH)dar crus "$@" $(OBJECTS) $(SUB_OBJECTS)

target_WPILib : subdirs_all check_objectdir $(OBJ_DIR)/WPILib.a
endif
ifeq ($(BUILD_SPEC),SIMLINUXgnu)
ifeq ($(DEBUG_MODE),1)
DEBUGFLAGS_WPILib = 
else
DEBUGFLAGS_WPILib = 
endif
$(OBJ_DIR)/WPILib.a : $(OBJECTS) $(SUB_OBJECTS)
	$(TRACE_FLAG)echo "building $@"; $(TOOL_PATH)arpentium crus "$@" $(OBJECTS) $(SUB_OBJECTS)

target_WPILib : subdirs_all check_objectdir $(OBJ_DIR)/WPILib.a
endif
ifeq ($(BUILD_SPEC),SIMNTdiab)
ifeq ($(DEBUG_MODE),1)
DEBUGFLAGS_WPILib = 
else
DEBUGFLAGS_WPILib = 
endif
$(OBJ_DIR)/WPILib.a : $(OBJECTS) $(SUB_OBJECTS)
	$(TRACE_FLAG)echo "building $@"; $(TOOL_PATH)dar crus "$@" $(OBJECTS) $(SUB_OBJECTS)

target_WPILib : subdirs_all check_objectdir $(OBJ_DIR)/WPILib.a
endif
ifeq ($(BUILD_SPEC),SIMNTgnu)
ifeq ($(DEBUG_MODE),1)
DEBUGFLAGS_WPILib = 
else
DEBUGFLAGS_WPILib = 
endif
$(OBJ_DIR)/WPILib.a : $(OBJECTS) $(SUB_OBJECTS)
	$(TRACE_FLAG)echo "building $@"; $(TOOL_PATH)arpentium crus "$@" $(OBJECTS) $(SUB_OBJECTS)

target_WPILib : subdirs_all check_objectdir $(OBJ_DIR)/WPILib.a
endif
ifeq ($(BUILD_SPEC),SIMSPARCSOLARISdiab)
ifeq ($(DEBUG_MODE),1)
DEBUGFLAGS_WPILib = 
else
DEBUGFLAGS_WPILib = 
endif
$(OBJ_DIR)/WPILib.a : $(OBJECTS) $(SUB_OBJECTS)
	$(TRACE_FLAG)echo "building $@"; $(TOOL_PATH)dar crus "$@" $(OBJECTS) $(SUB_OBJECTS)

target_WPILib : subdirs_all check_objectdir $(OBJ_DIR)/WPILib.a
endif
ifeq ($(BUILD_SPEC),SIMSPARCSOLARISgnu)
ifeq ($(DEBUG_MODE),1)
DEBUGFLAGS_WPILib = 
else
DEBUGFLAGS_WPILib = 
endif
$(OBJ_DIR)/WPILib.a : $(OBJECTS) $(SUB_OBJECTS)
	$(TRACE_FLAG)echo "building $@"; $(TOOL_PATH)arsparc crus "$@" $(OBJECTS) $(SUB_OBJECTS)

target_WPILib : subdirs_all check_objectdir $(OBJ_DIR)/WPILib.a
endif




-include *.makefile

main_all : check_objectdir external_build $(PROJECT_TARGETS)
	@echo "make: built targets of `pwd`"

check_objectdir :
	@if [ ! -d "$(OBJ_DIR)" ]; then\
		mkdir -p $(OBJ_DIR);\
	fi

# entry point for extending the build
external_build ::
	@echo ""

# main entry point for pre processing prior to the recursion
pre_recursion ::
	@echo ""

# main entry point for post processing after the recursion
post_recursion ::
	@echo ""

# main entry point for pre processing prior to the build
pre_build :: $(PRE_BUILD_STEP) generate_sources
	@echo ""

# entry point for generating sources prior to the build
generate_sources ::
	@echo ""

# main entry point for post processing after the build
post_build :: $(POST_BUILD_STEP) deploy_output
	@echo ""

# entry point for deploying output after the build
deploy_output ::
	@echo ""

# recursive make in SUBDIRS
subdirs_all :
	@_PWD=`pwd`;\
	for dir in _dummy_ $(SUBDIRS); do\
		if [ "$$dir" = "_dummy_" ]; then\
			continue ;\
		fi;\
		if [ ! -d "$$dir" ]; then\
			continue ;\
		fi;\
		echo "Recursive make: Changing to Directory '$$dir'";\
		cd "$$dir";\
		"$(MAKE)" -f "$(MAKEFILE)" $(MFLAGS) all || exit;\
		echo "Recursive make: Changing back to Directory '$$_PWD'";\
		cd "$$_PWD";\
	done

clean ::
	@_PWD=`pwd`;\
	for dir in _dummy_ $(SUBDIRS); do\
		if [ "$$dir" = "_dummy_" ]; then\
			continue ;\
		fi;\
		if [ ! -d "$$dir" ]; then\
			continue ;\
		fi;\
		echo "Recursive make: Changing to Directory '$$dir'";\
		cd "$$dir";\
		"$(MAKE)" -f "$(MAKEFILE)" $(MFLAGS) $@ || exit;\
		echo "Recursive make: Changing back to Directory '$$_PWD'";\
		cd "$$_PWD";\
	done

clean :: external_clean $(CLEAN_STEP) _clean

# entry point for extending the build clean
external_clean ::
	@echo ""

_clean :
	@echo "make: removing targets and objects of `pwd`";\
	rm -f $(OBJECTS) $(PROJECT_TARGETS) $(DEP_FILES) $(wildcard $(OBJ_DIR)/*.unstripped) $(wildcard $(OBJ_DIR)/ctdt.*)

build_all_specs :
	@echo "building target default for ALL build-specs";\
	for spec in _dummy_ $(ALL_BUILD_SPECS); do\
		if [ "$$spec" = "_dummy_" ]; then\
			continue ;\
		fi;\
		echo " ";\
		echo "building all for build-spec '$$spec'";\
		"$(MAKE)" -f "$(MAKEFILE)" $(MFLAGS) BUILD_SPEC=$$spec DEBUG_MODE=$(DEBUG_MODE) TRACE=$(TRACE) || exit;\
	done

clean_all_specs :
	@echo "building target clean for ALL build-specs";\
	for spec in _dummy_ $(ALL_BUILD_SPECS); do\
		if [ "$$spec" = "_dummy_" ]; then\
			continue ;\
		fi;\
		echo " ";\
		echo "building clean for build-spec '$$spec'";\
		"$(MAKE)" -f "$(MAKEFILE)" $(MFLAGS) BUILD_SPEC=$$spec DEBUG_MODE=$(DEBUG_MODE) TRACE=$(TRACE) clean || exit;\
	done

build_enabled_specs :
	@echo "building target default for ENABLED build-specs";\
	for spec in _dummy_ $(ENABLED_BUILD_SPECS); do\
		if [ "$$spec" = "_dummy_" ]; then\
			continue ;\
		fi;\
		echo " ";\
		echo "building all for build-spec '$$spec'";\
		"$(MAKE)" -f "$(MAKEFILE)" $(MFLAGS) BUILD_SPEC=$$spec DEBUG_MODE=$(DEBUG_MODE) TRACE=$(TRACE) || exit;\
	done

clean_enabled_specs :
	@echo "building target clean for ENABLED build-specs";\
	for spec in _dummy_ $(ENABLED_BUILD_SPECS); do\
		if [ "$$spec" = "_dummy_" ]; then\
			continue ;\
		fi;\
		echo " ";\
		echo "building clean for build-spec '$$spec'";\
		"$(MAKE)" -f "$(MAKEFILE)" $(MFLAGS) BUILD_SPEC=$$spec DEBUG_MODE=$(DEBUG_MODE) TRACE=$(TRACE) clean || exit;\
	done
