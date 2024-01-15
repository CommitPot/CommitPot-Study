#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

string map[1001];
int n, m, k, rs = -1, vis[1001][1001][11][2], d[] = {0, 1, 0, -1, 0};

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    queue<tuple<int, int, int, int>> q;
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) cin >> map[i];
    vis[0][0][k][0] = 1;
    q.emplace(0, 0, k, 0);
    while (!q.empty()) {
        auto [x, y, v, w] = q.front();
        if (x == n - 1 && y == m - 1) {
            rs = vis[x][y][v][w];
            break;
        }
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + d[i], ny = y + d[i + 1];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (map[nx][ny] == 49) {
                if (!w && v && !vis[nx][ny][v - 1][1]) {
                    vis[nx][ny][v - 1][1] = vis[x][y][v][0] + 1;
                    q.emplace(nx, ny, v - 1, 1);
                }
                if (w && !vis[x][y][v][0]) {
                    vis[x][y][v][0] = vis[x][y][v][1] + 1;
                    q.emplace(x, y, v, 0);
                }
            } else {
                if (!vis[nx][ny][v][!w]) {
                    vis[nx][ny][v][!w] = vis[x][y][v][w] + 1;
                    q.emplace(nx, ny, v, !w);
                }
            }
        }
    }
    cout << rs;
}
