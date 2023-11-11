CC = g++
CXXFLAGS = -g -O3 -Wpedantic -Wall -Wextra -Wmisleading-indentation -Wunused -Wuninitialized -Wshadow -Wconversion -Werror -I$(GENERIC_INCLUDE_DIR) -I$(FISH_INCLUDE_DIR) -I$(SHARK_INCLUDE_DIR) -std=c++23

GENERIC_INCLUDE_DIR = Headers
GENERIC_SRC_DIR = sources

FISH_INCLUDE_DIR = Animals/Fish/Headers
FISH_SRC_DIR = Animals/Fish

SHARK_INCLUDE_DIR = Animals/Sharks/Headers
SHARK_SRC_DIR := Animals/Sharks
BIN_DIR := bin

vpath %.cpp $(GENERIC_SRC_DIR) $(FISH_SRC_DIR) $(SHARK_SRC_DIR)
SOURCES := $(wildcard $(GENERIC_SRC_DIR)/*.cpp $(FISH_SRC_DIR)/*.cpp $(SHARK_SRC_DIR)/*.cpp)
#SOURCES := $(notdir $(SOURCES))
OBJECTS := $(patsubst %.cpp,%.o, $(SOURCES))
# We could have done that all in one line, but this way is easier to read.

all: $(OBJECTS) WaTor

$(BIN_DIR)/%.cpp.o: %.cpp
	$(CC) $(CXXFLAGS) -o $@

WaTor: $(OBJECTS)
	$(CC) $(CXXFLAGS) $^ $(BIN_DIR)/*.cpp  -o $@

clean:
	rm -f ${OBJECTS} WaTor