# Compiler and flags
CXX = g++
CXXFLAGS = -Iinclude -Iinclude/SDL2 -Iinclude/headers -Isrc

# Directories
LIB_DIRS = -Llib

# Libraries
LIBS = -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf

# Source files and output
SRC = main.cpp $(wildcard src/*.cpp)
OUT = main.exe

# Default target to build the executable
all: $(OUT)

$(OUT): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $@ $(LIB_DIRS) $(LIBS)

# Run the executable
run: all
	./$(OUT)

# Clean up build files
clean:
	rm -f $(OUT)

.PHONY: all run clean
