#include <bits/stdc++.h>
using namespace std;

long long fibMemo(int n, vector<long long>& memo) {
    if (n <= 1) {
        return n;
    }
    if (memo[n] != -1) {
        return memo[n];
    }
    return memo[n] = fibMemo(n - 1, memo) + fibMemo(n - 2, memo);
}

long long fibTabulation(int n) {
    vector<long long> dp(n + 1, 0);
    if (n >= 1) {
        dp[1] = 1;
    }

    for (int i = 2; i <= n; ++i) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[n];
}

int main() {
    int n = 10;
    vector<long long> memo(n + 1, -1);

    cout << "fibMemo(10): " << fibMemo(n, memo) << '\n';
    cout << "fibTabulation(10): " << fibTabulation(n) << '\n';

    cout << "\nDP recipe: state, transition, base case, answer.\n";
    return 0;
}

