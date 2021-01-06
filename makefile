CC = gcc
CFLAGS = -DMAX_MODELS="100"

INC_DIR = -I include
SRC_DIR = src

LINK_DIR = -L.
LIBS = -lglfw3 -lGLEW -lGLU -lGL -lX11 -lpthread -lm -ldl -lstdc++

TARGET = -o bin/app
ENTRY = main.cpp

SYSTEM_NAMESPACE = src/Ax/System/
SYSTEM_SRC = $(wildcard $(SYSTEM_NAMESPACE)*.cpp) $(wildcard $(SYSTEM_NAMESPACE)*/*.cpp)

app-debug:
	$(CC) main.cpp $(SYSTEM_SRC) $(TARGET) $(INC_DIR) $(LIBS)

%.o: $(SYSTEM_SRC)
	$(CC) -I include -c $^

libAxSystem.a: *.o
	ar -rcs $@ $^
	rm *.o

app-lib: libAxSystem.a
	$(CC) $(ENTRY) $(TARGET) $(INC_DIR) $(LINK_DIR) $(LIBS) -lAxSystem -lGLEW

.PHONY:clean
clean:
	rm -rf bin/
	rm *.o *.a
