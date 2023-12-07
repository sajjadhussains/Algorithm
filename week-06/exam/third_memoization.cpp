#include<bits/stdc++.h>

using namespace std;
const int N = 1e5 + 5;
int points[N];
long long dp[N];

long long max_points(int n) {
    // Base case
    if (n <= 0) {
        return 0;
    }
    // To avoid recalculation
    if (dp[n] != -1) {
        return dp[n];
    }
    // Recursive equation from smaller subproblems
    long long includeCurrent = max_points(n - 2) + points[n];
    long long excludeCurrent = max_points(n - 1);
    long long ans = max(includeCurrent, excludeCurrent);
    dp[n] = ans;
    return ans;
}

int main() {
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> points[i];
    }

    // Initialize dp array with -1
    memset(dp, -1, sizeof(dp));

    long long result = max_points(n);
    cout << result << endl;

    return 0;
}
