//bfs algorithm

#include<bits/stdc++.h>
using namespace std;

const int N=1e5;

int visited[N];
vector<int>adj_list[N];

void bfs(int src){
    queue<int>q;
    q.push(src);
    visited[src]=1;

    while(!q.empty()){
        int u=q.front();
        q.pop();
        // int previous_adj_node=u;
        cout<<u<<" ";

        for(int adj_node:adj_list[u]){
            if(visited[adj_node]==0){
                visited[adj_node]=1;
                q.push(adj_node);
            }
        }
    }
}


int main()
{
    int node,edges;
    cin>>node>>edges;

    for(int i=0;i<edges;i++)
    {
        int u,v;
        cin>>u>>v;

        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }
    int src=5;
    bfs(src);
    
    return 0;
}

/*
    0-----1-----2-----3
          |     |
          |     |
          5-----4

#no of nodes -> 6
#no of edges -> 6
list of adj nodes->
0 1
1 2
2 3
1 5
2 4
5 4
output will be:0 1 2 5
*/
