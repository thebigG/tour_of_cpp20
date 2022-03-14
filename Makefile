mkfile_path  := $(word $(words $(MAKEFILE_LIST)),$(MAKEFILE_LIST))
ROOT_DIR     := $(shell cd $(shell dirname $(mkfile_path)); pwd)
BUILD_DIR    := $(ROOT_DIR)/build

# Target directories
SRC_DIR    := $(ROOT_DIR)/src
OBJ_DIR    := $(BUILD_DIR)/obj
BIN_DIR    := $(BUILD_DIR)
INCLUDES   := -I$(SRC_DIR)

EXE        := $(BIN_DIR)/tour_of_cpp20
SRC        := $(SRC_DIR)/chapter2.cxx $(SRC_DIR)/chapter2_impl.cxx $(SRC_DIR)/chapter3.cxx $(SRC_DIR)/chapter3_impl.cxx $(SRC_DIR)/chapter4.cxx $(SRC_DIR)/chapter4_impl.cxx

MAIN	   := $(SRC_DIR)/main.cpp
OBJ        := $(SRC:$(SRC_DIR)/%.cxx=$(OBJ_DIR)/%.o)

# Set target flags
CPPFLAGS    := -fmodules-ts -MMD -MP -std=c++20 -fmessage-length=0 $(INCLUDES)
CFLAGS      := -Wall -g
LDFLAGS     := -Llib
LDLIBS      := -lm
HD_FLAGS    := -c -std=c++20 -fmodule-header

# Set tools
CC          := g++
LD          := g++

.PHONY: all clean

# Target recipes
$(EXE): $(OBJ)

$(OBJ_DIR)/main: $(OBJ) $(OBJ_DIR)/main.o
		$(LD) $(CPPFLAGS) $(LDFLAGS) $^ $(LDLIBS) -o $@

#$(OBJ_DIR)/main: $(OBJ_DIR)/main.o
#	$(LD) $(CPPFLAGS) $(LDFLAGS) $^ $(LDLIBS) -o $@

$(OBJ_DIR)/main.o: $(MAIN)
		$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@


$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cxx | $(OBJ_DIR)
		$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $@

all: $(EXE) $(OBJ_DIR)/main.o $(OBJ_DIR)/main

run:
	@$(OBJ_DIR)/main

stl_modules:
	@g++ -std=c++20 -fmodules-ts -xc++-system-header iostream
	@g++ -std=c++20 -fmodules-ts -xc++-system-header variant
	@g++ -std=c++20 -fmodules-ts -xc++-system-header utility
	@g++ -std=c++20 -fmodules-ts -xc++-system-header string
	@g++ -std=c++20 -fmodules-ts -xc++-system-header cstdint
	@g++ -std=c++20 -fmodules-ts -xc++-system-header exception
	@g++ -std=c++20 -fmodules-ts -xc++-system-header initializer_list

check-format:
	@bash ./check-clang-format.sh

format:
	@bash ./clang-format.sh

clean-modules:
	@rm -r gcm.cache

clean:
	@$(RM) -Rf $(BUILD_DIR)

-include $(OBJ:.o=.d)

