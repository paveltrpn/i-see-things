
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

main: $(OBJS)
	$(CC) $(OBJS) $(LFLAGS) -o $@ -lstdc++

clean:
	rm -f *.o main
