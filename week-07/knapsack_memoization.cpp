//problem-link:

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

#include<bits/stdc++.h>

using namespace std;
const int N=102;
const int M = 1e5+5;
long long dp[N][M];
int wt[N],value[N];

long long knapsack(int n,int w)
{
    //1.base case
    if(n==0){
        return 0;
    }
    //2.if already calculated
    if(dp[n][w]!=-1){
        return dp[n][w];
    }
    if(w<wt[n]){
        long long ans = knapsack(n-1,w);
        dp[n][w]=ans;
        return ans;
    }
    //3.Recurrence relation
    long long ans1 = value[n]+knapsack(n-1,w-wt[n]);
    long long ans2 = knapsack(n-1,w);
    long long ans = max(ans1,ans2);
    dp[n][w]=ans;
    return ans;
}
int main()
{
    int n,w;
    cin>>n>>w;
    for(int i=1;i<=n;i++){
        cin>>wt[i]>>value[i];
    }
    for(int i=0;i<=n;i++){
        for(int j=0;j<=w;j++){
            dp[i][j]=-1;
        }
    }

    cout<<knapsack(n,w)<<endl;

    return 0;
}