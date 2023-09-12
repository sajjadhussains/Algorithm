//problem -link:https://www.eolymp.com/en/problems/2470

#include<bits/stdc++.h>

using namespace std;
const int N=100;
int adj_matrix[N][N];

int main()
{
    int n;
    cin>>n;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            adj_matrix[i][j]=0;
        }
    }

     for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int a;
            cin>>a;
            adj_matrix[i][j]=a;
        }
    }

    bool is_self_loop= false;
    for(int i=0;i<n;i++){
        if(adj_matrix[i][i]==1){
            is_self_loop=true;
            break;
        }
    }
    bool is_directed=false;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(adj_matrix[i][j]!= adj_matrix[j][i]){
                is_directed=true;
                break;
            }
        }
    }
    if(is_self_loop==true || is_directed==true){
        cout<<"NO"<<endl;
    }
    else{
        cout<<"YES"<<endl;
    }

    return 0;
}