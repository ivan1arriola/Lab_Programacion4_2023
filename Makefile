CC = g++
CFLAGS = -std=c++11 -Wall

# Nombre del ejecutable
BINARY = programa

# .o de los archivos fuente
OBJS = main.o

# Ruta del archivo fuente
SRC = main.cpp

all: $(BINARY)

$(BINARY): $(SRC)
	$(CC) $(CFLAGS) -o $(BINARY) $(SRC)

run: $(BINARY)
	./$(BINARY)

clean:
	rm -f $(BINARY)

valgrind: $(BINARY)
	valgrind ./$(BINARY)

.PHONY: all run clean valgrind
