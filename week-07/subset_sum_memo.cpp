/*
- state:fun(n,target)-->returns true if it is possible to create subset from numbers 1 to n and from the sum "target"

- recurrence: fun(n,target)->fun(n-1,target) OR
                            fun(n-1,target-nums[n])
                                    if target>=nums[n]
- base case: fun(0,target)->if target == 0
                            else 0

sample input:
6 9
3 34 4 12 5 2
*/

#include<bits/stdc++.h>

using namespace std;

const int N = 105;
const int M = 1e5+5;
int dp[N][M];
int nums[N];

bool subset_sum(int n,int target){
    //1.define base case
    if(n==0){
        if(target==0) return 1;
        return 0;
    }
    //2.if the dp[n][target] is already calculated
    if(dp[n][target]!=-1){
        return dp[n][target];
    }
    //3.identify the recursive equation from smaller subproblem
    bool ans1 = subset_sum(n-1,target);
    if(target<nums[n]){
        dp[n][target]=ans1;
        return ans1;
    }
    bool ans2 = subset_sum(n-1,target-nums[n]);
    bool ans = ans1 or ans2;
    dp[n][target]=ans;
    return ans;
}
int main()
{
    int n,target;
    cin>>n>>target;

    for(int i=1;i<=n;i++){
        cin>>nums[i];
    }
    for(int i=0;i<=n;i++){
        for(int j=0;j<=target;j++){
            dp[i][j]=-1;
        }
    }
    cout<<subset_sum(n,target)<<endl;

    return 0;
}