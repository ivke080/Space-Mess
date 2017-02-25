PROGRAM = spacemess
CC = g++
LIBS = -lglut -lGL -lGLU  -lm
SOURCE = src/*.cpp

all: $(PROGRAM)

$(PROGRAM): $(SOURCE)
	$(CC) -o $(PROGRAM) $(SOURCE) $(LIBS)

.PHONY: clean

clean:
	rm -f *.o $(PROGRAM)