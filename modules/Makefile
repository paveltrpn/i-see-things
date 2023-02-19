
CC := g++
CFLAGS := -std=c++20 -fmodules-ts

#INCDIR := -I/usr/include/c++/10 -I/usr/include/x86_64-linux-gnu/c++/10
#LFLAGS := -L /usr/lib/gcc/x86_64-linux-gnu/10

SRCS := hello.cpp test.cpp
OBJS := $(SRCS:.cpp=.pcm)

.phony: all clean

all: main

vec3.pcm: vec3.cpp
	$(CC) $(CFLAGS) $(INCDIR) -c $< -o $@

mtrx3.pcm: mtrx3.cpp
	$(CC) $(CFLAGS) $(INCDIR) -c $< -o $@

algebra.pcm: algebra.cpp
	$(CC) $(CFLAGS) $(INCDIR) -c $< -o $@

main: vec3.pcm mtrx3.pcm algebra.pcm test.cpp
	$(CC) $(CFLAGS) $(INCDIR) $(LFLAGS)  test.cpp mtrx3.pcm vec3.pcm algebra.pcm -o main

clean:
	rm -f *.pcm main
