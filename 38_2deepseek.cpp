#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int n, k, x0, y0;

// 马步的八个方向
int dx[8] = {1, 1, 2, 2, -1, -1, -2, -2};
int dy[8] = {2, -2, 1, -1, 2, -2, 1, -1};

int main() {
    cin >> n >> k >> x0 >> y0;
    // 转换为 0‑based 坐标
    x0--; y0--;

    // visited[i][j] = 到达 (i,j) 所需的最少步数，-1 表示未访问
    vector<vector<int>> visited(n, vector<int>(n, -1));
    queue<pair<int, int>> q;

    visited[x0][y0] = 0;
    q.push({x0, y0});

    while (!q.empty()) {
        auto [x, y] = q.front(); q.pop();
        int steps = visited[x][y];
        if (steps == k) continue; // 已经达到最大步数，不再扩展

        for (int i = 0; i < 8; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && nx < n && ny >= 0 && ny < n && visited[nx][ny] == -1) {
                visited[nx][ny] = steps + 1;
                q.push({nx, ny});
            }
        }
    }

    // 统计所有被访问过的格子（步数 ≤ k）
    int ans = 0;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            if (visited[i][j] != -1) ans++;

    cout << ans << endl;
    return 0;
}