#include<bits/stdc++.h>

using namespace std;
const int N = 1e5;
vector<int>adj_list[N];
int visited[N];

bool detect_cycle_bfs(int node){
    queue<int>q;
    visited[node]=1;
    q.push(node);
    while(!q.empty()){
        int head = q.front();
        q.pop();

        for(int adj_node:adj_list[head]){
            /*
                if visited[adj_node]==0 ->"visited[adj_node]=1 and push to the queue"
                else if visited[adj_node]==1 ->"return true"
            */
           if(visited[adj_node]==0){
                visited[adj_node]=1;
                q.push(adj_node);
           }
           else if(visited[adj_node]==1){
                return true;
           }
        }
    }
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
    
    if(detect_cycle_bfs(1)){
        cout<<"Cycle exixts"<<endl;
    }
    else{
        cout<<"Cycle not exists"<<endl;
    }
    return 0;
}