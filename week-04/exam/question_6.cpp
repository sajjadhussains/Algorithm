#include<bits/stdc++.h>

using namespace std;
const int N = 1e5 + 5;
vector<int> adj_list[N];
int visited[N], cat_nodes[N];
int ans = 0;

void dfs(int src, int num_c, int max_nodes, int max_c) {
    visited[src] = 1;
    if (cat_nodes[src]) {
        num_c++;
    }
    else {
        num_c = 0;
    }
    max_c = max(max_c, num_c);

    int numChild = 0;
    for (int adj_node : adj_list[src]) {
        if (!visited[adj_node]) {
            dfs(adj_node, num_c, max_nodes, max_c);
            numChild++;
        }
    }

    if (numChild == 0 && max_c <= max_nodes) {
        ans++;
    }
}

int main() {
    int nodes, max_nodes;
    cin >> nodes >> max_nodes;

    for (int i = 1; i <= nodes; i++) {
        cin >> cat_nodes[i];
    }
    for (int i = 0; i < nodes - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }
    dfs(1, 0, max_nodes, 0);
    cout << ans << endl;

    return 0;
}
