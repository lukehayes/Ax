CXX = g++
CXXFLAGS = -I./include -DMAX=100
INC_DIR = -I include
SRC_DIR = src
LDFLAGS = -L. -lglfw3 -lGL -lX11 -lpthread -lm -ldl
OUTPUT = -o bin/app
ENTRY = main.cpp
GLAD_SRC = $(SRC_DIR)/glad.c
SYSTEM_NAMESPACE = $(SRC_DIR)/Ax/System
SYSTEM_SRC := $(wildcard $(SYSTEM_NAMESPACE)/*.cpp)
OBJS := Engine.o Window.o Shader.o VertexArray.o Camera.o Camera2D.o Camera3D.o

all: binary

binary: $(OBJS)
	$(CXX) $(CXXFLAGS) $(ENTRY) $(GLAD_SRC) *.o $(OUTPUT) $(LDFLAGS)

debug: $(OBJS)
	$(CXX) $(CXXFLAGS) -ggdb $(ENTRY) $(GLAD_SRC) *.o $(OUTPUT) $(LDFLAGS)

Engine.o: $(SYSTEM_NAMESPACE)/Engine.cpp
	$(CXX) $(CXXFLAGS) -c $<
	
Window.o: $(SYSTEM_NAMESPACE)/Window.cpp
	$(CXX) $(CXXFLAGS) -c $<

Shader.o: $(SYSTEM_NAMESPACE)/GL/Shader.cpp
	$(CXX) $(CXXFLAGS) -c $<

VertexArray.o: $(SYSTEM_NAMESPACE)/GL/VertexArray.cpp
	$(CXX) $(CXXFLAGS) -c $<

Camera.o: $(SYSTEM_NAMESPACE)/Graphics/Camera.cpp
	$(CXX) $(CXXFLAGS) -c $<

Camera2D.o: $(SYSTEM_NAMESPACE)/Graphics/Camera2D.cpp
	$(CXX) $(CXXFLAGS) -c $<

Camera3D.o: $(SYSTEM_NAMESPACE)/Graphics/Camera3D.cpp
	$(CXX) $(CXXFLAGS) -c $<


# Cleanup
.PHONY:clean
clean:
	rm -rf bin/
	rm *.o *.a
