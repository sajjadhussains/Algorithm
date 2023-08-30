#include<bits/stdc++.h>

using namespace std;

const int N=1e5+5;
vector<int>adj_list[N];
int visited[N],parent[N];

void dfs(int src)
{
    visited[src]=1;

    for(int adj_node:adj_list[src]){
        if(visited[adj_node]==0){
            parent[adj_node]=src;
            dfs(adj_node);
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
        adj_list[v].push_back(u);
    }

    int src_node = 1;
    parent[src_node]=-1;
    dfs(src_node);
    int destination_node = nodes;
    if(visited[destination_node]==0){
        cout<<"IMPOSSIBLE"<<endl;
        return 0;
    }

    vector<int>path;
    int selected_node = destination_node;
    
    while(true){
        path.push_back(selected_node);
        if(src_node==selected_node){
            break;
        }
        selected_node=parent[selected_node];
    }

    reverse(path.begin(),path.end());
    cout<<path.size()<<endl;
    for(int node:path){
        cout<<node<<" ";
    }
    cout<<endl;
    return 0;
}