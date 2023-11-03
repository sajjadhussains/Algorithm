#include<bits/stdc++.h>
//problem_link:https://atcoder.jp/contests/dp/tasks/dp_a
using namespace std;
const int N=1e5+5;
int dp[N];
int h[N];
int stone(int n){
    
    cout<<"this programm is for n="<<n<<endl;
    if(n==1){
        return 0;
    }
    if(n==2){
        return 20;
    }
    if(dp[n]!=-1){
        return dp[n];
    }

    int ans1 = stone(n-1)+abs(h[n]-h[n-1]);
    cout<<"ans1:"<<ans1<<endl;

    if(n==2){
        dp[n]=ans1;
        return ans1;
    }
    
    int ans2 = stone(n-2)+abs(h[n]-h[n-2]);
    cout<<"ans2:"<<ans2<<endl;
    int ans = min(ans1,ans2);
    cout<<"ans:"<<ans<<endl;
    dp[n]=ans;
    for(int i=1;i<=n;i++){
        cout<<"dp:"<<dp[i]<<" ";
    }
    cout<<endl;
    cout<<"dp:"<<dp[n]<<endl;
    cout<<"final ans after function:"<<ans<<endl;

    return ans2;
}
int main()
{
    int n;
    cin>>n;
    
    for(int i=1;i<=n;i++){
        cin>>h[i];
    }
    // memset(dp,-1,sizeof(dp));
    for(int i=1;i<=n;i++){
        dp[i]=-1;
    }
    for(int i=0;i<n;i++){
        cout<<"dp:"<<dp[i]<<" ";
    }
    cout<<endl;
    int result = stone(n);
    for(int i=0;i<n;i++){
        cout<<"dp:"<<dp[i]<<" ";
    }
    cout<<"result:"<<result<<endl;
    // ss
    return 0;
}
