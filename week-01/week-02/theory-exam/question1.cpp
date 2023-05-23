#include<bits/stdc++.h>

using namespace std;
const int N=1e5;

int visited[N];

vector<int>adj_list[N];

bool check_undirected(int src){
    queue<int>q;
    visited[src]=1;
    q.push(src);
    
    while(!q.empty()){
        int head=q.front();
        q.pop();
        //cout<<head<<endl;
        for(int adj_node:adj_list[head]){
            if (adj_node==head){
                return true;
            }
            else{
                if (visited[adj_node]==0){
                    visited[adj_node]=1;
                    q.push(adj_node);
                }
            }
            cout<<adj_node<<" "<<head<<endl;
        }
    }
    return false;
}
int main()
{
     // n = number of nodes
    // m = number of edges
    int n, m;
    cin >> n >> m;
 
    for(int i = 0 ; i < m ; i++) { // loop over the number of edges
        int u, v;
        cin >> u >> v; // There exists a directed edge from u to v
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }
    int src=0;
    bool result=check_undirected(src);
    cout<<result<<endl;
    if (result){
        cout<<"Undirected Graph"<<endl;
    }
    else{
        cout<<"Directed Graph"<<endl;
    }
    return 0;
}