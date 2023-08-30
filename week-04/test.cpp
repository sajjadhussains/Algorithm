#include<bits/stdc++.h>
 
using namespace std;
const int N=1e5+5;
vector<int>adj_list[N];
int visited[N],level[N],parent[N];
bool found = false;
 
void dfs(int node, int parent_node) {
    visited[node] = 1;
    parent[node] = parent_node;
 
    for(int adj_node : adj_list[node]) {
        if(!visited[adj_node]) {
            level[adj_node] = level[node] + 1;
            dfs(adj_node, node);
            if(found) return;
        } else if(adj_node != parent_node) {
            // We found a cycle, which indicates a path from source to destination
            found = true;
            vector<int> path;
            path.push_back(adj_node);
            int curr = node;
            while(curr != adj_node) {
                path.push_back(curr);
                curr = parent[curr];
            }
            path.push_back(adj_node);
 
            cout << level[dst_node] << endl;
            reverse(path.begin(), path.end());
            for(int p : path) {
                cout << p << " ";
            }
            cout << endl;
 
            return;
        }
    }
}
 
int main() {
    int n, m;
    cin >> n >> m;
 
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }
    
    int src_node = 1, dst_node = n;
    level[src_node] = 1;
    dfs(src_node, -1);
    
    if(!found) {
        cout << "IMPOSSIBLE" << endl;
    }
    
    return 0;
}
