#include<bits/stdc++.h>

using namespace std;
const long long int N=101;
long long int dp[N];
int main()
{
    int n;
    cin>>n;
    //define base case:
    dp[1]=1;
    dp[2]=1;
    for(int i=3;i<=n;i++){
        //calculate the result from smaller subproblem
        dp[i]=dp[i-1]+dp[i-2];
    }
    cout<<dp[n]<<endl;

    return 0;
}