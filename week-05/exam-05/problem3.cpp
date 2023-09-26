//problem_link:https://www.eolymp.com/en/problems/2472

#include <bits/stdc++.h>
using namespace std;

const int N =1e5;
vector<int>adj_list[N];

int main() {
    int n,k;
    cin >>n>>k;

    for(int i=0;i<k;i++){
        int operation_sign;
        cin>>operation_sign;
        if(operation_sign==1){
            int u,v;
            cin>>u>>v;
            adj_list[u].push_back(v);
            adj_list[v].push_back(u);

        }
        else if(operation_sign==2){
            int node;
            cin>>node;
            for(int adj_node:adj_list[node]){
                cout<<adj_node<<" ";
            }
            cout<<endl;
        }
    }

    return 0;
}
