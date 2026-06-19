CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -pedantic
TARGET = box_volume

all: $(TARGET)

$(TARGET): main.cpp Box.cpp Box.h
	$(CXX) $(CXXFLAGS) main.cpp Box.cpp -o $(TARGET)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET)
