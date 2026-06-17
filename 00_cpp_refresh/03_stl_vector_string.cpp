#include <bits/stdc++.h>
using namespace std;

template <typename T>
void print(const vector<T>& values) {
    for (const T& value : values) {
        cout << value << ' ';
    }
    cout << '\n';
}

int main() {
    vector<int> numbers = {4, 1, 7, 1, 9, 3};
    sort(numbers.begin(), numbers.end());

    cout << "Sorted: ";
    print(numbers);

    numbers.erase(unique(numbers.begin(), numbers.end()), numbers.end());
    cout << "Unique: ";
    print(numbers);

    int target = 7;
    auto it = lower_bound(numbers.begin(), numbers.end(), target);
    if (it != numbers.end() && *it == target) {
        cout << target << " found at index " << distance(numbers.begin(), it) << '\n';
    }

    string text = "data structures";
    text[0] = static_cast<char>(toupper(text[0]));
    text += " in C++";
    cout << "Text: " << text << '\n';
    cout << "Substring: " << text.substr(5, 10) << '\n';

    return 0;
}

