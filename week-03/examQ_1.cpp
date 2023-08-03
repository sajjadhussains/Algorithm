
#include<bits/stdc++.h>

using namespace std;
const int N=2e5;
vector<int>adj_list[N];
int visited[N];
int level[N];

void dfs(int node,int lvl){
    visited[node]=1;
    level[node]=lvl;

    for(int adj_node:adj_list[node]){
        if(visited[adj_node]==0){
            dfs(adj_node,lvl+1);
        }
    }
}
int main()
{
    int nodes,edges;
    cin>>nodes>>edges;

    for(int i=0;i<edges;i++){
        int u,v;
        cin>>u>>v;
        adj_list[u].push_back(v);
    }
    dfs(0,0);

    for(int i=0;i<nodes;i++){
        cout<<"node->"<<i<<":"<<"level->"<<level[i]<<endl;
    }
    return 0;
}

/*
5 5
0 1
0 2
0 4
2 3
4 3
*/