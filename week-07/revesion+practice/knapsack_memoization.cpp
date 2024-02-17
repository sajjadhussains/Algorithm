#include<bits/stdc++.h>

using namespace std;
const int N=102;
const int M=1e5+5;
int value[N];
int w[N];
long long dp[N][M];
long long knapsack(int n,int cap){
    //define base case
    if(n==0){
        return 0;
    }
    //if the result is already calculated
    if(dp[n][cap]!=-1){
        return dp[n][cap];
    }
    if(cap<w[n]){
        long long ans=knapsack(n-1,cap);
        dp[n][cap]=ans;
        return ans;
    }
    long long ans1= value[n]+knapsack(n-1,cap-w[n]);
    long long ans2= knapsack(n-1,cap);
    long long ans= max(ans1,ans2);
    dp[n][cap]=ans;
    return ans;
}
int main()
{
    int n,cap;
    cin>>n>>cap;
    for(int i=1;i<=n;i++){
        cin>>w[i]>>value[i];
    }
    for(int i=0;i<=n;i++){
        for(int j=0;j<=cap;j++){
            dp[i][j]=-1;
        }
    }
    cout<<knapsack(n,cap)<<endl;

    return 0;
}