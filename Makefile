###############################################################################################
# Declare Some Makefile Variables - Make sure to add a '\' to the end of a line if it overflows
###############################################################################################
CC = g++
###############################
LANG_STD = -std=c++17
###############################
COMPILER_FLAGS = -Wall\
				 -Wfatal-errors
###############################
INCLUDE_PATH = -I"./libs/"
###############################
SRC_FILES = src/*.cpp \
			src/Game/*.cpp\
			src/Logger/*.cpp
###############################
LINKER_FLAGS = -lSDL2\
			   -lSDL2_image\
			   -lSDL2_ttf\
			   -lSDL2_mixer\
			   -llua5.3
###############################
OBJ_NAME = gameengine
###############################################################################################
# Declare Some Makefile Rules
###############################################################################################
build:
	$(CC) $(COMPILER_FLAGS) $(LANG_STD) $(INCLUDE_PATH) $(SRC_FILES) $(LINKER_FLAGS) -o $(OBJ_NAME);


###############################################################################################
# Declare The Run Command
###############################################################################################
run:
	./$(OBJ_NAME)

###############################################################################################
# Declare The Clean Command
###############################################################################################
clean:
	rm $(OBJ_NAME)
