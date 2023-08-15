#include<bits/stdc++.h>

using namespace std;
const int N=2e5;
vector<int> adj_list[N];
int visited[N];
stack<int>node_stack;

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
    node_stack.push(node);
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
        cout<<"IMPOSSIBLE"<<endl;
    }
    else{
        while(!node_stack.empty()){
            cout<<node_stack.top()<<" ";
            node_stack.pop();
        }
        cout<<endl;
    }

    return 0;
}