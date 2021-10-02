CC=g++
EXECUTABLE=sdl
SOURCES=$(wildcard ./src/*.cpp)
OBJS=$(SOURCES:.cpp=.o)
LIBFLAGS= -lSDL2 -lSDL2_image

debug : $(EXECUTABLE)
release : $(EXECUTABLE)

all: $(SOURCES) $(EXECUTABLE)
$(EXECUTABLE): $(OBJS)
	$(CC) $(OBJS) -o $@ $(LIBFLAGS)
.cpp.o:
	$(CC) -c $(LIBFLAGS) $< -o $@

clean:
	rm -f main $(OBJS)
