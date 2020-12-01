CC = gcc
CFLAGS = -Wall
IDFLAGS = -I include
SRCDIR = src
SRCFLAGS = src/math/vec2.c
ALLSRC = $(wildcard src/*.c) $(wildcard src/*/*.c)
LDFLAGS =
LIBS = -lglfw3 -lGLU -lGL -lX11 -lpthread -lm -ldl -lGLEW
STATIC_LIBS = -lCG-Math-Static
TARGET = -o build/app
ENTRY = main.c

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
