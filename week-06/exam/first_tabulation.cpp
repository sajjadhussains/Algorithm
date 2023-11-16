// problem_link:https://www.spoj.com/problems/FARIDA/en/

#include <bits/stdc++.h>

using namespace std;
const int N = 1e6 + 2;
long long int monsters[N];
long long int dp[N];

long long int total_max_coins(int n)
{
   if (n<2){
    return max(monsters[0],monsters[1]);
    // return monsters[0];
   }
   for(int i=0;i<n;i++){
    dp[i]=-1;
   }
   dp[0]=monsters[0];
   dp[1]=max(monsters[0],monsters[1]);

   for(int i=2;i<n;i++){
    dp[i]=max(dp[i-2]+monsters[i],dp[i-1]);
   }
   return dp[n-1];
}
int main()
{
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        int n;
        cin >> n;

        for (int i = 0; i < n; i++)
        {
            cin >> monsters[i];
        }
        
        cout <<"Case "<<i<<": "<<total_max_coins(n)<< endl;
    }

    return 0;
}