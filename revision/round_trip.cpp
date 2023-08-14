#include <iostream>
#include <vector>
#include <queue>
#include <algorithm> // Include this header for 'reverse' function

using namespace std;

bool hasCycle(const vector<vector<int>>& graph, int start) {
    vector<int> parent(graph.size(), -1);
    vector<bool> visited(graph.size(), false);
    queue<int> q;

    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        for (int neighbor : graph[current]) {
            if (!visited[neighbor]) {
                q.push(neighbor);
                visited[neighbor] = true;
                parent[neighbor] = current;
            } else if (parent[current] != neighbor) {
                // Found a cycle
                vector<int> cycle;
                int node = current;
                while (node != -1) {
                    cycle.push_back(node);
                    node = parent[node];
                }
                cycle.push_back(neighbor);
                reverse(cycle.begin(), cycle.end());
                
                // Print the cycle
                cout << "Cycle detected: ";
                for (int c : cycle) {
                    cout << c << " ";
                }
                cout << endl;

                return true;
            }
        }
    }

    return false;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n + 1);

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    bool cycleDetected = false;
    for (int i = 1; i <= n; ++i) {
        if (!cycleDetected) {
            cycleDetected = hasCycle(graph, i);
        }
    }

    if (!cycleDetected) {
        cout << "No cycle detected in the graph." << endl;
    }

    return 0;
}
