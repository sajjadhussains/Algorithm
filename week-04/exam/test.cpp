#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

const int dx[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
const int dy[] = { -1, 0, 1, -1, 1, -1, 0, 1 };

int H, W;
vector<vector<char>> grid;
int memo[55][55];

bool isValid(int x, int y) {
    return (x >= 0 && x < H && y >= 0 && y < W);
}

int dfs(int x, int y) {
    if (memo[x][y] != -1) {
        return memo[x][y];
    }

    int max_length = 0;

    for (int i = 0; i < 8; i++) {
        int new_x = x + dx[i];
        int new_y = y + dy[i];

        if (isValid(new_x, new_y) && grid[new_x][new_y] == grid[x][y] + 1) {
            int length = 1 + dfs(new_x, new_y);
            max_length = max(max_length, length);
        }
    }

    return memo[x][y] = max_length;
}

int findLongestPath() {
    int max_length = 0;

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (grid[i][j] == 'A') {
                int length = 1 + dfs(i, j);
                max_length = max(max_length, length);
            }
        }
    }

    return max_length;
}

int main() {
    int case_num = 1;

    while (cin >> H >> W) {
        if (H == 0 && W == 0) {
            break;
        }

        grid.assign(H, vector<char>(W));
        memset(memo, -1, sizeof(memo));

        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                cin >> grid[i][j];
            }
        }

        int result = findLongestPath();

        cout << "Case " << case_num << ": " << result << endl;
        case_num++;
    }

    return 0;
}
