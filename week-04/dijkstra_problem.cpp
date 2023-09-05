#include <bits/stdc++.h>

using namespace std;
const int N = 1e5+5;
const long long INF = 1e18;
int nodes, edges;

vector<pair<int,int>> adj_list[N];
int visited[N], parent[N];
long long d[N];

void dijkstra(int src) {
    for (int i = 1; i <= nodes; i++) {
        d[i] = INF;
    }
    d[src] = 0;
    priority_queue<pair<long long, int>> pq;
    pq.push({0, src});

    while (!pq.empty()) {
        pair<long long, int> head = pq.top();
        pq.pop();
        int selected_node = head.second;

        if (visited[selected_node] == 1) {
            continue;
        }
        visited[selected_node] = 1;

        for (auto adj_entry : adj_list[selected_node]) {
            int adj_node = adj_entry.first;
            int edge_cost = adj_entry.second;

            if (d[selected_node] + edge_cost < d[adj_node]) {
                d[adj_node] = d[selected_node] + edge_cost;
                parent[adj_node] = selected_node;
                pq.push({-d[adj_node], adj_node});
            }
        }
    }
}

int main() {
    cin >> nodes >> edges;
    for (int i = 0; i < edges; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj_list[u].push_back({v, w});
        adj_list[v].push_back({u, w});
    }

    dijkstra(1);

    // If there is no path to vertex n, print -1
    if (d[nodes] == INF) {
        cout << -1 << endl;
        return 0;
    }

    // Reconstruct the shortest path
    int current_node = nodes;
    vector<int> path;

    while (current_node != 0) {
        path.push_back(current_node);
        current_node = parent[current_node];
    }
    
    reverse(path.begin(), path.end());

    // Print the shortest path
    for (auto node : path) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}
