CC=clang
CFLAGS=-Wall -I/usr/include/SDL2
LDFLAGS=-lSDL -lGL

TARGET=triangle

all: $(TARGET)

$(TARGET):
	clang src/main.cpp -o $(TARGET)

clean:
	rm -f *.o $(TARGET)

