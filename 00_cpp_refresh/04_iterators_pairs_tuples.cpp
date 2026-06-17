#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<pair<string, int>> scores = {
        {"Ari", 91},
        {"Mira", 88},
        {"Tuhin", 95},
    };

    sort(scores.begin(), scores.end(), [](const auto& left, const auto& right) {
        return left.second > right.second;
    });

    cout << "Sorted by score:\n";
    for (const auto& [name, score] : scores) {
        cout << name << ": " << score << '\n';
    }

    tuple<int, string, double> record = {225, "DSA", 3.5};
    auto [code, title, credits] = record;
    cout << "\nTuple unpacked: " << code << ' ' << title << ' ' << credits << '\n';

    map<string, int> frequency;
    for (const auto& [name, score] : scores) {
        frequency[name] = score;
    }

    cout << "\nMap iteration:\n";
    for (auto it = frequency.begin(); it != frequency.end(); ++it) {
        cout << it->first << " -> " << it->second << '\n';
    }

    return 0;
}

