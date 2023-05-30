#include <bits/stdc++.h>

using namespace std;

struct Graph {
  int V;
  vector<vector<int>> adj;

  Graph(int V) {
    this->V = V;
    adj.resize(V);
  }

  void addEdge(int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  void connectedComponents() {
    vector<bool> visited(V, false);
    int numComponents = 0;

    for (int u = 0; u < V; u++) {
      if (!visited[u]) {
        numComponents++;
        dfs(u, visited);
      }
    }

    cout << "Number of connected components: " << numComponents << endl;
  }

private:
  void dfs(int u, vector<bool>& visited) {
    visited[u] = true;

    for (int v : adj[u]) {
      if (!visited[v]) {
        dfs(v, visited);
      }
    }
  }
};

int main() {
  int V;
  cin >> V;

  Graph g(V);

  for (int i = 0; i < V; i++) {
    int u, v;
    cin >> u >> v;
    g.addEdge(u, v);
  }

  g.connectedComponents();

  return 0;
}
