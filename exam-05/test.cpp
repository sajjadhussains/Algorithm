#include <bits/stdc++.h>
using namespace std;

const int N = 40;
int tables[N][N];
int visited[N][N];
vector<vector<pair<int, int>>> parent;
int n;

int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};

bool isInside(pair<int, int> coord) {
    int x = coord.first;
    int y = coord.second;
    return (x >= 0 && x < n && y >= 0 && y < n);
}

bool is_safe(pair<int, int> coord) {
    int x = coord.first;
    int y = coord.second;
    if (tables[x][y] == 0) {
        return true; // Empty cell, can move here
    }
    return false;
}

bool bfs(pair<int, int> src) {
    queue<pair<int, int>> q;
    q.push(src);
    visited[src.first][src.second] = 1;

    while (!q.empty()) {
        pair<int, int> head = q.front();
        int x = head.first;
        int y = head.second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int new_x = dx[i] + x;
            int new_y = dy[i] + y;
            pair<int, int> adj_node = {new_x, new_y};

            if (isInside(adj_node) && visited[new_x][new_y] == 0 && is_safe(adj_node)) {
                visited[new_x][new_y] = 1;
                q.push(adj_node);
                parent[new_x][new_y] = {x, y};
                if (tables[new_x][new_y] == 2) {
                    return true;
                }
            }
        }
    }

    return false;
}

int main() {
    cin >> n;
    pair<int, int> src, dest;
    parent.resize(n, vector<pair<int, int>>(n, {-1, -1}));
    memset(visited, 0, sizeof(visited)); // Initialize visited array

    for (int i = 0; i < n; i++) {
        string input;
        cin >> input;
        for (int j = 0; j < n; j++) {
            if (input[j] == '@') {
                tables[i][j] = 1;
                src = {i, j};
            } else if (input[j] == 'X') {
                tables[i][j] = 2;
                dest = {i, j};
            } else if (input[j] == '.') {
                tables[i][j] = 0;
            } else {
                tables[i][j] = -1;
            }
        }
    }

    if (bfs(src)) {
        cout << "Y" << endl;
        pair<int, int> current = dest;
        while (current != src) {
            tables[current.first][current.second] = 3;
            current = parent[current.first][current.second];
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (tables[i][j] == 1)
                    cout << "@";
                else if (tables[i][j] == 0)
                    cout << ".";
                else if (tables[i][j] == -1)
                    cout << "0";
                else
                    cout << "+";
            }
            cout << endl;
        }
    } else {
        cout << "N" << endl;
    }

    return 0;
}
