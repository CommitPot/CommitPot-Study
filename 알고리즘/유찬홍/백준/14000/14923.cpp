#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n, m, s1, s2, e1, e2, rs = -1, d[] = {0, 1, 0, -1, 0}, map[1001][1001], vis[1001][1001][2] = {0};
    queue<pair<pair<int, int>, int>> q;
    cin >> n >> m >> s1 >> s2 >> e1 >> e2;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> map[i][j];
        }
    }
    q.push({{s1, s2}, 0});
    vis[s1][s2][0] = 1;
    while (!q.empty()) {
        auto [x, v] = q.front();
        if (x.first == e1 && x.second == e2) {
            rs = vis[x.first][x.second][v] - 1;
            break;
        }
        q.pop();
        for (int i = 0; i < 4; i++) {
            int dx = x.first + d[i], dy = x.second + d[i + 1];
            if (dx < 1 || dx > n || dy < 1 || dy > m || vis[dx][dy][v]) continue;
            if (!map[dx][dy]) {
                q.push({{dx, dy}, v});
                vis[dx][dy][v] = vis[x.first][x.second][v] + 1;
            }
            if (map[dx][dy] && !v) {
                q.push({{dx, dy}, 1});
                vis[dx][dy][1] = vis[x.first][x.second][0] + 1;
            }
        }
    }
    cout << rs;
}
