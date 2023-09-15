#include <bits/stdc++.h>

using namespace std;

const int N = 100;
vector<int> adj_list[N];
int visited[N], parent[N];

void dfs(int u) {
    visited[u] = 1;
    for (int v : adj_list[u]) {
        if (!visited[v]) {
            parent[v] = u;
            dfs(v);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }
    dfs(1);

    for (int u = 1; u <= n; u++) {
        if (parent[u] != 0) {
            cout << u << " " << parent[u] << endl;
        }
    }

    return 0;
}
