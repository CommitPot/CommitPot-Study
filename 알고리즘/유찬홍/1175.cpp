#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n, m, z = 48, rs = -1, vis[51][51][4][5] = {0}, d[] = {0, 1, 0, -1, 0};
    queue<tuple<int, int, int, int>> q;
    string map[51];
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> map[i];
        for (int j = 0; j < m; j++) {
            if (map[i][j] == 'S') {
                map[i][j] = '.';
                vis[i][j][0][4] = 1;
                q.emplace(i, j, 5, 0);
            }
            if (map[i][j] == 'C') map[i][j] = z++;
        }
    }
    while (!q.empty()) {
        auto [x, y, w, b] = q.front();
        if (b == 3) {
            rs = vis[x][y][3][w];
            break;
        }
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + d[i], ny = y + d[i + 1], bb = b;
            if (nx < 0 || nx >= n || ny < 0 || ny >= m || map[nx][ny] == '#') continue;
            if (w == i) continue;
            if (map[nx][ny] == '.' && !vis[nx][ny][b][i]) {
                vis[nx][ny][b][i] = vis[x][y][b][w] + 1;
                q.emplace(nx, ny, i, b);
            }
            bb = b | (1 << 0);
            if (map[nx][ny] == 48 && !vis[nx][ny][bb][i]) {
                vis[nx][ny][bb][i] = vis[x][y][b][w] + 1;
                q.emplace(nx, ny, i, bb);
            }
            bb = b | (1 << 1);
            if (map[nx][ny] == 49 && !vis[nx][ny][bb][i]) {
                vis[nx][ny][bb][i] = vis[x][y][b][w] + 1;
                q.emplace(nx, ny, i, bb);
            }
        }
    }
    cout << rs;
}
