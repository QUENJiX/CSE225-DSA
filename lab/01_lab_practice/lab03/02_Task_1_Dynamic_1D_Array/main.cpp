#include <iostream>
using namespace std;

int main() {
    int size;

    cout << "Enter array size: ";
    cin >> size;

    int* arr = new int[size];

    cout << "Enter " << size << " integer values: ";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    cout << "Array values: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    delete[] arr;
    arr = nullptr;

    return 0;
}
