#include <bits/stdc++.h>
using namespace std;

void generateSubsets(const vector<int>& values, int index, vector<int>& current) {
    if (index == static_cast<int>(values.size())) {
        cout << "{ ";
        for (int value : current) {
            cout << value << ' ';
        }
        cout << "}\n";
        return;
    }

    generateSubsets(values, index + 1, current);

    current.push_back(values[index]);
    generateSubsets(values, index + 1, current);
    current.pop_back();
}

void generatePermutations(vector<int>& values, int index) {
    if (index == static_cast<int>(values.size())) {
        for (int value : values) {
            cout << value << ' ';
        }
        cout << '\n';
        return;
    }

    for (int i = index; i < static_cast<int>(values.size()); ++i) {
        swap(values[index], values[i]);
        generatePermutations(values, index + 1);
        swap(values[index], values[i]);
    }
}

int main() {
    vector<int> values = {1, 2, 3};
    vector<int> current;

    cout << "Subsets:\n";
    generateSubsets(values, 0, current);

    cout << "\nPermutations:\n";
    generatePermutations(values, 0);

    return 0;
}

