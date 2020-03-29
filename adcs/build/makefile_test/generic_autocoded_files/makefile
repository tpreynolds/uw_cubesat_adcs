# Define the directories
GENERIC_INC_DIR := ../std_autocode_headers/
INC_DIR := ./
BUILD_DIR := ./build
SRC_DIR := ./

# Define macros for all file names of the files we care about
SRC := $(wildcard $(SRC_DIR)/*.c)
OBJ := $(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/%.o,$(SRC))
# if there are libraries to include, add them to the line below and then add $(LIBS) to the main: rule.
# LIBS := 

# Macros for build options
CC=gcc
CFLAGS=-I$(GENERIC_INC_DIR) -I$(INC_DIR) -Wall

main: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) -c -o $@ $< $(CFLAGS)

.PHONY: clean
clean:
	rm -f $(BUILD_DIR)/*.o $(BUILD_DIR)/*.d *~ cor