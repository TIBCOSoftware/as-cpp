#!/usr/bin/make -f

ifndef AS_HOME
    $(error AS_HOME is not defined)
endif

BUILD_TYPE := $(if $(DEBUG),dbg,rel)
BIN_DIR := bin
LIB_DIR := lib
OBJ_DIR := obj

COMPILE_FLAGS := -w
COMPILE_FLAGS += -m64
COMPILE_FLAGS += -Wunreachable-code
COMPILE_FLAGS += -fno-strict-aliasing
COMPILE_FLAGS += -D_PLATFORM_MAC64
COMPILE_FLAGS += -DDarwin
COMPILE_FLAGS += -D_DARWIN_C_SOURCE
COMPILE_FLAGS += -D_REENTRANT
COMPILE_FLAGS += -DPIC
COMPILE_FLAGS += -DHAVE_CONFIG_H
COMPILE_FLAGS += -D_LARGEFILE64_SOURCE
COMPILE_FLAGS += -D_LARGEFILE_SOURCE
COMPILE_FLAGS += -D_FILE_OFFSET_BITS=64
COMPILE_FLAGS += -I$(AS_INCLUDE)
ifneq ($(DEBUG),)
    COMPILE_FLAGS += -g3
    COMPILE_FLAGS += -ggdb3
    COMPILE_FLAGS += -D_DEBUG
else
    COMPILE_FLAGS += -O2
    COMPILE_FLAGS += -DNDEBUG
endif

LINK_FLAGS := -m64
LINK_FLAGS += -L$(LIB_DIR) -L$(AS_HOME)/lib
LINK_FLAGS += -ldl
LINK_FLAGS += -lstdc++
LINK_FLAGS += -lm
LINK_FLAGS += -lpthread

OBJECTS = $(foreach src, $1, $(1:%.cpp=$(OBJ_DIR)/%.o))

LIB_SRCS := $(wildcard src/*.cpp)
LIB_OBJS := $(call OBJECTS,$(LIB_SRCS))
$(LIB_OBJS) : CPPFLAGS := $(COMPILE_FLAGS) -I$(AS_HOME)/include/c
LIBRARY := $(LIB_DIR)/libas-cpp.dylib
STD_TEST_FILES := $(wildcard src/*.test)

EXE_SRCS := $(wildcard examples/*.cpp)
EXE_OBJS := $(call OBJECTS,$(EXE_SRCS))
$(EXE_OBJS) : CPPFLAGS := $(COMPILE_FLAGS) -Isrc -I$(AS_HOME)/include/c

EXE_MAIN_SRCS := $(shell grep -l "int main" $(EXE_SRCS))
EXE_BASE_SRCS := $(filter-out $(EXE_MAIN_SRCS), $(EXE_SRCS))
EXE_BASE_OBJS := $(call OBJECTS,$(EXE_BASE_SRCS))

define exe_template
    EXES += $(BIN_DIR)/$(basename $(notdir $1))++
    $(BIN_DIR)/$(basename $(notdir $1))++ : $(call OBJECTS,$1) $(EXE_BASE_OBJS) -las-cpp
    $(BIN_DIR)/$(basename $(notdir $1))++ : override LDFLAGS := $(LINK_FLAGS)
endef

OBJS := $(LIB_OBJS) $(EXE_OBJS)
DEPS := $(OBJS:.o=.d) $(OBJ_DIR)/configure.d
EXES :=

$(foreach src, $(EXE_MAIN_SRCS), $(eval $(call exe_template,$(src))))

all : $(EXES) $(LIBRARY)

$(OBJ_DIR)/%.d : ;

$(OBJ_DIR)/configure.d : $(STD_TEST_FILES)
	@mkdir -p $(@D)
	@> $@
	@if $(CXX) $(CXXFLAGS) $(CPPFLAGS) $(TARGET_ARCH) -c -x c++ src/StdSharedPtr.test -o /dev/null 2> /dev/null ; \
	then \
		echo std::shared_ptr found; \
	else \
		echo STD_CXX_FLAGS += -DNO_STD_SHARED_PTR >> $@ ; \
	fi
	@if $(CXX) $(CXXFLAGS) $(CPPFLAGS) $(TARGET_ARCH) -c -x c++ src/StdMutex.test -o /dev/null 2> /dev/null ; \
	then \
		echo std::mutex found ; \
	else \
		echo STD_CXX_FLAGS += -DNO_STD_MUTEX >> $@ ; \
	fi
	@echo >> $@

$(OBJ_DIR)/%.o : %.cpp
	@echo Compiling $<
	@mkdir -p $(@D)
	@$(COMPILE.cpp) -fPIC $< $(OUTPUT_OPTION) -MMD -MT $@

$(LIBRARY) : override LDFLAGS := $(LINK_FLAGS)
-las-cpp : $(LIBRARY)
$(LIBRARY) : $(LIB_OBJS)
	@echo Linking dynamic library $(@F)
	@mkdir -p $(@D)
	@$(LINK.cc) -fPIC -shared -o $@ $^ -las-common -las-core

$(BIN_DIR)/%++:
	@echo Linking executabe $(@F)
	@mkdir -p $(@D)
	@$(LINK.cc) -o $@ $^ -las-common -las-core

clean:
	@echo Removing binaries
	@$(RM) $(OBJS)
	@$(RM) $(DEPS)
	@$(RM) $(EXES)
	@$(RM) $(LIBRARY)

clean1:
	@echo $(RM) $(OBJS) $(DEPS) $(EXES) $(LIBRARY)

rm_outdir:
	@$(RM) -r bin lib obj

.DEFAULT_GOAL := all

.DEFAULT:
	mkdir -p $@

.PHONY : clean all

.INTERMEDIATE : -las-cpp

-include $(DEPS) $(OBJ_DIR)/configure.d
