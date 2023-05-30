CC = g++
CFLAGS = -std=c++11

# Nombre del ejecutable
TARGET = programa

# Ruta del archivo fuente
SRC = main.cpp

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET)

valgrind: $(TARGET)
	valgrind ./$(TARGET)

.PHONY: all run clean valgrind
