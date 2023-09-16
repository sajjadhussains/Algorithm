#include<bits/stdc++.h>

using namespace std;
const int N=100;
const int INF = 1e5;
vector<pair<int,int>>adj_list[N];
int d[N],visited[N];
int cost[N];
int n,m;
void dijkstra(int src){
    for(int i=0;i<=n;i++){
        d[i]=INF;
    }
    d[src]=0;
    priority_queue<pair<int,int>>pq;
    pq.push({0,src});

    while(!pq.empty()){
        pair<int,int>head=pq.top();
        pq.pop();

        int selected_node = head.second;

        if(visited[selected_node]==1){
            continue;
        }
        visited[selected_node]=1;

        for(pair<int,int>adj_entry:adj_list[selected_node]){
            int adj_node = adj_entry.first;
            int edge_cost = adj_entry.second;

            if(d[selected_node]+edge_cost<d[adj_node]){
                d[adj_node]=d[selected_node]+edge_cost;
                pq.push({-d[adj_node],adj_node});
            }

        }
    }
}
int main(){
    cin>>n;

    for(int i=0;i<n;i++){
        cin>>cost[i];
    }
    cin>>m;
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        int cost_u_v=cost[u-1];
        int cost_v_u=cost[v-1];
        adj_list[u].push_back({v,cost_u_v});
        adj_list[v].push_back({u,cost_v_u});
    }
    int src=1;
    dijkstra(src);
    if(d[n]<INF){
        cout<<d[n]<<endl;
    }
    else{
        cout<<-1<<endl;
    }

    return 0;
}