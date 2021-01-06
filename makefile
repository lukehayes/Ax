CC = gcc
CFLAGS = -DMAX_MODELS="100"
INC_DIR = -I include
SRC_DIR = src
SYSTEM_NAMESPACE = src/Ax/System/
ALL_SRC = $(wildcard $(SYSTEM_NAMESPACE)*.cpp) $(wildcard $(SYSTEM_NAMESPACE)*/*.cpp)
LD_FLAGS = -L.
LIBS = -lglfw3 -lGLU -lGL -lX11 -lpthread -lm -ldl -lGLEW -lstdc++
STATIC_LIBS = -lCG
TARGET = -o bin/app
ENTRY = main.cpp

app-debug:
	$(CC) main.cpp $(ALL_SRC) $(TARGET) $(INC_DIR) $(LIBS)

%.o: %src/*.cpp
	$(CC) -I include -c $^

libCG.a: *.o
	ar -rcs $@ $^

app-lib:
	$(CC) main.cpp $(TARGET) $(INC_DIR) $(LD_FLAGS) $(LIBS) -lCG

.PHONY:clean

clean:
	rm -rf bin/
	rm *.o *.a
