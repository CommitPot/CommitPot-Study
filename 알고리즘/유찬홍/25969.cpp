#include <iostream>
#include <queue>

using namespace std;

typedef struct E {
    int x, y, t, b;
} E;

int n, m, k, map[201][201], vis[201][201][31][2];

bool check(int x, int y, int t, int b) {
    if (x < 0 || x >= n || y < 0 || y >= m) return true;
    if (map[x][y] == 1) return true;
    if (vis[x][y][t][b]) return true;
    return false;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int p[5][5], d[] = {0, 1, 0, -1, 0};
    queue<E> q;
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) cin >> map[i][j];
    vis[0][0][k][0] = 1;
    q.emplace(E{0, 0, k, 0});
    for (auto &i: p) for (int &j: i) cin >> j;
    while (!q.empty()) {
        E e = q.front();
        if (e.x == n - 1 && e.y == m - 1 && e.b) {
            cout << vis[e.x][e.y][e.t][1] - 1;
            return 0;
        }
        q.pop();
        int v = vis[e.x][e.y][e.t][e.b] + 1;
        for (int i = 0; i < 4; i++) {
            int dx = e.x + d[i], dy = e.y + d[i + 1];
            int b = map[dx][dy] == 2 ? 1 : e.b;
            if (check(dx, dy, e.t, b)) continue;
            vis[dx][dy][e.t][b] = v;
            q.emplace(E{dx, dy, e.t, b});
        }
        if (e.t) {
            for (int i = 0; i < 5; i++) {
                for (int j = 0; j < 5; j++) {
                    if (!p[i][j]) continue;
                    int dx = e.x + i - 2, dy = e.y + j - 2;
                    int b = map[dx][dy] == 2 ? 1 : e.b;
                    if (check(dx, dy, e.t - 1, b)) continue;
                    vis[dx][dy][e.t - 1][b] = v;
                    q.emplace(E{dx, dy, e.t - 1, b});
                }
            }
        }
    }
    cout << -1;
}
