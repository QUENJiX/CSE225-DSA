#include <bits/stdc++.h>
using namespace std;

int binarySearchIndex(const vector<int>& values, int target) {
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

int firstTrue(int low, int high, const function<bool(int)>& ok) {
    int answer = high + 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (ok(mid)) {
            answer = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return answer;
}

int main() {
    vector<int> values = {1, 3, 3, 5, 8, 13, 21};
    cout << "Index of 8: " << binarySearchIndex(values, 8) << '\n';
    cout << "Index of 4: " << binarySearchIndex(values, 4) << '\n';

    auto lower = lower_bound(values.begin(), values.end(), 3);
    auto upper = upper_bound(values.begin(), values.end(), 3);
    cout << "Count of 3 using bounds: " << distance(lower, upper) << '\n';

    int needed = 47;
    int minimumDays = firstTrue(1, 20, [&](int days) {
        return days * 3 >= needed;
    });
    cout << "Minimum days for 47 tasks at 3/day: " << minimumDays << '\n';

    return 0;
}

