#include <bits/stdc++.h>
using namespace std;

long long linearSum(const vector<int>& values) {
    long long total = 0;
    for (int value : values) {
        total += value;
    }
    return total;
}

long long pairCount(const vector<int>& values) {
    long long count = 0;
    for (size_t i = 0; i < values.size(); ++i) {
        for (size_t j = i + 1; j < values.size(); ++j) {
            if ((values[i] + values[j]) % 2 == 0) {
                ++count;
            }
        }
    }
    return count;
}

template <typename Function>
void timeIt(const string& label, Function function) {
    auto start = chrono::high_resolution_clock::now();
    long long result = function();
    auto stop = chrono::high_resolution_clock::now();
    auto microseconds = chrono::duration_cast<chrono::microseconds>(stop - start).count();

    cout << label << " -> result: " << result << ", time: " << microseconds << " us\n";
}

int main() {
    vector<int> values(3000);
    iota(values.begin(), values.end(), 1);

    timeIt("O(n) sum", [&] {
        return linearSum(values);
    });

    timeIt("O(n^2) pair count", [&] {
        return pairCount(values);
    });

    cout << "\nBig-O ignores exact machine time, but timing helps you feel growth.\n";
    return 0;
}

