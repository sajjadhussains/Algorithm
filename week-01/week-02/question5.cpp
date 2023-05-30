#include<bits/stdc++.h>

using namespace std;

string int_to_binary(int decimal)
{
    if(decimal==0) return "";
    
    if(decimal%2==0){
        return int_to_binary(decimal/2)+"0";
    }
    else{
        return int_to_binary(decimal/2)+"1";
    }
}

int main()
{
    string result=int_to_binary(10);
    cout<<result<<endl;
    cout<<"hello world"<<endl;

    return 0;

}