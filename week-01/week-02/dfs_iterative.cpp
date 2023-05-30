// dfs implementation using stack

#include <bits/stdc++.h>

using namespace std;
const int N = 1e5;
vector<int> adj_list[N];

int visited[N];

void dfs_iterative(int src)
{
    stack<int> s;
    s.push(src);
    while (!s.empty())
    {
        int t = s.top();
        s.pop();
        if(visited[t]!=1){
            cout<<t<<" ";
            visited[t]=1;
        }
        for (int adj_node : adj_list[t])
        {
            if(visited[adj_node]!=1){
                s.push(adj_node);
            }
        }
    }
}

int main()
{
    int nodes, edges;
    cin >> nodes >> edges;

    for (int i = 0; i < edges; i++)
    {
        int u, v;
        cin >> u >> v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }

    int src = 0;
    dfs_iterative(src);
    return 0;
}