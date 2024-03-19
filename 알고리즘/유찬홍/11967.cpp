#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n, m, x, y, a, b, cnt = 0, d[] = {0, 1, 0, -1, 0};
    bool s[101][101] = {}, map[101][101] = {}, vis[101][101] = {};
    cin >> n >> m;
    vector<pair<int, int>> l[101][101];
    queue<pair<int, int>> q;
    while (m--) {
        cin >> x >> y >> a >> b;
        l[x][y].emplace_back(a, b);
    }
    s[1][1] = map[1][1] = vis[1][1] = true;
    q.emplace(1, 1);
    while (!q.empty()) {
        auto [h, w] = q.front();
        q.pop();
        for (auto [i, j]: l[h][w]) {
            s[i][j] = true;
            if (map[i][j] && !vis[i][j]) {
                vis[i][j] = true;
                q.emplace(i, j);
            }
        }
        for (int i = 0; i < 4; i++) {
            int nx = h + d[i], ny = w + d[i + 1];
            if (nx >= 1 && nx <= n && ny >= 1 && ny <= n) {
                map[nx][ny] = true;
                if (!vis[nx][ny] && s[nx][ny]) {
                    vis[nx][ny] = true;
                    q.emplace(nx, ny);
                }
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (s[i][j]) cnt++;
        }
    }
    cout << cnt;
}
