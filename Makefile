CC = g++
EXECUTABLE = bin/main.out
PYTHONFLAGS = `python3.6-config --ldflags`
GRAPHICFLAGS = -lsfml-graphics -lsfml-window -lsfml-system -std=c++11
CFLAGS = -Wall -Werror -c -MD $(PYTHONFLAGS) $(GRAPHICFLAGS)
SOURCES = $(wildcard src/*.cpp)
OBJECTS = $(patsubst src/%.cpp, build/%.o, $(wildcard src/*.cpp))
DEPENDENCIES = $(patsubst build/%.o, build/%.d, $(wildcard build/*.o))
TEST_SOURCES = $(wildcard $(addprefix test/, *.cpp))
TEST_OBJECTS = $(patsubst $(addprefix test/, %.h),$(addprefix build/, %.o),$(wildcard $(addprefix test/, *.h))) $(patsubst $(addprefix test/, %.cpp),$(addprefix build/, %.o),$(wildcard $(addprefix test/, *.cpp)))
TEST_EXECUTABLE = bin/test.out

all : $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE) : $(OBJECTS)
	$(CC) $^ -o $@ -std=c++11 $(PYTHONFLAGS) $(GRAPHICFLAGS)

build/%.o : src/%.cpp
	$(CC) $(CFLAGS) $< -o $@ -std=c++11

.PHONY : clean
clean:
	rm -f build/*.o build/*.d bin/*.out

.PHONY : test
test : $(TEST_SOURCES) $(TEST_EXECUTABLE)
	cd bin && ./test.out

$(TEST_EXECUTABLE) : $(TEST_OBJECTS)
	$(CC) $^ -o $@ -std=c++11 $(PYTHONFLAGS) $(GRAPHICFLAGS)

build/%_test.o : src/%.cpp
	$(CC) $(CFLAGS) $< -o $@ -std=c++11

build/%.o : test/%.cpp
	$(CC) $(CFLAGS) $< -o $@ -std=c++11

include $(wildcard build/*.d)