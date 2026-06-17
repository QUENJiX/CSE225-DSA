#include <bits/stdc++.h>
using namespace std;

vector<int> prefixSums(const vector<int>& values) {
    vector<int> prefix(values.size() + 1, 0);
    for (size_t i = 0; i < values.size(); ++i) {
        prefix[i + 1] = prefix[i] + values[i];
    }
    return prefix;
}

bool isPalindrome(const string& text) {
    int left = 0;
    int right = static_cast<int>(text.size()) - 1;

    while (left < right) {
        if (text[left] != text[right]) {
            return false;
        }
        ++left;
        --right;
    }
    return true;
}

int longestUniqueSubstring(const string& text) {
    vector<int> lastSeen(256, -1);
    int best = 0;
    int left = 0;

    for (int right = 0; right < static_cast<int>(text.size()); ++right) {
        unsigned char ch = static_cast<unsigned char>(text[right]);
        left = max(left, lastSeen[ch] + 1);
        lastSeen[ch] = right;
        best = max(best, right - left + 1);
    }

    return best;
}

int main() {
    vector<int> values = {2, 4, 6, 8, 10};
    vector<int> prefix = prefixSums(values);

    int left = 1;
    int right = 3;
    cout << "Range sum [1, 3]: " << prefix[right + 1] - prefix[left] << '\n';

    cout << boolalpha;
    cout << "racecar palindrome? " << isPalindrome("racecar") << '\n';
    cout << "Longest unique substring in abcaabcd: " << longestUniqueSubstring("abcaabcd") << '\n';

    return 0;
}

