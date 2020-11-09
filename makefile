CC = gcc
CFLAGS = -Wall
IDFLAGS = -I include
LDFLAGS = -L/usr/local/lib/GLFW
LIBS = -lglfw3 -lGLU -lGL -lX11 -lpthread -lm -ldl
TARGET = -o bin/app
ENTRY = main.c

compile:
	$(CC) $(ENTRY) $(TARGET) $(CFLAGS) $(IDFLAGS) $(LDFLAGS) $(LIBS)

clean:
	rm -r bin
