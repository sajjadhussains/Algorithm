#include<bits/stdc++.h>

using namespace std;
const int N=102;
const int M = 1e5+5;
int value[N];
int wt[M];
long long dp[N][M];
int main()
{
    int n,cap;
    cin>>n>>cap;
    for(int i=1;i<=n;i++){
        cin>>wt[i]>>value[i];
    }
    //1.define base case
    for(int i=0;i<=cap;i++){
        dp[0][i]=0;
    }
    //2.loop through the states
    for(int i=1;i<=n;i++){
        for(int j=0;j<=cap;j++){
            if(j<wt[i]){
                cout<<"corner case: "<<j<<"->"<<wt[i]<<endl;
                dp[i][j]=dp[i-1][j];
            }
            else{
               dp[i][j]=max(value[i]+dp[i-1][j-wt[i]],
                            dp[i-1][j]);
               cout<<"ans: "<<j<<"->"<<dp[i][j]<<endl;
            }
        }
    }

    cout<<dp[n][cap]<<endl;

    return 0;
}