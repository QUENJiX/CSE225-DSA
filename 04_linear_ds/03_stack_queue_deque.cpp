#include <bits/stdc++.h>
using namespace std;

bool balancedBrackets(const string& text) {
    stack<char> open;
    unordered_map<char, char> matching = {{')', '('}, {']', '['}, {'}', '{'}};

    for (char ch : text) {
        if (ch == '(' || ch == '[' || ch == '{') {
            open.push(ch);
        } else if (matching.count(ch) > 0) {
            if (open.empty() || open.top() != matching[ch]) {
                return false;
            }
            open.pop();
        }
    }

    return open.empty();
}

vector<int> slidingWindowMaximum(const vector<int>& values, int windowSize) {
    deque<int> candidates;
    vector<int> answer;

    for (int i = 0; i < static_cast<int>(values.size()); ++i) {
        while (!candidates.empty() && candidates.front() <= i - windowSize) {
            candidates.pop_front();
        }

        while (!candidates.empty() && values[candidates.back()] <= values[i]) {
            candidates.pop_back();
        }

        candidates.push_back(i);
        if (i >= windowSize - 1) {
            answer.push_back(values[candidates.front()]);
        }
    }

    return answer;
}

int main() {
    cout << boolalpha;
    cout << "{[()]} balanced? " << balancedBrackets("{[()]}") << '\n';
    cout << "{[(])} balanced? " << balancedBrackets("{[(])}") << '\n';

    queue<string> waiting;
    waiting.push("first");
    waiting.push("second");
    waiting.push("third");
    cout << "Queue front: " << waiting.front() << '\n';

    vector<int> values = {1, 3, -1, -3, 5, 3, 6, 7};
    vector<int> maximums = slidingWindowMaximum(values, 3);
    cout << "Sliding maximums: ";
    for (int value : maximums) {
        cout << value << ' ';
    }
    cout << '\n';

    return 0;
}

