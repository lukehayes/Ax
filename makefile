CC = gcc
CFLAGS = -Wall -g
IDFLAGS = -I include -I deps/GLEW
LDFLAGS = -L/usr/local/lib/GLFW -L deps/GLEW/lib
LIBS = -lglfw3 -lGLU -lGL -lX11 -lpthread -lm -ldl -lGLEW
TARGET = -o bin/$@
ENTRY = main.c

app:
	$(CC) $(ENTRY) $(TARGET) $(CFLAGS) $(IDFLAGS) $(LDFLAGS) $(LIBS)

clean:
	rm -r bin
