CC = gcc
CFLAGS = -Wall -Wextra -I. -Icaixa -Ifila -Ipilhas -Iprodutos -Itipos

SRCS = $(wildcard *.c) $(wildcard caixa/*.c) $(wildcard fila/*.c) $(wildcard pilhas/*.c) $(wildcard produtos/*.c) $(wildcard tipos/*.c)
OBJS = $(SRCS:.c=.o)
TARGET = app

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)
