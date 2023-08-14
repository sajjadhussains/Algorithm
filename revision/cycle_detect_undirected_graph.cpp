#include<bits/stdc++.h>
using namespace std;

const int N = 1e5;
vector<int> adj_list[N];
int visited[N];

bool detect_cycle(int node, int parent) {
    visited[node] = 1;

    for (int adj_node : adj_list[node]) {
        if (visited[adj_node] == 0) {
            if (detect_cycle(adj_node, node)) {
                return true;
            }
        } else if (adj_node != parent) {
            return true;
        }
    }

    return false;
}

int main() {
    int nodes, edges;
    cin >> nodes >> edges;

    for (int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }

    if (detect_cycle(1, -1)) {
        cout << "Cycle exists in the undirected graph" << endl;
    } else {
        cout << "Cycle does not exist in the undirected graph" << endl;
    }
    return 0;
}
