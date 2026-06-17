#include <bits/stdc++.h>
using namespace std;

int linearSearch(const vector<int>& values, int target) {
    for (int i = 0; i < static_cast<int>(values.size()); ++i) {
        if (values[i] == target) {
            return i;
        }
    }
    return -1;
}

int binarySearch(const vector<int>& values, int target) {
    int low = 0;
    int high = static_cast<int>(values.size()) - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (values[mid] == target) {
            return mid;
        }
        if (values[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return -1;
}

int firstAtLeast(const vector<int>& values, int target) {
    int low = 0;
    int high = static_cast<int>(values.size()) - 1;
    int answer = static_cast<int>(values.size());

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (values[mid] >= target) {
            answer = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return answer;
}

int main() {
    vector<int> values = {1, 3, 3, 7, 8, 10, 12};

    cout << "Linear search 7: " << linearSearch(values, 7) << '\n';
    cout << "Binary search 7: " << binarySearch(values, 7) << '\n';
    cout << "First index with value >= 6: " << firstAtLeast(values, 6) << '\n';

    auto it = lower_bound(values.begin(), values.end(), 6);
    cout << "STL lower_bound index: " << distance(values.begin(), it) << '\n';

    return 0;
}

