
CC := gcc

TARGET := rock-paper-scissor

.PHONY: all clean

all: $(TARGET)

$(TARGET) : main.c game-pages.c game-utilities.c game-utilities.h game-config.h game-pages.h game-shape.h
	$(CC) -o $(TARGET) main.c game-pages.c game-utilities.c

clean:
	rm -rf $(TARGET)
