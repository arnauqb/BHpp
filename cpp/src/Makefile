CC=g++
CFLAGS=-c -Wall
LDFLAGS=
SOURCES=main.cpp BlackHole.cpp
HEADERS = BlackHole.hpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=bhg

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS) $(HEADERS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@
