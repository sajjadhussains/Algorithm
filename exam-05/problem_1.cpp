//problem-link:https://www.eolymp.com/en/problems/992
#include<bits/stdc++.h>

using namespace std;
const int N=101;
int citys[N][N];

int main(){
    int n;
    cin>>n;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            citys[i][j]=0;
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int a;
            cin>>a;
            citys[i][j]=a;
        }
    }

    int count_roads=0;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(citys[i][j]==1){
                count_roads++;
            }
        }
    }
    cout<<count_roads/2<<endl;

    return 0;
}