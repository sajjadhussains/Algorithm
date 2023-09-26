#include<bits/stdc++.h>
//problem_link:https://atcoder.jp/contests/dp/tasks/dp_a
using namespace std;
const int N=1e5+5;
int dp[N];
int h[N];
int stone(int n){
    if(n==1){
        return 0;
    }
    if(dp[n]!=-1){
        return dp[n];
    }
    int ans1 = stone(n-2)+abs(h[n]-h[n-2]);
    int ans2 = stone(n-1)+abs(h[n]-h[n-1]);
    int ans = min(ans1,ans2);
    return ans;
}
int main()
{
    int n;
    cin>>n;
    
    for(int i=1;i<=n;i++){
        cin>>h[i];
    }
    for(int i=1;i<=n;i++){
        dp[i]=-1;
    }

    int result = stone(n);
    cout<<result<<endl;
    return 0;
}
