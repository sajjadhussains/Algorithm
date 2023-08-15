#include <bits/stdc++.h>

using namespace std;
const int N = 1e5;
vector<int> adj_list[N];
int visited[N];

bool cycle_detect_bfs(int node)
{

    queue<int> q;
    visited[node] = 0;
    q.push(node);

    while (!q.empty())
    {
        int head = q.front();
        q.pop();
        visited[head] = 1;

        for (int adj_node : adj_list[head])
        {
            if (visited[adj_node] == -1)
            {
                visited[adj_node] = 0;
                q.push(adj_node);
            }
            else if (visited[adj_node] == 0 && adj_node != head)
            {
                visited[adj_node] = 1;
                return true;
            }
        }
    }
    return false;
}

bool visit_all(){
    for(int i=1;i<=N;i++){
        if(cycle_detect_bfs(i)){
            return true;
        }
        else{
            return false;
        }
    }
}

int main()
{
    int nodes, edges;
    cin >> nodes >> edges;
    for (int i = 0; i < N; i++)
    {
        visited[i] = -1;
    }

    for (int i = 0; i < edges; i++)
    {
        int u, v;
        cin >> u >> v;

        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }
    vector<int>round_trip;
    
    if (visit_all())
    {
        for(int i=1;i<=N;i++){
            if(visited[i]==1){
                round_trip.push_back(i);
            }
        }
        round_trip.push_back(round_trip[0]);
        cout<<round_trip.size()<<endl;
        for(int i=0;i<round_trip.size();i++){
            cout<<round_trip[i]<<" ";
        }
        cout<<endl;
    }
    else
    {
        cout <<"IMPOSSIBLE"<< endl;
    }

    return 0;
}