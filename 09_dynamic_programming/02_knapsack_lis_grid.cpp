#include <bits/stdc++.h>
using namespace std;

int knapsack01(const vector<int>& weights, const vector<int>& values, int capacity) {
    int n = static_cast<int>(weights.size());
    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));

    for (int i = 1; i <= n; ++i) {
        for (int cap = 0; cap <= capacity; ++cap) {
            dp[i][cap] = dp[i - 1][cap];
            if (weights[i - 1] <= cap) {
                dp[i][cap] = max(dp[i][cap], dp[i - 1][cap - weights[i - 1]] + values[i - 1]);
            }
        }
    }

    return dp[n][capacity];
}

int lisLength(const vector<int>& values) {
    vector<int> tails;
    for (int value : values) {
        auto it = lower_bound(tails.begin(), tails.end(), value);
        if (it == tails.end()) {
            tails.push_back(value);
        } else {
            *it = value;
        }
    }
    return static_cast<int>(tails.size());
}

int gridPaths(int rows, int cols) {
    vector<vector<int>> dp(rows, vector<int>(cols, 0));

    for (int row = 0; row < rows; ++row) {
        for (int col = 0; col < cols; ++col) {
            if (row == 0 || col == 0) {
                dp[row][col] = 1;
            } else {
                dp[row][col] = dp[row - 1][col] + dp[row][col - 1];
            }
        }
    }

    return dp[rows - 1][cols - 1];
}

int main() {
    vector<int> weights = {2, 3, 4, 5};
    vector<int> values = {3, 4, 5, 6};
    cout << "0/1 knapsack best value: " << knapsack01(weights, values, 5) << '\n';

    vector<int> sequence = {10, 9, 2, 5, 3, 7, 101, 18};
    cout << "LIS length: " << lisLength(sequence) << '\n';

    cout << "Grid paths 3x4: " << gridPaths(3, 4) << '\n';

    return 0;
}

