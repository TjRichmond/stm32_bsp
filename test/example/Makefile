# Name of component under test
COMPONENT_NAME = example

# Compiler settings
CPPUTEST_CPPFLAGS =-DSTM32U575xx 

# Dynamically generate absolute paths
# From https://matheusmbar.com/bugfree-robot/2019/04/05/makefile-first-test.html
MAKEFILE_DIR = $(dir $(realpath $(firstword $(MAKEFILE_LIST))))
PROJECT_DIR = $(realpath $(MAKEFILE_DIR)../..)
# SRC_DIR = $(PROJECT_DIR)/bsp
TEST_DIR = $(PROJECT_DIR)/test

# Location of CppUTest (if not already set)
CPPUTEST_HOME ?= ~/Tools/cpputest

# Include and source files for component under test
# INCLUDE_DIRS = $(SRC_DIR)/include
# INCLUDE_DIRS += $(PROJECT_DIR)/CMSIS/Device/ST/STM32U5/Include
# INCLUDE_DIRS += $(PROJECT_DIR)/CMSIS/CMSIS/Core/Include
# SRC_DIRS = $(SRC_DIR)

# Includes CppUTest header files
INCLUDE_DIRS += $(CPPUTEST_HOME)/include

# Directories containing the unit tests
TEST_SRC_DIRS = $(TEST_DIR)/$(COMPONENT_NAME)

# Run MakefileWorker.mk with the variables set in this Makefile
include $(CPPUTEST_HOME)/build/MakefileWorker.mk