//problem_link:https://www.eolymp.com/en/problems/4369

#include<bits/stdc++.h>

using namespace std;
const int N=1e5+5;
vector<int>adj_list[N];
int visited[N],dist[N];

int main()
{
    int n,m;
    cin>>n>>m;

    for(int i=1;i<=m;i++){
        int u,v;
        cin>>u>>v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }
    queue<int>q;
    int k;
    cin>>k;
    for(int i=0;i<k;i++){
        int x;
        cin>>x;
        q.push(x);
        dist[x]=0;
        visited[x]=1;
    }
    
    while(!q.empty()){
        int head = q.front();
        q.pop();
        for(int adj_node:adj_list[head]){
            if(visited[adj_node]==0){
                q.push(adj_node);
                dist[adj_node]=dist[head]+1;
                visited[adj_node]=1;
            }
        }
    }

    int last_node_dist=0;
    vector<int>last_nodes;

    for(int i=1;i<=n;i++){
        if(last_node_dist<dist[i]){
            last_node_dist=dist[i];
            last_nodes.clear();
            last_nodes.push_back(i);
        }
        else if(last_node_dist==dist[i]){
            last_nodes.push_back(i);
        }
    }

    int last_node=*min_element(last_nodes.begin(),last_nodes.end());

    

    cout<<last_node_dist<<endl;
    cout<<last_node<<endl;

    return 0;
}