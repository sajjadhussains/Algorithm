#include <bits/stdc++.h>

using namespace std;

const int N = 102;

vector<int> adj_list[N];
int visited[N], level[N];

void bfs(int src) {
    visited[src] = 1;
    level[src] = 1;
    queue<int> q;
    q.push(src);

    while (!q.empty()) {
        int head = q.front();
        q.pop();

        for (int adj_node : adj_list[head]) {
            if (visited[adj_node] == 0) {
                visited[adj_node] = 1;
                level[adj_node] = level[head] + 1;
                q.push(adj_node);
            }
        }
    }
}

int main() {
    for (int i = 2; i <= 101; i++) {
        for (int j = i * 2; j <= 101; j += i) {
            adj_list[i].push_back(j);
        }
    }

    for (int i = 2; i <= 101; i++) {
        bfs(i);
    }

    int longest_path = 0;
    for (int i = 2; i <= 101; i++) {
        longest_path = max(longest_path, level[i]);
    }

    cout << "Longest path: " << longest_path << endl;
    return 0;
}
