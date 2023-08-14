#include<bits/stdc++.h>

using namespace std;
const int N=1e5;
vector<int> adj_list[N];
int visited[N];

bool detect_cycle(int node){

    visited[node]=1;

    for(int adj_node:adj_list[node]){
        /* if visited[adj_node]==0 "unexplored node" | apply dfs
           if visited[adj_node]==1 "paused node" | cycle detected
           if visited[adj_node]==2 "done node" | continue
        */
       if(visited[adj_node]==0){
            bool got_cycle = detect_cycle(adj_node);
            if(got_cycle){
                return true;
            }
       }
       else if(visited[adj_node]==1){
        return true;
       }
    }
    visited[node]=2;
    return false;
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
    bool cycle_exists= false;
    for(int i=1;i<=nodes;i++){
        if(visited[i]==0){
            bool got_cycle = detect_cycle(i);
            if(got_cycle){
                cycle_exists=true;
                break;
            }
        }
    }

    if(cycle_exists){
        cout<<"cycle exits in the graph"<<endl;
    }
    else{
        cout<<"Cycle not found in the graph"<<endl;
    }

    return 0;
}