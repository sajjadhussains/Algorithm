#include<bits/stdc++.h>
long long arr[101];
using namespace std;
long long fibo(int n)
{
    if(n<=2) return 1;
    if(arr[n]!=0){
        return arr[n];
    }
    arr[n]=fibo(n-1)+fibo(n-2);
    return arr[n];
}
int main()
{
    cout<<fibo(50)<<endl;
    return 0;
}

//output will come->12586269025