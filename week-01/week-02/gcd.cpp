#include<bits/stdc++.h>

using namespace std;
int gcd(int a,int b)
{
    if(b==0) return a;
    else return gcd(b,a%b);
}

int main()
{
    int result=gcd(20,3);
    cout<<result<<endl;
    return 0;

}