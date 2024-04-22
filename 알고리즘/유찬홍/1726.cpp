#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    bool p[101][101];
    int m, n, a, b, c, vis[101][101][5] = {}, d[][2] = {{},
                                                        {0,  1},
                                                        {0,  -1},
                                                        {1,  0},
                                                        {-1, 0}};
    char f[5][3] = {"", "34", "34", "12", "12"};
    cin >> m >> n;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> p[i][j];
        }
    }
    memset(vis, 1e9, sizeof(vis));
    queue<tuple<int, int, int>> q;
    cin >> a >> b >> c;
    vis[a][b][c] = 1e9 - 1;
    q.emplace(a, b, c);
    cin >> a >> b >> c;
    while (!q.empty()) {
        auto [x, y, w] = q.front();
        q.pop();
        if (x == a && y == b && w == c) {
            cout << 1e9 - vis[a][b][c] - 1;
            break;
        }
        for (int i = 1; i <= 3; i++) {
            int nx = x + d[w][0] * i, ny = y + d[w][1] * i;
            if (nx <= 0 || nx > m || ny <= 0 || ny > n || p[nx][ny] || vis[nx][ny][w] > vis[x][y][w] - 1) break;
            vis[nx][ny][w] = vis[x][y][w] - 1;
            q.emplace(nx, ny, w);
        }
        for (int i = 0; i < 2; i++) {
            if (vis[x][y][f[w][i] - 48]) continue;
            vis[x][y][f[w][i] - 48] = vis[x][y][w] - 1;
            q.emplace(x, y, f[w][i] - 48);
        }
    }
}
