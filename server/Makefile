CC=g++ -std=c++20
CFLAGS=-c -Wall
LDFLAGS= 
SOURCES=server.cpp base.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=server

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@ -lpthread

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@
clear:
	rm -f server server.o base.o