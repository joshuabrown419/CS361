CC = g++
CFLAGS = -std=c++17 -fdiagnostics-color=always -g
TARGET = ./target/

SRCEXT = cpp
SOURCES = $(shell find ./src/ -type f -name "*.$(SRCEXT)")
OBJECTS = $(addprefix $(TARGET),$(notdir $(SOURCES:.cpp=.o)))

build: $(TARGET) $(OBJECTS)
	$(CC) $(CFLAGS) $(TARGET)PRNGService.o -o prng-service
	$(CC) $(CFLAGS) $(TARGET)ImageService.o -o image-service
	$(CC) $(CFLAGS) $(TARGET)UI.o -o ui

test: $(TARGET) main.cpp
	$(CC) $(CFLAGS) main.cpp -o test

$(TARGET):
	mkdir $(TARGET)

$(TARGET)%.o: ./src/%.$(SRCEXT)
	$(CC) $(CFLAGS) -c -o ./$@ $<

tar:
	tar -cvf $(TAR_NAME).tar Makefile *.cpp *.h *.hpp

clean:
	rm -r $(TARGET)
	rm -f $(EXE_FILE)