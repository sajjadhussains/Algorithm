#include<bits/stdc++.h>

using namespace std;
const int N = 1e5+5;
vector<int> adj_list[N];

void dfs(int src, vector<int>& ancestors, vector<vector<int>>& parent) {
    for (int ancestor : ancestors) {
        parent[src].push_back(ancestor);
    }

    ancestors.push_back(src);

    for (int adj_node : adj_list[src]) {
        dfs(adj_node, ancestors, parent);
    }

    ancestors.pop_back();
}

int main() {
    int n, src;
    cin >> n;
    vector<vector<int>> parent(n+1); // Adjust size to n+1

    for (int i = 1; i <= n; i++) {
        int u;
        cin >> u;
        if (u == 0) src = i;
        adj_list[u].push_back(i);
    }

    vector<int> ancestors;
    dfs(src, ancestors, parent);

    int m;
    cin >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        bool is_parent = false;

        for (int node : parent[v]) {
            if (node == u) {
                is_parent = true;
                break; // Break early if parent is found
            }
        }

        cout << is_parent << endl; // Output 1 or 0 directly
    }

    return 0;
}