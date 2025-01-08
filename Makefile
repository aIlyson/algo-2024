# esse arquivo serve para automatizar o processo de compilação do projeto utilizando o Makefile
# controlando para compilar e linkar os arquivos fonte, gerenciar os objetos intermediários e limpar arquivos temporários

CC = gcc
CFLAGS = -Wall -Wextra -Wpedantic -Wshadow -Wformat=2 -Wcast-align -Wconversion -Wsign-conversion -Wnull-dereference -g3 -O0
SOURCES = main.c methods/estoque.c methods/financeiro.c
OBJECTS = $(SOURCES:.c=.o)
TARGET = build/Debug/outDebug.exe

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(TARGET)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(TARGET)
