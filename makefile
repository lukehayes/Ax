CC = gcc
CFLAGS = -DMAX_MODELS="100"
IDFLAGS = -I include
SRCDIR = src
ALLSRC = $(wildcard src/*.cpp) $(wildcard src/*/*.cpp)
LDFLAGS =
LIBS = -lglfw3 -lGLU -lGL -lX11 -lpthread -lm -ldl -lGLEW -lstdc++
STATIC_LIBS = -lCG-Math-Static
TARGET = -o bin/app
ENTRY = main.cpp

#Bundle all source code into a single binary
all:
	$(CC) $(ENTRY) $(ALLSRC) $(TARGET) $(CFLAGS) $(IDFLAGS) $(LDFLAGS) $(LIBS)

build-static: 
	$(CC) $(ENTRY) $(TARGET) $(CFLAGS) $(IDFLAGS) $(LDFLAGS) $(LIBS) $(STATIC_LIBS)

libCG-Math-Static.a:
	$(CC) -c src/math/*.c $(IDFLAGS)
	ar -rcs $@ *.o

#Debug specific. -g3 flag enables ALL debugging symbols.
DEBUG_FLAGS = -Wall -ggdb
debug:
	$(CC) $(ENTRY) $(ALLSRC) $(TARGET) $(DEBUG_FLAGS) $(CFLAGS) $(IDFLAGS) $(LDFLAGS) $(LIBS)

clean:
	rm *.o *.so *.a
	rm -r bin
