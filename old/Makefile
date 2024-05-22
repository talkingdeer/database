CC=g++
CFLAGS=-c -Wall
LDFLAGS=
SOURCES=main.cpp base.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=base

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@