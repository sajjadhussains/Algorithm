// problem-link:

/*  __
    ||   steps to solve knapsack dp problem:
         1.State-->knapsack(n,cap)
         2.Recurrence relation
            knapsack(n,cap)=max(
                            value[n]+knapsack(n-1,cap-wt[n]),
                            knapsack(n-1,cap)
                        )
        3.base case:
            knapsack(0,cap)=0
*/

#include <bits/stdc++.h>

using namespace std;
const int N = 102;
const int M = 1e5 + 5;
long long dp[N][M];
int wt[N], value[N];

int main()
{
    int n, w;
    cin >> n >> w;
    for (int i = 1; i <= n; i++)
    {
        cin >> wt[i] >> value[i];
    }

    // 1.define base case
    for (int i = 0; i <= w; i++)
    {
        dp[0][i] = 0;
    }
    // 2.loop through the states
    for (int i = 1; i <= n; i++)
    {
        for (int cap = 0; cap <= w; cap++)
        {
            if (cap < wt[i])
            {
                dp[i][cap] = dp[i - 1][cap];
            }
            else
            {
                dp[i][cap] = max(
                    value[i] + dp[i - 1][cap - wt[i]],
                    dp[i - 1][cap]

                );
            }
        }
    }

    cout<<dp[n][w]<<endl;

    return 0;
}