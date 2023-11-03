/*
    -the process of solving dp using tabulation technique:
    1._handle base case
    2._loop through the states
        2.1.1_calculate the answer from smaller subproblems
*/

#include<bits/stdc++.h>

using namespace std;

const int N = 101;
long long dp[N];

int main()
{
    int n;
    cin>>n;

    for(int i=0;i<=n;i++){
        dp[i]=-1;
    }
    //base case
    dp[1]=1;
    dp[2]=1;
    //loop through the state
    for(int i=3;i<=n;i++){
        dp[i]=dp[i-1]+dp[i-2];
    }

    cout<<dp[n]<<endl;

    return 0;
}