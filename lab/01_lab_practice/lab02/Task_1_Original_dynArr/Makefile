CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra
TARGET = lab3_task1

all: $(TARGET)

$(TARGET): main.cpp dynarr.cpp dynarr.h
	$(CXX) $(CXXFLAGS) main.cpp dynarr.cpp -o $(TARGET)

clean:
	rm -f $(TARGET)
