#include<bits/stdc++.h>

using namespace std;
const int N = 1005; // Updated to a value that safely fits the constraints

int maze[N][N], visited[N][N];
int n, m;

int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};

bool isInside(pair<int, int> coord) {
    int x = coord.first;
    int y = coord.second;

    if (x >= 0 && x < n && y >= 0 && y < m) {
        return true;
    }
    return false;
}

bool isSafe(pair<int, int> coord) {
    int x = coord.first;
    int y = coord.second;

    if (maze[x][y] == -1) {
        return false;
    }
    return true;
}

void bfs(pair<int, int> src, int roomNumber) {
    queue<pair<int, int>> q;
    visited[src.first][src.second] = roomNumber;

    q.push(src);

    while (!q.empty()) {
        pair<int, int> head = q.front();
        q.pop();

        int x = head.first;
        int y = head.second;

        for (int i = 0; i < 4; i++) {
            int new_x = dx[i] + x;
            int new_y = dy[i] + y;

            pair<int, int> adj_node = {new_x, new_y};

            if (isInside(adj_node) && isSafe(adj_node) && visited[new_x][new_y] == 0) {
                visited[new_x][new_y] = roomNumber;
                q.push(adj_node);
            }
        }
    }
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        string input;
        cin >> input;

        for (int j = 0; j < m; j++) {
            if (input[j] == '#') {
                maze[i][j] = -1;
            } else if (input[j] == '.') {
                maze[i][j] = 0;
            }
        }
    }

    int room_count = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (maze[i][j] == 0 && visited[i][j] == 0) {
                room_count++;
                bfs({i, j}, room_count);
            }
        }
    }
    cout << room_count << endl;
    return 0;
}
