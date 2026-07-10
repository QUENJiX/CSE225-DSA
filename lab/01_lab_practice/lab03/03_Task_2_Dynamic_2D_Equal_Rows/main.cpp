#include <iostream>
#include <limits>
using namespace std;

int main() {
    int rows = 2;
    int columns = 10;

    char** text = new char*[rows];

    for (int i = 0; i < rows; i++) {
        text[i] = new char[columns + 1];
    }

    for (int i = 0; i < rows; i++) {
        cout << "Enter string for row " << i << ": ";
        cin.getline(text[i], columns + 1);

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "Input was too long. Only the first "
                << columns << " characters were stored.\n";
        }
    }

    cout << "\nStored strings:\n";

    for (int i = 0; i < rows; i++) {
        cout << text[i] << '\n';
    }

    for (int i = 0; i < rows; i++) {
        delete[] text[i];
    }

    delete[] text;
    text = nullptr;

    return 0;
}
