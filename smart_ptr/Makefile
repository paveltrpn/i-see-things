
CC = g++-10
CFLAGS = --std=c++20 -O0

SRCS := smart_ptr.cpp test.cpp
OBJS := $(SRCS:.cpp=.o)

.phony: all clean

all: main

%.o: %.cpp %.h
	$(CC) $(CFLAGS) -c $< -o $@

main: $(OBJS)
	$(CC) $(OBJS) -o $@ -lstdc++

clean:
	rm -f *.o main
