#include<bits/stdc++.h>

using namespace std;
const int N=102;
const int M=1e5+5;
int w[N];
int value[M];
long long dp[N][M];
int main()
{
    int n,cap;
    cin>>n>>cap;
    for(int i=1;i<=n;i++){
        cin>>w[i]>>value[i];
    }
    //define base case
    for(int i=0;i<=cap;i++){
        dp[0][i]=0;
    }

    //loop through the states
    for(int i=1;i<=n;i++){
        for(int j=0;j<=cap;j++){
            if(j<w[i]){
                dp[i][j]=dp[i-1][j];
            }
            else{
                dp[i][j]=max(value[i]+dp[i-1][j-w[i]],dp[i-1][j]);
            }
        }
    }
    cout<<dp[n][cap]<<endl;

    return 0;
}