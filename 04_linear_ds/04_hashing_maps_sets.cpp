#include <bits/stdc++.h>
using namespace std;

char firstUniqueCharacter(const string& text) {
    unordered_map<char, int> frequency;
    for (char ch : text) {
        ++frequency[ch];
    }

    for (char ch : text) {
        if (frequency[ch] == 1) {
            return ch;
        }
    }

    return '?';
}

bool hasPairWithSum(const vector<int>& values, int target) {
    unordered_set<int> seen;
    for (int value : values) {
        if (seen.count(target - value) > 0) {
            return true;
        }
        seen.insert(value);
    }
    return false;
}

int main() {
    string text = "algorithm";
    cout << "First unique character in " << text << ": " << firstUniqueCharacter(text) << '\n';

    map<string, int> orderedScores = {{"C", 70}, {"A", 90}, {"B", 80}};
    cout << "map keeps keys sorted:\n";
    for (const auto& [key, value] : orderedScores) {
        cout << key << " -> " << value << '\n';
    }

    vector<int> values = {4, 1, 9, 7, 5};
    cout << boolalpha << "Pair with sum 12? " << hasPairWithSum(values, 12) << '\n';

    return 0;
}

