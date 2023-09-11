#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

const int MAXN = 505;
const int MAXM = 16005;

struct Edge {
    int to, cost;
};

vector<Edge> graph[MAXN];
int dist[MAXN];
int maxCost[MAXN];

void dijkstra(int start, int n) {
    for (int i = 0; i < n; ++i) {
        dist[i] = INT_MAX;
        maxCost[i] = 0;
    }

    priority_queue<pair<int, int>> pq;
    pq.push({0, start});
    dist[start] = 0;

    while (!pq.empty()) {
        int u = pq.top().second;
        int cost = -pq.top().first;
        pq.pop();

        if (cost > dist[u]) continue;

        for (const Edge& edge : graph[u]) {
            int v = edge.to;
            int w = edge.cost;

            if (max(dist[u], w) < dist[v]) {
                dist[v] = max(dist[u], w);
                maxCost[v] = max(maxCost[u], w);
                pq.push({-dist[v], v});
            }
        }
    }
}

int main() {
    int T;
    cin >> T;

    for (int caseNum = 1; caseNum <= T; ++caseNum) {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; ++i) {
            graph[i].clear();
        }

        for (int i = 0; i < m; ++i) {
            int u, v, w;
            cin >> u >> v >> w;
            graph[u].push_back({v, w});
            graph[v].push_back({u, w});
        }

        int t;
        cin >> t;

        dijkstra(t, n);

        cout << "Case " << caseNum << ":" << endl;
        for (int i = 0; i < n; ++i) {
            if (i == t) {
                cout << "0" << endl;
            } else if (dist[i] == INT_MAX) {
                cout << "Impossible" << endl;
            } else {
                cout << maxCost[i] << endl;
            }
        }
    }

    return 0;
}
