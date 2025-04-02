# Makefile para Windows (C++)
CC = g++
CFLAGS = -Wall -std=c++17
TARGET = main.exe
SRCS = lista_sequencial_main.cpp lista_sequencial.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	del /f /q *.o $(TARGET)