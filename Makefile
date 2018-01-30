CC=g++
CFLAGS=-c -Wall
LDFLAGS=
SOURCES=src/main.cpp src/BlackHole.cpp
HEADERS = src/BlackHole.hpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=bhg

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS) $(HEADERS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@
