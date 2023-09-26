#include<bits/stdc++.h>


/*
    1 1
*/



using namespace std;
long long arr[101];
int fun(int n)
{
    //optimized code for time complexity
    if(n<=2)    return 1;
    if(arr[n] != 0) return arr[n];
    arr[n] = fun(n-1)+fun(n-2);
    return arr[n];
}
int main()
{
    int n;
    cin>>n;
    cout<<fun(n)<<endl;

    return 0;
}