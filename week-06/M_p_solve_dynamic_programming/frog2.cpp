#include<bits/stdc++.h>

using namespace std;
const int N =1e5+5;
const int INF = 2e9;

int h[N],dp[N];
int n,k;
int stone_2(int n){
    //1.define base case
    if(n==1){
        return 0;
    }
    //2.if answer is already calculated return it
    if(dp[n]!=-1){
        return dp[n];
    }
    //3.calculate answer from smaller subproblem
    int ans = INF;
    for(int i=1;i<=k;i++){
        //corner case
        if(n-i<=0){
            break;/*you can continue it also*/
        }
        int candidate_ans = stone_2(n-i)+abs(h[n]-h[n-i]);
        ans = min(ans,candidate_ans);
    }
    dp[n]=ans;
    return ans;
}
int main()
{
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>h[i];
    }
    for(int i=1;i<=n;i++){
        dp[i]=-1;
    }
    int result = stone_2(n);
    cout<<result<<endl;
    return 0;
}