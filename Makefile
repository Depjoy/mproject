#SHELL=!/bin/bash

CC  ?= gcc
CXX ?= g++

CFLAGS += -g -Wall -Werror
CFLAGS += -lpthread -ldl
LDFLAGS += -I./include

BIN = ./bin
SRC += src/log/log.c \
	   src/file/file.c \
	   src/main.c \

LIBSRC += src/math/stime.c

TARGET = libshare.so test
all: $(TARGET)

libshare.so:
	$(CC) -o $@ $^ $(LIBSRC) -fPIC -shared
test: 
	$(CC) -o $@ $^ $(SRC) $(LDFLAGS) $(CFLAGS)
clean:
	rm -f *.so *.o
	rm bin/test
	rm lib/libshare.so
