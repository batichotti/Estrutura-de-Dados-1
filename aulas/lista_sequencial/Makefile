# Makefile para Windows (C++)
CC = g++
CFLAGS = -Wall -std=c++17
TARGET = main.exe
SRCS = list_seq_main.cpp list_seq.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	del /f /q *.o $(TARGET)