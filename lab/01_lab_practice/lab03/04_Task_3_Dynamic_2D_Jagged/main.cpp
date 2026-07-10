#include <iostream>
#include <limits>
using namespace std;

int main() {
    int rows = 3;

    int* columns = new int[rows];

    columns[0] = 5;
    columns[1] = 10;
    columns[2] = 15;

    char** text = new char*[rows];

    for (int i = 0; i < rows; i++) {
        text[i] = new char[columns[i] + 1];
    }

    for (int i = 0; i < rows; i++) {
        cout << "Enter string for row " << i
            << " (maximum " << columns[i] << " characters): ";

        cin.getline(text[i], columns[i] + 1);

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "Input was too long. Only the first "
                << columns[i] << " characters were stored.\n";
        }
    }

    cout << "\nStored strings:\n";

    for (int i = 0; i < rows; i++) {
        cout << "Row " << i << ": " << text[i] << endl;
    }

    for (int i = 0; i < rows; i++) {
        delete[] text[i];
    }

    delete[] text;
    delete[] columns;

    text = nullptr;
    columns = nullptr;

    return 0;
}
