// This is a follow up of problem 1. Trim all edges of the input graph where there is an edge from u -> v but not v -> u. Output the number of edges you have to remove. Use the same code to take input as problem 1.

#include <bits/stdc++.h>

using namespace std;

const int N = 1e5;
vector<int> adj_list[N];

void trimEdges(int numOfEdges)
{
    int countRemoveEdges = 0;

    for (int u = 0; u < numOfEdges; u++)
    {
        for (int v : adj_list[u])
        {
            bool edgeInReverseDirection = false;
            for (int w : adj_list[v])
            {
                if (w = u)
                {
                    edgeInReverseDirection = true;
                    break;
                }
            }
            if(!edgeInReverseDirection){
                adj_list[u].erase(find(adj_list[u].begin(),adj_list[u].end(),v));
                countRemoveEdges++;
            }
        }
    }
    cout<<"Number of edge remove: "<<countRemoveEdges<<endl;
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
        // adj_list[v].push_back(u);
    }
    
    trimEdges(m);
    return 0;
}