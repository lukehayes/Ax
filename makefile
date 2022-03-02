CXX = g++
CXXFLAGS = -std=c++17 -I./include -DDEBUG=1 -DMAX_ENTITIES=1000
SRC_DIR = src
LDFLAGS = -L. -lglfw -lGL -lX11 -lpthread -lm -ldl
OUTPUT = -o bin/app
ENTRY = main.cpp
GLAD_SRC = $(SRC_DIR)/glad.c
OBJS    = $(patsubst src/%.cpp, obj/%.o, $(wildcard src/*.cpp))

obj/%.o: src/%.cpp
	$(CXX) $(CXXFLAGS) -c $^ -o $@

all: $(OBJS)
	$(CXX) $(CXXFLAGS) $(ENTRY) $(GLAD_SRC) $^ $(OUTPUT) $(LDFLAGS)

debug: $(OBJS)
	$(CXX) $(CXXFLAGS) -ggdb $(ENTRY) $(GLAD_SRC) $^ $(OUTPUT) $(LDFLAGS)

# Cleanup
.PHONY:clean
clean:
	rm -rf bin/*
	rm *.o *.a
