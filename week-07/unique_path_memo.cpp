//problem_link:https://leetcode.com/problems/unique-paths/

#include<bits/stdc++.h>

using namespace std;
const int N=101;
int dp[N][N];
int unique_paths(int n,int m){
    if(n==0 && m==0){
        return 1;
    }
    //2.if result is already calculated
    if(dp[n][m]!=-1){
        return dp[n][m];
    }
    int ans=0;
    if(n>0) ans+=unique_paths(n-1,m);
    if(m>0) ans+=unique_paths(n,m-1);
    dp[n][m]=ans;
    return ans;
}
int main()
{
    int ro,col;
    cin>>ro>>col;
    for(int i=0;i<ro;i++){
        for(int j=0;j<col;j++){
            dp[i][j]=-1;
        }
    }
    cout<<unique_paths(ro-1,col-1)<<endl;

    return 0;
}