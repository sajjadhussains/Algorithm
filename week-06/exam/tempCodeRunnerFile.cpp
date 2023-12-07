//problem_link:https://codeforces.com/contest/456/problem/C

#include<bits/stdc++.h>

using namespace std;
const int N=1e5+5;
int points[N];
int dp[N];

int max_points(int n)
{
    //base case
    if(n==0){
        return 0;
    }
    //to avoid recalculate
    if(dp[n]!=-1){
        return dp[n];
    }
    //recursive equation from smaller sub problems
    int ans1=max_points(n-2)+points[n];
    int ans2=max_points(n-1);
    int ans = max(ans1,ans2);
    dp[n]=ans;
    return ans;

}
int main()
{
    int n;
    cin>>n;

    for(int i=1;i<=n;i++){
        cin>>points[i];
    }
    memset(dp,-1,sizeof(dp));
    int result = max_points(n);
    cout<<result<<endl;

    return 0;
}