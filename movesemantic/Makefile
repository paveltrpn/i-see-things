
CC = g++-10
CFLAGS = --std=c++20 -O2

SRCS := movesemantic.cpp rvalue.cpp test.cpp
OBJS := $(SRCS:.cpp=.o)

.phony: all clean

all: main

movesemantic.o: movesemantic.cpp
	$(CC) $(CFLAGS) -c $< -o $@

rvalue.o: rvalue.cpp
	$(CC) $(CFLAGS) -c $< -o $@

test.o: test.cpp
	$(CC) $(CFLAGS) -c $< -o $@

main: $(OBJS)
	$(CC) $(OBJS) -o $@ -lstdc++

clean:
	rm -f *.o main
