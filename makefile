# compiler
CC = g++
# compiler flags
CFLAGS = -c -Wall
# source files
SOURCES = sentenceMain.cpp sentenceAnalysis.cpp
# object files
OBJECTS = $(SOURCES:.cpp=.o)
# executable name
EXECUTABLE = sentenceAnalysis

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf $(OBJECTS) $(EXECUTABLE)
