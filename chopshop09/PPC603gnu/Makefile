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
PRJ_ROOT_DIR := W:/workspace/chopshop09
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

IDE_INCLUDES = -IW:/workspace/WPILib -I$(WIND_BASE)/target/h -I$(WIND_BASE)/target/h/WPILib -I$(WIND_BASE)/target/h/wrn/coreip 

IDE_LIBRARIES = $(WS_ROOT_DIR)/WPILib/PPC603gnu_DEBUG/WPILib.a 



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
PROJECT_TARGETS = chopshop09/$(MODE_DIR)/chopshop09.out


#Rules

# chopshop09
ifeq ($(DEBUG_MODE),1)
chopshop09/$(MODE_DIR)/% : DEBUGFLAGS_C-Compiler = -g
chopshop09/$(MODE_DIR)/% : DEBUGFLAGS_C++-Compiler = -g
chopshop09/$(MODE_DIR)/% : DEBUGFLAGS_Linker = -g
chopshop09/$(MODE_DIR)/% : DEBUGFLAGS_Partial-Image-Linker = 
chopshop09/$(MODE_DIR)/% : DEBUGFLAGS_Librarian = 
chopshop09/$(MODE_DIR)/% : DEBUGFLAGS_Assembler = -g
else
chopshop09/$(MODE_DIR)/% : DEBUGFLAGS_C-Compiler = -O2 -fstrength-reduce -fno-builtin
chopshop09/$(MODE_DIR)/% : DEBUGFLAGS_C++-Compiler = -O2 -fstrength-reduce -fno-builtin
chopshop09/$(MODE_DIR)/% : DEBUGFLAGS_Linker = -O2 -fstrength-reduce -fno-builtin
chopshop09/$(MODE_DIR)/% : DEBUGFLAGS_Partial-Image-Linker = 
chopshop09/$(MODE_DIR)/% : DEBUGFLAGS_Librarian = 
chopshop09/$(MODE_DIR)/% : DEBUGFLAGS_Assembler = -O2 -fstrength-reduce -fno-builtin
endif
chopshop09/$(MODE_DIR)/% : IDE_INCLUDES = -IW:/workspace/WPILib -I$(WIND_BASE)/target/h -I$(WIND_BASE)/target/h/WPILib -I$(WIND_BASE)/target/h/wrn/coreip 
chopshop09/$(MODE_DIR)/% : IDE_LIBRARIES = $(WS_ROOT_DIR)/WPILib/PPC603gnu_DEBUG/WPILib.a 
chopshop09/$(MODE_DIR)/% : PROJECT_TYPE = DKM
chopshop09/$(MODE_DIR)/% : DEFINES = 
chopshop09/$(MODE_DIR)/% : EXPAND_DBG = 0
chopshop09/$(MODE_DIR)/% : VX_CPU_FAMILY = ppc
chopshop09/$(MODE_DIR)/% : CPU = PPC603
chopshop09/$(MODE_DIR)/% : TOOL_FAMILY = gnu
chopshop09/$(MODE_DIR)/% : TOOL = gnu
chopshop09/$(MODE_DIR)/% : TOOL_PATH = 
chopshop09/$(MODE_DIR)/% : CC_ARCH_SPEC = -mcpu=603 -mstrict-align -mno-implicit-fp -mlongcall
chopshop09/$(MODE_DIR)/% : LIBPATH = 
chopshop09/$(MODE_DIR)/% : LIBS = 
chopshop09/$(MODE_DIR)/% : OBJ_DIR := chopshop09/$(MODE_DIR)

chopshop09/$(MODE_DIR)/Objects/chopshop09/Autonomous166.o : W:/workspace/chopshop09/Autonomous166.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP -mlongcall $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


chopshop09/$(MODE_DIR)/Objects/chopshop09/Dispenser166.o : W:/workspace/chopshop09/Dispenser166.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP -mlongcall $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


chopshop09/$(MODE_DIR)/Objects/chopshop09/Drive166.o : W:/workspace/chopshop09/Drive166.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP -mlongcall $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


chopshop09/$(MODE_DIR)/Objects/chopshop09/Inertia166.o : W:/workspace/chopshop09/Inertia166.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP -mlongcall $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


chopshop09/$(MODE_DIR)/Objects/chopshop09/MemoryLog166.o : W:/workspace/chopshop09/MemoryLog166.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP -mlongcall $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


chopshop09/$(MODE_DIR)/Objects/chopshop09/PIDControl166.o : W:/workspace/chopshop09/PIDControl166.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP -mlongcall $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


chopshop09/$(MODE_DIR)/Objects/chopshop09/PIDGyro.o : W:/workspace/chopshop09/PIDGyro.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP -mlongcall $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


chopshop09/$(MODE_DIR)/Objects/chopshop09/Robot166.o : W:/workspace/chopshop09/Robot166.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP -mlongcall $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


chopshop09/$(MODE_DIR)/Objects/chopshop09/SensorTest166.o : W:/workspace/chopshop09/SensorTest166.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP -mlongcall $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


chopshop09/$(MODE_DIR)/Objects/chopshop09/Sonar166.o : W:/workspace/chopshop09/Sonar166.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP -mlongcall $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


chopshop09/$(MODE_DIR)/Objects/chopshop09/Target166.o : W:/workspace/chopshop09/Target166.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP -mlongcall $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


chopshop09/$(MODE_DIR)/Objects/chopshop09/Vision166.o : W:/workspace/chopshop09/Vision166.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP -mlongcall $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


OBJECTS_chopshop09 = chopshop09/$(MODE_DIR)/Objects/chopshop09/Autonomous166.o \
	 chopshop09/$(MODE_DIR)/Objects/chopshop09/Dispenser166.o \
	 chopshop09/$(MODE_DIR)/Objects/chopshop09/Drive166.o \
	 chopshop09/$(MODE_DIR)/Objects/chopshop09/Inertia166.o \
	 chopshop09/$(MODE_DIR)/Objects/chopshop09/MemoryLog166.o \
	 chopshop09/$(MODE_DIR)/Objects/chopshop09/PIDControl166.o \
	 chopshop09/$(MODE_DIR)/Objects/chopshop09/PIDGyro.o \
	 chopshop09/$(MODE_DIR)/Objects/chopshop09/Robot166.o \
	 chopshop09/$(MODE_DIR)/Objects/chopshop09/SensorTest166.o \
	 chopshop09/$(MODE_DIR)/Objects/chopshop09/Sonar166.o \
	 chopshop09/$(MODE_DIR)/Objects/chopshop09/Target166.o \
	 chopshop09/$(MODE_DIR)/Objects/chopshop09/Vision166.o

chopshop09/$(MODE_DIR)/chopshop09.out : $(OBJECTS_chopshop09)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@";rm -f "$@";nmppc $(OBJECTS_chopshop09) $(IDE_LIBRARIES) | tclsh $(WIND_BASE)/host/resource/hutils/tcl/munch.tcl -c ppc > $(OBJ_DIR)/ctdt.c; $(TOOL_PATH)ccppc $(DEBUGFLAGS_Linker) $(CC_ARCH_SPEC) -fdollars-in-identifiers -Wall $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES)  -o $(OBJ_DIR)/ctdt.o -c $(OBJ_DIR)/ctdt.c; $(TOOL_PATH)ccppc -r -nostdlib -Wl,-X -T $(WIND_BASE)/target/h/tool/gnu/ldscripts/link.OUT -o "$@" $(OBJ_DIR)/ctdt.o $(OBJECTS_chopshop09) $(IDE_LIBRARIES) $(LIBPATH) $(LIBS)  $(ADDED_LIBPATH) $(ADDED_LIBS) && if [ "$(EXPAND_DBG)" = "1" ]; then plink "$@";fi

chopshop09/$(MODE_DIR)/chopshop09_compile_file : $(FILE) ;

_clean :: chopshop09/$(MODE_DIR)/chopshop09_clean

chopshop09/$(MODE_DIR)/chopshop09_clean : 
	$(TRACE_FLAG)if [ -d "chopshop09" ]; then cd "chopshop09"; rm -rf $(MODE_DIR); fi

DEP_FILES := chopshop09/$(MODE_DIR)/Objects/chopshop09/Autonomous166.d chopshop09/$(MODE_DIR)/Objects/chopshop09/Dispenser166.d chopshop09/$(MODE_DIR)/Objects/chopshop09/Drive166.d \
	 chopshop09/$(MODE_DIR)/Objects/chopshop09/Inertia166.d chopshop09/$(MODE_DIR)/Objects/chopshop09/MemoryLog166.d chopshop09/$(MODE_DIR)/Objects/chopshop09/PIDControl166.d \
	 chopshop09/$(MODE_DIR)/Objects/chopshop09/PIDGyro.d chopshop09/$(MODE_DIR)/Objects/chopshop09/Robot166.d chopshop09/$(MODE_DIR)/Objects/chopshop09/SensorTest166.d \
	 chopshop09/$(MODE_DIR)/Objects/chopshop09/Sonar166.d chopshop09/$(MODE_DIR)/Objects/chopshop09/Target166.d chopshop09/$(MODE_DIR)/Objects/chopshop09/Vision166.d
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
