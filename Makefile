mkfile_path  := $(word $(words $(MAKEFILE_LIST)),$(MAKEFILE_LIST))
ROOT_DIR     := $(shell cd $(shell dirname $(mkfile_path)); pwd)
BUILD_DIR    := $(ROOT_DIR)/build

# Target directories
SRC_DIR    := $(ROOT_DIR)/src
OBJ_DIR    := $(BUILD_DIR)/obj
BIN_DIR    := $(BUILD_DIR)
INCLUDES   := -I$(SRC_DIR)

# Target files
EXE        := $(BIN_DIR)/tour_of_cpp20
SRC        := $(SRC_DIR)/func.cxx $(SRC_DIR)/func_impl.cxx
MAIN	   := $(SRC_DIR)/main.cpp
OBJ        := $(SRC:$(SRC_DIR)/%.cxx=$(OBJ_DIR)/%.o)

# Set target flags
CPPFLAGS    := -fmodules-ts -MMD -MP -std=c++20 -fmessage-length=0 $(INCLUDES)
CFLAGS      := -Wall -g
LDFLAGS     := -Llib
LDLIBS      := -lm

# Set tools
CC          := g++
LD          := g++

.PHONY: all clean

# Target recipes
$(EXE): $(OBJ)

main: $(OBJ) $(OBJ_DIR)/main.o
	$(LD) $(CPPFLAGS) $(LDFLAGS) $^ $(LDLIBS) -o $@

$(OBJ_DIR)/main.o: $(MAIN)
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@


$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cxx | $(OBJ_DIR)
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $@

all: $(EXE) $(OBJ_DIR)/main.o main

clean:
	@$(RM) -Rf $(BUILD_DIR)

-include $(OBJ:.o=.d)

