//solve tribonacci series
//if n=5
// then, the series will be 1 1 1 3 5

#include<bits/stdc++.h>

using namespace std;
const int N = 101;
long long dp[N];
long long tribo(int n)
{
    if(n<=3){
        return 1;
    }
    if(dp[n]!=-1){
        return dp[n];
    }
    long long ans = tribo(n-1)+tribo(n-2)+tribo(n-3);
    dp[n]=ans;
    return ans;
}
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        dp[i]=-1;
    }
    long long result = tribo(n);
    cout<<result<<endl;

    return 0;
}