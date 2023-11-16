#include <bits/stdc++.h>

using namespace std;
const int N = 1e4 + 5;
int monsters[N];
long long dp[N];

long long total_max_coins_recursive(int n) {
    if (n == 0) {
        return 0;
    } else if (n == 1) {
        return monsters[0];
    }

    if (dp[n] != -1) {
        return dp[n];
    }

    // Include the current monster and skip the next one
    long long includeCurrent = monsters[n - 1] + total_max_coins_recursive(n - 2);

    // Exclude the current monster and move to the next one
    long long excludeCurrent = total_max_coins_recursive(n - 1);

    // Return the maximum of the two cases
    return dp[n] = max(includeCurrent, excludeCurrent);
}

int main() {
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        int n;
        cin >> n;

        for (int j = 0; j < n; j++) {
            cin >> monsters[j];
        }

        // Initialize memoization table to -1 for each test case
        memset(dp, -1, sizeof(dp));

        cout << "Case " << i << ": " << total_max_coins_recursive(n) << endl;
    }

    return 0;
}
