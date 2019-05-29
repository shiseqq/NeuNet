CC = g++
EXECUTABLE = bin/main.out
PYTHONFLAGS = `python3.6-config --ldflags`
GRAPHICFLAGS = -lsfml-graphics -lsfml-window -lsfml-system -std=c++11
CFLAGS = -Wall -Werror -c -MD $(PYTHONFLAGS)
SOURCES = $(wildcard src/*.cpp)
OBJECTS = $(patsubst src/%.cpp, build/%.o, $(wildcard src/*.cpp))
DEPENDENCIES = $(patsubst build/%.o, build/%.d, $(wildcard build/*.o))

all : $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE) : $(OBJECTS)
	$(CC) $^ -o $@ -std=c++11 $(PYTHONFLAGS) $(GRAPHICFLAGS)

build/%.o : src/%.cpp
	$(CC) $(CFLAGS) $< -o $@ -std=c++11

.PHONY : clean
clean:
	rm -f build/*.o build/*.d bin/*.out

include $(wildcard build/*.d)