# Makefile para Windows (C++)
CC = g++
CFLAGS = -Wall -std=c++17
TARGET = main.exe
SRCS = lista_circular_main.cpp lista_circular.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	del /f /q *.o $(TARGET)