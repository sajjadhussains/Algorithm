#include<bits/stdc++.h>
using namespace std;

const int N = 1005;
int blueberries[N];
int dp[N][1005];

int max_blueberries(int n, int k) {
    // Base case
    if (n <= 0 || k <= 0) {
        return 0;
    }

    // If the result is already calculated, return it
    if (dp[n][k] != -1) {
        return dp[n][k];
    }

    // If picking from the current bush doesn't exceed the limit
    if (blueberries[n] <= k) {
        // Teresa has two choices: pick or skip the current bush
        dp[n][k] = max(max_blueberries(n-1, k), max_blueberries(n-2, k-blueberries[n]) + blueberries[n]);
    } else {
        // If picking from the current bush exceeds the limit, skip it
        dp[n][k] = max_blueberries(n-1, k);
    }

    return dp[n][k];
}

int main() {
    int t;
    cin >> t;

    for (int scenario = 1; scenario <= t; ++scenario) {
        int n, k;
        cin >> n >> k;

        for (int i = 1; i <= n; ++i) {
            cin >> blueberries[i];
        }

        // Initialize the memoization table
        memset(dp, -1, sizeof(dp));

        int result = max_blueberries(n, k);

        cout << "Scenario #" << scenario << ": " << result << endl;
    }

    return 0;
}
