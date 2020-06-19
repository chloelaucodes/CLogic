CC      = gcc
CFLAGS  = -Wall -g -D_POSIX_SOURCE -D_DEFAULT_SOURCE -std=c99

.SUFFIXES: .c .o

.PHONY: all clean

all: ext_test_execute

CLogic: ext_test_execute.o

clean:
	rm -f $(wildcard *.o)
	rm -f ext_test_execute
