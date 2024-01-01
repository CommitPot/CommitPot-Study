#include <iostream>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n, idx = 1, map[126][126], vis[126][126], d[] = {0, 1, 0, -1, 0};
    priority_queue<pair<int, pair<int, int>>> q;
    while (cin >> n) {
        if (!n) break;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> map[i][j];
                vis[i][j] = 1e8;
            }
        }
        q.emplace(-map[0][0], make_pair(0, 0));
        vis[0][0] = map[0][0];
        while (!q.empty()) {
            int w = -q.top().first;
            auto [x, y] = q.top().second;
            q.pop();
            if (vis[x][y] >= w) {
                for (int i = 0; i < 4; i++) {
                    int dx = x + d[i], dy = y + d[i + 1];
                    if (dx < 0 || dy < 0 || dx >= n || dy >= n) continue;
                    if (w + map[dx][dy] < vis[dx][dy]) {
                        vis[dx][dy] = map[dx][dy] + w;
                        q.emplace(-vis[dx][dy], make_pair(dx, dy));
                    }
                }
            }
        }
        cout << "Problem " << idx++ << ": " << vis[n - 1][n - 1] << "\n";
    }
}
