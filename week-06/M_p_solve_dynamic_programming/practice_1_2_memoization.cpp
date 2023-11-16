//problem_link:https://leetcode.com/problems/climbing-stairs/

#include<bits/stdc++.h>

using namespace std;
const int N=46;
int dp[N];

int climbStairs(int n){
    if(n==1) return 1;
    if(n==2) return 2;
    if(dp[n]!=-1){
        return dp[n];
    }
    int ans = climbStairs(n-1)+climbStairs(n-2);
    dp[n]=ans;
    return ans;
}
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        dp[i]=-1;
    }
    cout<<climbStairs(n)<<endl;
    return 0;
}