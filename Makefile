CC      = gcc
CFLAGS  = -Wall -g -D_POSIX_SOURCE -D_DEFAULT_SOURCE -std=c99

.SUFFIXES: .c .o

.PHONY: all clean

all: CLogic

CLogic: CLogic.o

clean:
	rm -f $(wildcard *.o)
	rm -f CLogic
