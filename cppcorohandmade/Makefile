CC       = clang++-15
CFLAGS   = -Wall --std=c++20
LFLAGS 	 =

INCDIR	 =
LIBDIR	 =

VPATH =  

SRCS = main.cpp

OBJS = $(patsubst %.cpp, %.o,$(SRCS))

#OBJS := $(SRCS:.cpp=.o)

.PHONY: clean all

all: $(OBJS) main

main.o: main.cpp
	$(CC) $(CFLAGS) $(addprefix -I,$(INCDIR)) -c $< -o $@

clean:
	rm -f *.o main
