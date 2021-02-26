CXX = g++
CXX_FLAGS = -DMAX=100

INC_DIR = -I include
SRC_DIR = src

LINK_DIR = -L.
LIBS = -lglfw3 -lGLEW -lGLU -lGL -lX11 -lpthread -lm -ldl

TARGET = -o bin/app
ENTRY = main.cpp

SYSTEM_NAMESPACE = src/Ax/System/
SYSTEM_SRC = $(wildcard $(SYSTEM_NAMESPACE)**/*.cpp)

# Development
%.o: %$(SYSTEM_NAMESPACE)*.cpp %$(SYSTEM_NAMESPACE)*/*.cpp
	$(CXX) -I include -c $^

app-debug: *.o
	$(CXX) main.cpp $^ $(CXX_FLAGS) $(TARGET) $(INC_DIR) $(LIBS)

run: app-debug
	$(shell "./bin/app")

# Library Creation
#libAxSystem.a: *.o
	#ar -rcs $@ $^
	#rm *.

#app-lib: libAxSystem.a
	#$(CXX) $(ENTRY) $(TARGET) $(INC_DIR) $(LINK_DIR) $(LIBS) -lAxSystem -lGLEW

# Cleanup
.PHONY:clean
clean:
	rm -rf bin/
	rm *.o *.a
