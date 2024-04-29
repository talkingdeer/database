CC=g++
CFLAGS=-c -Wall
LDFLAGS=
SOURCES=client.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=client

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@