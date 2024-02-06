#include<bits/stdc++.h>

using namespace std;
const int N=1e5+5;
const int INF=1e9;
int dp[N];
int h[N];
int K;
int stone_2(int n){
    //define base case:
    if(n==1){
        return 0;
    }
    //if the result is already calculated return result
    if(dp[n]!=-1){
        return dp[n];
    }
    //identify the recursive equation from smaller subproblem
    int ans=INF;
    for(int i=1;i<=K;i++){
        if(n-i<=0){
            break;
        }
        int candidate_ans=stone_2(n-i)+abs(h[n]-h[n-i]);
        ans=min(ans,candidate_ans);
    }
    dp[n]=ans;
    return ans;
}
int main()
{
    int n;
    cin>>n>>K;
    for(int i=0;i<n;i++){
        cin>>h[i];
    }
    for(int i=0;i<N;i++){
        dp[i]=-1;
    }
    cout<<stone_2(n)<<endl;

    return 0;

}