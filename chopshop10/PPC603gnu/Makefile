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

all : pre_build main_all post_build

_clean ::
	@echo "make: removing targets and objects of `pwd`"

TRACE=0
TRACEON=$(TRACE:0=@)
TRACE_FLAG=$(TRACEON:1=)

MAKEFILE := Makefile

FLEXIBLE_BUILD := 1

BUILD_SPEC = PPC603gnu
DEBUG_MODE = 1
ifeq ($(DEBUG_MODE),1)
MODE_DIR := Debug
else
MODE_DIR := NonDebug
endif
OBJ_DIR := .
PRJ_ROOT_DIR := W:/workspace/chopshop10
WS_ROOT_DIR := W:/workspace



#Global Build Macros
PROJECT_TYPE = DKM
DEFINES = 
EXPAND_DBG = 0


#BuildSpec specific Build Macros
VX_CPU_FAMILY = ppc
CPU = PPC603
TOOL_FAMILY = gnu
TOOL = gnu
TOOL_PATH = 
CC_ARCH_SPEC = -mcpu=603 -mstrict-align -mno-implicit-fp -mlongcall
LIBPATH = 
LIBS = 

IDE_INCLUDES = -I$(WIND_BASE)/target/h -I$(WIND_BASE)/target/h/WPILib -I$(WIND_BASE)/target/h/wrn/coreip -I$(WIND_BASE)/target/h/WPILib/Vision -I$(WIND_BASE)/target/h/WPILib/Vision2009 

IDE_LIBRARIES = $(WIND_BASE)/target/lib/WPILib.a 



#BuildTool flags
ifeq ($(DEBUG_MODE),1)
DEBUGFLAGS_C-Compiler = -g
DEBUGFLAGS_C++-Compiler = -g
DEBUGFLAGS_Linker = -g
DEBUGFLAGS_Partial-Image-Linker = 
DEBUGFLAGS_Librarian = 
DEBUGFLAGS_Assembler = -g
else
DEBUGFLAGS_C-Compiler = -O2 -fstrength-reduce -fno-builtin
DEBUGFLAGS_C++-Compiler = -O2 -fstrength-reduce -fno-builtin
DEBUGFLAGS_Linker = -O2 -fstrength-reduce -fno-builtin
DEBUGFLAGS_Partial-Image-Linker = 
DEBUGFLAGS_Librarian = 
DEBUGFLAGS_Assembler = -O2 -fstrength-reduce -fno-builtin
endif


#Project Targets
PROJECT_TARGETS = chopshop10/$(MODE_DIR)/chopshop10.out


#Rules

# chopshop10
ifeq ($(DEBUG_MODE),1)
chopshop10/$(MODE_DIR)/% : DEBUGFLAGS_C-Compiler = -g
chopshop10/$(MODE_DIR)/% : DEBUGFLAGS_C++-Compiler = -g
chopshop10/$(MODE_DIR)/% : DEBUGFLAGS_Linker = -g
chopshop10/$(MODE_DIR)/% : DEBUGFLAGS_Partial-Image-Linker = 
chopshop10/$(MODE_DIR)/% : DEBUGFLAGS_Librarian = 
chopshop10/$(MODE_DIR)/% : DEBUGFLAGS_Assembler = -g
else
chopshop10/$(MODE_DIR)/% : DEBUGFLAGS_C-Compiler = -O2 -fstrength-reduce -fno-builtin
chopshop10/$(MODE_DIR)/% : DEBUGFLAGS_C++-Compiler = -O2 -fstrength-reduce -fno-builtin
chopshop10/$(MODE_DIR)/% : DEBUGFLAGS_Linker = -O2 -fstrength-reduce -fno-builtin
chopshop10/$(MODE_DIR)/% : DEBUGFLAGS_Partial-Image-Linker = 
chopshop10/$(MODE_DIR)/% : DEBUGFLAGS_Librarian = 
chopshop10/$(MODE_DIR)/% : DEBUGFLAGS_Assembler = -O2 -fstrength-reduce -fno-builtin
endif
chopshop10/$(MODE_DIR)/% : IDE_INCLUDES = -I$(WIND_BASE)/target/h -I$(WIND_BASE)/target/h/WPILib -I$(WIND_BASE)/target/h/wrn/coreip -I$(WIND_BASE)/target/h/WPILib/Vision -I$(WIND_BASE)/target/h/WPILib/Vision2009 
chopshop10/$(MODE_DIR)/% : IDE_LIBRARIES = $(WIND_BASE)/target/lib/WPILib.a 
chopshop10/$(MODE_DIR)/% : PROJECT_TYPE = DKM
chopshop10/$(MODE_DIR)/% : DEFINES = 
chopshop10/$(MODE_DIR)/% : EXPAND_DBG = 0
chopshop10/$(MODE_DIR)/% : VX_CPU_FAMILY = ppc
chopshop10/$(MODE_DIR)/% : CPU = PPC603
chopshop10/$(MODE_DIR)/% : TOOL_FAMILY = gnu
chopshop10/$(MODE_DIR)/% : TOOL = gnu
chopshop10/$(MODE_DIR)/% : TOOL_PATH = 
chopshop10/$(MODE_DIR)/% : CC_ARCH_SPEC = -mcpu=603 -mstrict-align -mno-implicit-fp -mlongcall
chopshop10/$(MODE_DIR)/% : LIBPATH = 
chopshop10/$(MODE_DIR)/% : LIBS = 
chopshop10/$(MODE_DIR)/% : OBJ_DIR := chopshop10/$(MODE_DIR)

chopshop10/$(MODE_DIR)/Objects/chopshop10/Autonomous166.o : W:/workspace/chopshop10/Autonomous166.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP -mlongcall $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


chopshop10/$(MODE_DIR)/Objects/chopshop10/Banner166.o : W:/workspace/chopshop10/Banner166.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP -mlongcall $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


chopshop10/$(MODE_DIR)/Objects/chopshop10/CANDrive166.o : W:/workspace/chopshop10/CANDrive166.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP -mlongcall $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


chopshop10/$(MODE_DIR)/Objects/chopshop10/CANJaguar.o : W:/workspace/chopshop10/CANJaguar.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP -mlongcall $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


chopshop10/$(MODE_DIR)/Objects/chopshop10/DashboardDataSender.o : W:/workspace/chopshop10/DashboardDataSender.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP -mlongcall $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


chopshop10/$(MODE_DIR)/Objects/chopshop10/EBrake166.o : W:/workspace/chopshop10/EBrake166.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP -mlongcall $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


chopshop10/$(MODE_DIR)/Objects/chopshop10/HealthMon166.o : W:/workspace/chopshop10/HealthMon166.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP -mlongcall $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


chopshop10/$(MODE_DIR)/Objects/chopshop10/Inclinometer.o : W:/workspace/chopshop10/Inclinometer.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP -mlongcall $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


chopshop10/$(MODE_DIR)/Objects/chopshop10/Kicker166.o : W:/workspace/chopshop10/Kicker166.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP -mlongcall $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


chopshop10/$(MODE_DIR)/Objects/chopshop10/LiftCan166.o : W:/workspace/chopshop10/LiftCan166.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP -mlongcall $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


chopshop10/$(MODE_DIR)/Objects/chopshop10/MemoryLog166.o : W:/workspace/chopshop10/MemoryLog166.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP -mlongcall $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


chopshop10/$(MODE_DIR)/Objects/chopshop10/Pneumatics166.o : W:/workspace/chopshop10/Pneumatics166.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP -mlongcall $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


chopshop10/$(MODE_DIR)/Objects/chopshop10/Proxy166.o : W:/workspace/chopshop10/Proxy166.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP -mlongcall $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


chopshop10/$(MODE_DIR)/Objects/chopshop10/Robot166.o : W:/workspace/chopshop10/Robot166.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP -mlongcall $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


chopshop10/$(MODE_DIR)/Objects/chopshop10/RobotCamera166.o : W:/workspace/chopshop10/RobotCamera166.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP -mlongcall $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


chopshop10/$(MODE_DIR)/Objects/chopshop10/Runtime166.o : W:/workspace/chopshop10/Runtime166.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP -mlongcall $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


chopshop10/$(MODE_DIR)/Objects/chopshop10/Sonar166.o : W:/workspace/chopshop10/Sonar166.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP -mlongcall $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


chopshop10/$(MODE_DIR)/Objects/chopshop10/Target.o : W:/workspace/chopshop10/Target.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP -mlongcall $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


chopshop10/$(MODE_DIR)/Objects/chopshop10/Target166.o : W:/workspace/chopshop10/Target166.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP -mlongcall $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


chopshop10/$(MODE_DIR)/Objects/chopshop10/TaskTemplate.o : W:/workspace/chopshop10/TaskTemplate.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP -mlongcall $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


chopshop10/$(MODE_DIR)/Objects/chopshop10/Team166Task.o : W:/workspace/chopshop10/Team166Task.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP -mlongcall $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


chopshop10/$(MODE_DIR)/Objects/chopshop10/Vacuum.o : W:/workspace/chopshop10/Vacuum.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP -mlongcall $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


chopshop10/$(MODE_DIR)/Objects/chopshop10/Vision166.o : W:/workspace/chopshop10/Vision166.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP -mlongcall $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


OBJECTS_chopshop10 = chopshop10/$(MODE_DIR)/Objects/chopshop10/Autonomous166.o \
	 chopshop10/$(MODE_DIR)/Objects/chopshop10/Banner166.o \
	 chopshop10/$(MODE_DIR)/Objects/chopshop10/CANDrive166.o \
	 chopshop10/$(MODE_DIR)/Objects/chopshop10/CANJaguar.o \
	 chopshop10/$(MODE_DIR)/Objects/chopshop10/DashboardDataSender.o \
	 chopshop10/$(MODE_DIR)/Objects/chopshop10/EBrake166.o \
	 chopshop10/$(MODE_DIR)/Objects/chopshop10/HealthMon166.o \
	 chopshop10/$(MODE_DIR)/Objects/chopshop10/Inclinometer.o \
	 chopshop10/$(MODE_DIR)/Objects/chopshop10/Kicker166.o \
	 chopshop10/$(MODE_DIR)/Objects/chopshop10/LiftCan166.o \
	 chopshop10/$(MODE_DIR)/Objects/chopshop10/MemoryLog166.o \
	 chopshop10/$(MODE_DIR)/Objects/chopshop10/Pneumatics166.o \
	 chopshop10/$(MODE_DIR)/Objects/chopshop10/Proxy166.o \
	 chopshop10/$(MODE_DIR)/Objects/chopshop10/Robot166.o \
	 chopshop10/$(MODE_DIR)/Objects/chopshop10/RobotCamera166.o \
	 chopshop10/$(MODE_DIR)/Objects/chopshop10/Runtime166.o \
	 chopshop10/$(MODE_DIR)/Objects/chopshop10/Sonar166.o \
	 chopshop10/$(MODE_DIR)/Objects/chopshop10/Target.o \
	 chopshop10/$(MODE_DIR)/Objects/chopshop10/Target166.o \
	 chopshop10/$(MODE_DIR)/Objects/chopshop10/TaskTemplate.o \
	 chopshop10/$(MODE_DIR)/Objects/chopshop10/Team166Task.o \
	 chopshop10/$(MODE_DIR)/Objects/chopshop10/Vacuum.o \
	 chopshop10/$(MODE_DIR)/Objects/chopshop10/Vision166.o

chopshop10/$(MODE_DIR)/chopshop10.out : $(OBJECTS_chopshop10)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@";rm -f "$@";nmppc $(OBJECTS_chopshop10) $(IDE_LIBRARIES) | tclsh $(WIND_BASE)/host/resource/hutils/tcl/munch.tcl -c ppc > $(OBJ_DIR)/ctdt.c; $(TOOL_PATH)ccppc $(DEBUGFLAGS_Linker) $(CC_ARCH_SPEC) -fdollars-in-identifiers -Wall $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES)  -o $(OBJ_DIR)/ctdt.o -c $(OBJ_DIR)/ctdt.c; $(TOOL_PATH)ccppc -r -nostdlib -Wl,-X -T $(WIND_BASE)/target/h/tool/gnu/ldscripts/link.OUT -o "$@" $(OBJ_DIR)/ctdt.o $(OBJECTS_chopshop10) $(IDE_LIBRARIES) $(LIBPATH) $(LIBS)  $(ADDED_LIBPATH) $(ADDED_LIBS) && if [ "$(EXPAND_DBG)" = "1" ]; then plink "$@";fi

chopshop10/$(MODE_DIR)/chopshop10_compile_file : $(FILE) ;

_clean :: chopshop10/$(MODE_DIR)/chopshop10_clean

chopshop10/$(MODE_DIR)/chopshop10_clean : 
	$(TRACE_FLAG)if [ -d "chopshop10" ]; then cd "chopshop10"; rm -rf $(MODE_DIR); fi

DEP_FILES := chopshop10/$(MODE_DIR)/Objects/chopshop10/Autonomous166.d chopshop10/$(MODE_DIR)/Objects/chopshop10/Banner166.d chopshop10/$(MODE_DIR)/Objects/chopshop10/CANDrive166.d \
	 chopshop10/$(MODE_DIR)/Objects/chopshop10/CANJaguar.d chopshop10/$(MODE_DIR)/Objects/chopshop10/DashboardDataSender.d chopshop10/$(MODE_DIR)/Objects/chopshop10/EBrake166.d \
	 chopshop10/$(MODE_DIR)/Objects/chopshop10/HealthMon166.d chopshop10/$(MODE_DIR)/Objects/chopshop10/Inclinometer.d chopshop10/$(MODE_DIR)/Objects/chopshop10/Kicker166.d \
	 chopshop10/$(MODE_DIR)/Objects/chopshop10/LiftCan166.d chopshop10/$(MODE_DIR)/Objects/chopshop10/MemoryLog166.d chopshop10/$(MODE_DIR)/Objects/chopshop10/Pneumatics166.d \
	 chopshop10/$(MODE_DIR)/Objects/chopshop10/Proxy166.d chopshop10/$(MODE_DIR)/Objects/chopshop10/Robot166.d chopshop10/$(MODE_DIR)/Objects/chopshop10/RobotCamera166.d \
	 chopshop10/$(MODE_DIR)/Objects/chopshop10/Runtime166.d chopshop10/$(MODE_DIR)/Objects/chopshop10/Sonar166.d chopshop10/$(MODE_DIR)/Objects/chopshop10/Target.d \
	 chopshop10/$(MODE_DIR)/Objects/chopshop10/Target166.d chopshop10/$(MODE_DIR)/Objects/chopshop10/TaskTemplate.d chopshop10/$(MODE_DIR)/Objects/chopshop10/Team166Task.d \
	 chopshop10/$(MODE_DIR)/Objects/chopshop10/Vacuum.d chopshop10/$(MODE_DIR)/Objects/chopshop10/Vision166.d
-include $(DEP_FILES)



-include $(PRJ_ROOT_DIR)/*.makefile

-include *.makefile

main_all : external_build $(PROJECT_TARGETS)
	@echo "make: built targets of `pwd`"

# entry point for extending the build
external_build ::
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

clean :: external_clean $(CLEAN_STEP) _clean

# entry point for extending the build clean
external_clean ::
	@echo ""
