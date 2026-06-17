#include <bits/stdc++.h>
using namespace std;

class IntBuffer {
private:
    int* data;
    size_t length;

public:
    explicit IntBuffer(size_t bufferLength)
        : data(new int[bufferLength]{}), length(bufferLength) {}

    ~IntBuffer() {
        delete[] data;
    }

    IntBuffer(const IntBuffer& other) : data(new int[other.length]), length(other.length) {
        copy(other.data, other.data + other.length, data);
    }

    IntBuffer& operator=(const IntBuffer& other) {
        if (this == &other) {
            return *this;
        }

        int* newData = new int[other.length];
        copy(other.data, other.data + other.length, newData);
        delete[] data;
        data = newData;
        length = other.length;
        return *this;
    }

    IntBuffer(IntBuffer&& other) noexcept : data(other.data), length(other.length) {
        other.data = nullptr;
        other.length = 0;
    }

    IntBuffer& operator=(IntBuffer&& other) noexcept {
        if (this == &other) {
            return *this;
        }

        delete[] data;
        data = other.data;
        length = other.length;
        other.data = nullptr;
        other.length = 0;
        return *this;
    }

    int& operator[](size_t index) {
        return data[index];
    }

    size_t size() const {
        return length;
    }
};

IntBuffer makeSquares(size_t n) {
    IntBuffer buffer(n);
    for (size_t i = 0; i < buffer.size(); ++i) {
        buffer[i] = static_cast<int>(i * i);
    }
    return buffer;
}

int main() {
    IntBuffer a = makeSquares(5);
    IntBuffer b = a;
    b[0] = 100;

    cout << "Original first value: " << a[0] << '\n';
    cout << "Copied first value: " << b[0] << '\n';

    IntBuffer c = move(b);
    cout << "Moved buffer size: " << c.size() << '\n';

    return 0;
}
