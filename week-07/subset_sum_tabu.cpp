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

int main()
{
    int n,target;
    cin>>n>>target;

    for(int i=1;i<=n;i++){
        cin>>nums[i];
    }
    //1.handle base case
    dp[0][0]=1;
    for(int i=1;i<=target;i++){
        dp[0][i]=0;
    }

    //2.Loop over the states
    for(int i=1;i<=n;i++){
        for(int j=1;j<=target;j++){
            //2.1->calculate the smaller subproblems
            int ans1 = dp[i-1][j];
            if(j<nums[i]){
                dp[i][j]=ans1;
            }
            else{
                int ans2 = dp[i-1][j-nums[i]];
                dp[i][j]=ans1 || ans2;
            }
        }
    }
    cout<<dp[n][target]<<endl;
    return 0;
}