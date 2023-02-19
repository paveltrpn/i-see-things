
CC := g++-10
CFLAGS := -std=c++20 -O0
LFLAGS := -L/usr/local/lib -lfmt

SRCS := $(wildcard *.cpp)
OBJS := $(SRCS:.cpp=.o)

VPATH := .

.phony: all clean

all: main

main.o: main.cpp
	$(CC) $(CFLAGS) -c $< -o $@

file.o: file.cpp
	$(CC) $(CFLAGS) -c $< -o $@

string_mnp.o: string_mnp.cpp common.h
	$(CC) $(CFLAGS) -c $< -o $@

main: $(OBJS)
	$(CC) $(OBJS) $(LFLAGS) -o $@ -lstdc++

clean:
	rm -f *.o main
