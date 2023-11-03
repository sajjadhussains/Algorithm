#include<bits/stdc++.h>

using namespace std;
int fibo(int n){
    if(n==1){
        return 0;
    }
    for(int i=1;i<=3;i++){
        cout<<fibo(n-1);
        cout<<i<<endl;
    }
}
int main()
{
    int n=5;
    int result = fibo(n);
   return 0; 
}