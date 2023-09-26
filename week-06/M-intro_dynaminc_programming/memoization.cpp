/*
    Memoization process/recursive/Top Down:
        fun(n,a,b,c){
            1.handle base case
            2.if current state is already solved, return the result
            3.calculate the result from smaller subproblems.
        }
*/

#include<bits/stdc++.h>

using namespace std;
const int N=101;
int dp[N];
int fibo(int n){
    //1.base case
    if(n<=2){
        return 1;
    }
    //2.if current state is already solved return the result
    if(dp[n]!=-1){
        return dp[n];
    }
    //3.calculate from smaller subproblem
    int ans = fibo(n-1)+fibo(n-2);
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

    cout<<fibo(n)<<endl;
    return 0;
}