
CC := g++
CFLAGS := -IE:\Devtools\fmt-7.1.3\include -std=c++2a -O0
LFLAGS := -LE:\Devtools\fmt-7.1.3\build -lfmt
SOURCE_PREFIX = src
BUILD_PREFIX = build

SRCS = main.cpp \
	   file.cpp \
	   string_mnp.cpp
	   
OBJS := $(patsubst %.cpp,$(BUILD_PREFIX)/%.o,$(SRCS))

VPATH := $(SOURCE_PREFIX)

.phony: all clean

all: main

$(BUILD_PREFIX)/main.o: main.cpp common.h
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_PREFIX)/file.o: file.cpp common.h
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_PREFIX)/string_mnp.o: string_mnp.cpp common.h
	$(CC) $(CFLAGS) -c $< -o $@

main: $(OBJS)
	$(CC) $(OBJS) $(LFLAGS) -o $@ -lstdc++

clean:
	rm -f $(BUILD_PREFIX)/*.o main.exe
