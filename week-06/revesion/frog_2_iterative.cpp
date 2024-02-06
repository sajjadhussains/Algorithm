#include<bits/stdc++.h>

using namespace std;
const int N=1e5+5;
const int INF=1e9;
int dp[N],K;
int h[N];
int main()
{
    int n;
    cin>>n>>K;
    for(int i=1;i<=n;i++){
        cin>>h[i];
    }
    //define base case
    dp[1]=0;
    //loop through the states
    for(int i=2;i<=n;i++){
        dp[i]=INF;
        for(int j=1;j<=K;j++){
            int from_stone=i-j;
            if(from_stone<=0){
                break;
            }
            int candidate_ans=(dp[from_stone]+abs(h[i]-h[from_stone]));
            dp[i]=min(dp[i],candidate_ans);
        }
    }
    cout<<dp[n]<<endl;

    return 0;
}