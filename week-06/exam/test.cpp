#include<bits/stdc++.h>

using namespace std;
const int N = 1e5 + 5;
int points[N];
int dp[N];

int max_points(int n)
{
    if (n <= 0) {
        return 0;
    }
    if (n == 1) {
        return points[1];
    }
    if (n == 2) {
        return max(points[1], points[2]);
    }

    if (dp[n] != -1) {
        return dp[n];
    }

    int ans1 = max_points(n - 2) + points[n];
    int ans2 = max_points(n - 1);
    int ans = max(ans1, ans2);
    dp[n] = ans;
    return ans;
}

int main()
{
    int n;
    cin >> n;

    int max_element = 0;

    for (int i = 0; i < n; i++) {
        cin >> points[i];
        max_element = max(max_element, points[i]);
    }

    // Considering only elements up to the maximum element in the sequence
    vector<long long> freq(max_element + 1, 0);

    for (int i = 0; i < n; i++) {
        freq[points[i]] += points[i];
    }

    memset(dp, -1, sizeof(dp));

    // Using an iterative dynamic programming approach
    for (int i = 0; i <= max_element; i++) {
        dp[i] = max(dp[i - 1], dp[i - 2] + freq[i]);
    }

    cout << dp[max_element] << endl;

    return 0;
}
