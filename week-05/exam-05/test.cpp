#include <bits/stdc++.h>

using namespace std;
const int N = 1e5 + 10;
const long long INF = 1e9; // Changed to a larger value for infinity
long long d[N];
int parent[N];
vector<pair<int, int>> adj_list[N];

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int w;
            cin >> w;
            if (w == -1) { // Handle missing connections
                continue;
            }
            adj_list[i].push_back({j, w}); // Use 0-based indexing
        }
    }
    for (int i = 0; i < n; i++) {
        d[i] = INF;
    }
    for (int i = 0; i < n; i++) {
        parent[i] = -1;
    }
    int src = 0; // Use 0-based indexing for the source node
    d[src] = 0;

    for (int i = 1; i <= n - 1; i++) { // Iterate n-1 times
        for (int node = 0; node < n; node++) {
            for (pair<int, int> adj_node : adj_list[node]) {
                int u = node;
                int v = adj_node.first;
                int w = adj_node.second;
                if (d[u] + w < d[v]) {
                    d[v] = d[u] + w;
                    parent[v] = u;
                }
            }
        }
    }

    bool is_negative_cycle = false;

    // Check for negative cycles
    for (int node = 0; node < n; node++) {
        for (pair<int, int> adj_node : adj_list[node]) {
            int u = node;
            int v = adj_node.first;
            int w = adj_node.second;
            if (d[u] + w < d[v]) {
                is_negative_cycle = true;
                break;
            }
        }
        if (is_negative_cycle) {
            break;
        }
    }

    if (is_negative_cycle) {
        cout << "YES" << endl;
        int selected_node = parent[src];
        vector<int> cycle;
        cycle.push_back(src);
        while (selected_node != src) {
            cycle.push_back(selected_node);
            selected_node = parent[selected_node];
        }
        cycle.push_back(src);

        int length = cycle.size();
        cout << length << endl;
        for (int i = length - 1; i >= 0; i--) {
            cout << cycle[i] + 1 << " "; // Adjust for 1-based indexing
        }
        cout << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}
