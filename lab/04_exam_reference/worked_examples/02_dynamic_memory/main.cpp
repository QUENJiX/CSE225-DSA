#include <iomanip>
#include <iostream>
using namespace std;

int* allocateIntArray(int size) {
    if (size <= 0) {
        return nullptr;
    }
    return new int[size];
}

void deleteIntArray(int*& arr) {
    delete[] arr;
    arr = nullptr;
}

char** allocateWords(int rows, int maxLength) {
    if (rows <= 0 || maxLength <= 0) {
        return nullptr;
    }

    char** words = new char*[rows];
    for (int i = 0; i < rows; i++) {
        words[i] = new char[maxLength + 1];
    }
    return words;
}

void deleteWords(char**& words, int rows) {
    if (words == nullptr) {
        return;
    }

    for (int i = 0; i < rows; i++) {
        delete[] words[i];
    }
    delete[] words;
    words = nullptr;
}

int** allocateJaggedIntArray(int rows, int*& cols) {
    if (rows <= 0) {
        cols = nullptr;
        return nullptr;
    }

    cols = new int[rows];
    int** data = new int*[rows];

    for (int i = 0; i < rows; i++) {
        cout << "Columns in row " << i << ": ";
        cin >> cols[i];

        if (cols[i] <= 0) {
            cols[i] = 0;
            data[i] = nullptr;
        } else {
            data[i] = new int[cols[i]];
        }
    }

    return data;
}

void deleteJaggedIntArray(int**& data, int*& cols, int rows) {
    if (data != nullptr) {
        for (int i = 0; i < rows; i++) {
            delete[] data[i];
        }
    }

    delete[] data;
    delete[] cols;
    data = nullptr;
    cols = nullptr;
}

void singleValue() {
    int* p = new int;
    *p = 10;

    cout << "Single value: " << *p << endl;

    delete p;
    p = nullptr;
}

void dynamic1DArray() {
    int size;
    cout << "Enter 1D array size: ";
    cin >> size;

    int* arr = allocateIntArray(size);
    if (arr == nullptr) {
        cout << "Invalid 1D array size" << endl;
        return;
    }

    cout << "Enter " << size << " integers: ";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    cout << "1D array: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    deleteIntArray(arr);
}

void equalRowCharArray() {
    int rows, maxLength;
    cout << "Enter rows and max word length: ";
    cin >> rows >> maxLength;

    char** words = allocateWords(rows, maxLength);
    if (words == nullptr) {
        cout << "Invalid word array size" << endl;
        return;
    }

    cout << "Enter " << rows << " words: ";
    for (int i = 0; i < rows; i++) {
        cin >> setw(maxLength + 1) >> words[i];
    }

    cout << "Words:" << endl;
    for (int i = 0; i < rows; i++) {
        cout << words[i] << endl;
    }

    deleteWords(words, rows);
}

void jaggedIntArray() {
    int rows;
    cout << "Enter jagged row count: ";
    cin >> rows;

    int* cols = nullptr;
    int** data = allocateJaggedIntArray(rows, cols);
    if (data == nullptr) {
        cout << "Invalid jagged row count" << endl;
        return;
    }

    for (int i = 0; i < rows; i++) {
        if (cols[i] == 0) {
            cout << "Skipping empty row " << i << endl;
            continue;
        }

        cout << "Enter row " << i << ": ";
        for (int j = 0; j < cols[i]; j++) {
            cin >> data[i][j];
        }
    }

    cout << "Jagged array:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols[i]; j++) {
            cout << data[i][j] << " ";
        }
        cout << endl;
    }

    deleteJaggedIntArray(data, cols, rows);
}

int main() {
    singleValue();
    dynamic1DArray();
    equalRowCharArray();
    jaggedIntArray();

    return 0;
}
