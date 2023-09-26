#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

typedef pair<int, int> pii;

const int MAX_N = 101;
const int MAX_T = 10001;

vector<pii> adj[MAX_N];
int dist[MAX_N];

int shortestTime(int n, int d, int v, int r, vector<vector<int>>& routes) {
    for (int i = 1; i <= n; ++i) {
        dist[i] = INT_MAX;
    }

    dist[d] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, d});

    while (!pq.empty()) {
        int u = pq.top().second;
        int curDist = pq.top().first;
        pq.pop();

        if (u == v) {
            return curDist;
        }

        for (auto& route : routes) {
            int start = route[0];
            int departure = route[1];
            int dest = route[2];
            int arrival = route[3];

            if (start == u && departure > curDist) {
                int waitTime = max(curDist, arrival) - departure;
                int newDist = curDist + waitTime;

                if (newDist < dist[dest]) {
                    dist[dest] = newDist;
                    pq.push({newDist, dest});
                }
            }
        }
    }

    return -1;
}

int main() {
    int n, d, v, r;
    cin >> n >> d >> v >> r;

    vector<vector<int>> routes(r, vector<int>(4));
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < 4; ++j) {
            cin >> routes[i][j];
        }
    }

    int result = shortestTime(n, d, v, r, routes);

    cout << result << endl;

    return 0;
}
