#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Graph {
public:
    Graph(int numNodes) : numNodes_(numNodes) {
        adjacency_list_ = unordered_map<int, vector<int>>();
        for (int i = 1; i <= numNodes_; i++) {
            adjacency_list_[i] = vector<int>();
        }
    }

    void addEdge(int u, int v) {
        adjacency_list_[u].push_back(v);
    }

    bool isBidirectional() {
        for (int u = 1; u <= numNodes_; u++) {
            for (int v : adjacency_list_[u]) {
                if (adjacency_list_.count(v) == 0 || 
                    find(adjacency_list_[v].begin(), adjacency_list_[v].end(), u) == adjacency_list_[v].end()) {
                    return false;
                }
            }
        }
        return true;
    }

private:
    int numNodes_;
    unordered_map<int, vector<int>> adjacency_list_;
};

int main() {
    int n, m;
    cin >> n >> m;

    Graph graph(n);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        graph.addEdge(u, v);
    }

    bool isBidirectional = graph.isBidirectional();

    if (isBidirectional) {
        cout << "The graph is bidirectional." << endl;
    }
    else {
        cout << "The graph is not bidirectional." << endl;
    }

    return 0;
}
