#include <bits/stdc++.h>
using namespace std;

const int N = 1005;
int dp[N][1005]; // Considering K can be up to 1000

int max_blueberries_helper(int n, int k, int blueberries[]) {
    if (n == 0 || k == 0) {
        return 0;
    }

    if (dp[n][k] != -1) {
        return dp[n][k];
    }

    int result = max(
    max_blueberries_helper(n - 1, k, blueberries),
    (k >= n) ? max_blueberries_helper(n - 2, k - n, blueberries) + blueberries[n - 1] : 0
);

    dp[n][k] = result;
    return result;
}

int max_blueberries(int n, int k, int blueberries[]) {
    memset(dp, -1, sizeof(dp));
    return max_blueberries_helper(n, k, blueberries);
}

int main() {
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        int n, k;
        cin >> n >> k;
        int blueberries[n];
        for (int j = 0; j < n; j++) {
            cin >> blueberries[j];
        }
        int result = max_blueberries(n, k, blueberries);
        cout << "Scenario #" << i << ": " << result << endl;
    }
    return 0;
}
