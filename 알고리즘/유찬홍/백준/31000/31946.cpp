#include <queue>
#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n, m, k, a[101][101];
    bool vis[101][101] = {};
    queue<pair<int, int>> q;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }
    cin >> k;
    vis[1][1] = true;
    q.emplace(1, 1);
    while (!q.empty()) {
        auto [x, y] = q.front();
        if (x == n && y == m) break;
        q.pop();
        for (int i = max(1, x - k); i <= min(n, x + k); i++) {
            for (int j = max(1, y - k); j <= min(m, y + k); j++) {
                if (abs(i - x) + abs(j - y) <= k && !vis[i][j] && a[i][j] == a[1][1]) {
                    vis[i][j] = true;
                    q.emplace(i, j);
                }
            }
        }
    }
    cout << (vis[n][m] ? "ALIVE" : "DEAD");
}
