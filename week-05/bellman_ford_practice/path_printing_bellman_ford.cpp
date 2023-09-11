#include<bits/stdc++.h>

using namespace std;
const int N = 1e5+5;
const int INF = 1e9;
int d[N],parent[N];
vector<pair<int,int>>adj_list[N];

int main()
{
    int n,m;
    cin>>n>>m;

    for(int i=0;i<=n;i++){
        d[i]=INF;
    }

    for(int i=1;i<=n;i++){
        int u,v,w;
        cin>>u>>v>>w;
        adj_list[u].push_back({v,w});
    }

    int src = 1;
    d[src] = 0;
    bool is_negetive_cycle = false;
    int last_updated_node;
    for(int i=1;i<=n;i++){
        for(int node=1;node<=n;node++){
            for(pair<int,int>adj_node:adj_list[node]){
                int u = node;
                int v = adj_node.first;
                int w = adj_node.second;
                if(d[u]+w<d[v]){
                    d[v] = d[u] + w;
                    parent[v]=u;
                    if(i=n){
                        is_negetive_cycle=true;
                        last_updated_node = v;
                    }
                }
            }
        }
    }

    if(is_negetive_cycle){
        cout<<"YES"<<endl;
        int selected_node = last_updated_node;
        for(int i=1;i<=n-1;i++){
            selected_node=parent[selected_node];
        }
        
        int first_node = selected_node;
        vector<int>cycle;
        cycle.push_back(first_node);
        while(true){
            selected_node=parent[selected_node];
            cycle.push_back(selected_node);
            if(first_node==selected_node){
                break;
            }
        }
        reverse(cycle.begin(),cycle.end());
        for(auto node:cycle){
            cout<<node<<" ";
        }
        cout<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }

    return 0;
}