#SHELL=!/bin/bash

CC  ?= gcc
CXX ?= g++

CFLAGS += -g -Wall -Werror -pthread
CFLAGS += -I./include \

LDFLAGS += -lpthread -ldl
BIN = ./bin
SRC += ./src/log/log.c \
	   ./src/file/file.c \
	   ./src/main.c \

test: 
	$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS) $(SRC)
clean:
	rm -f *.so *.o test
