#include <iomanip>
#include <iostream>
using namespace std;

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

    int* arr = new int[size];

    cout << "Enter " << size << " integers: ";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    cout << "1D array: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    delete[] arr;
    arr = nullptr;
}

void equalRowCharArray() {
    int rows, cols;
    cout << "Enter rows and max word length: ";
    cin >> rows >> cols;

    char** words = new char*[rows];
    for (int i = 0; i < rows; i++) {
        words[i] = new char[cols + 1];
    }

    cout << "Enter " << rows << " words: ";
    for (int i = 0; i < rows; i++) {
        cin >> setw(cols + 1) >> words[i];
    }

    cout << "Words:" << endl;
    for (int i = 0; i < rows; i++) {
        cout << words[i] << endl;
    }

    for (int i = 0; i < rows; i++) {
        delete[] words[i];
    }
    delete[] words;
    words = nullptr;
}

void jaggedIntArray() {
    int rows;
    cout << "Enter jagged row count: ";
    cin >> rows;

    int* cols = new int[rows];
    int** data = new int*[rows];

    for (int i = 0; i < rows; i++) {
        cout << "Columns in row " << i << ": ";
        cin >> cols[i];
        data[i] = new int[cols[i]];
    }

    for (int i = 0; i < rows; i++) {
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

    for (int i = 0; i < rows; i++) {
        delete[] data[i];
    }
    delete[] data;
    delete[] cols;
    data = nullptr;
    cols = nullptr;
}

int main() {
    singleValue();
    dynamic1DArray();
    equalRowCharArray();
    jaggedIntArray();

    return 0;
}
