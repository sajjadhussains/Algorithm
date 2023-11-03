/*
    -the process of solving dp by memoization:
        1._define states
        2._identify the recursive equation from smaller subproblems
        3.define base cases
*/

#include<bits/stdc++.h>

using namespace std;
const int N=101;
long long dp[N];
long long fibo(int n){
    if(n<=2) return 1;
    if(dp[n]!=-1){
        return dp[n];
    }
    long long ans = fibo(n-1)+fibo(n-2);
    dp[n]=ans;
    
    return ans;
}
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<=n;i++){
        dp[i]=-1;
    }

    cout<<fibo(n)<<endl;

    return 0;
}