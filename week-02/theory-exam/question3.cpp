#include <bits/stdc++.h>

using namespace std;
const int N = 1e5;
vector<int> adj_list[N];
int visited[N];

void dfs(int src)
{
    visited[src] = 1;
    for (int adj_node : adj_list[src])
    {
        if (visited[adj_node == 0])
        {
            dfs(adj_node);
        }
    }
}

int componentCounts(int numOfEdges)
{
    int numOfConnectedComponents = 0;
    for (int i = 0; i < numOfEdges; i++)
    {
        if (visited[i] == 0)
        {
            numOfConnectedComponents++;
            dfs(i);
        }
    }
    cout<<numOfConnectedComponents<<endl;
    return numOfConnectedComponents;
}

int main()
{
    // n = number of nodes
    // m = number of edges
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    { // loop over the number of edges
        int u, v;
        cin >> u >> v; // There exists a directed edge from u to v
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }
    int result=componentCounts(m);
    cout<<"Connected Components : "<<result<<endl;

    return 0;
}