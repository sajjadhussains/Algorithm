#include<bits/stdc++.h>

using namespace std;
int fibo(int n){
    if(n<=2) return 1;
    int fibo1 = fibo(n-1);
    int fibo2 = fibo(n-2);

    return fibo1+fibo2;
}
int main()
{
    cout<<fibo(1)<<endl;

    return 0;

}