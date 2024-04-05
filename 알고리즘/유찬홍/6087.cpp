#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n, m, c, d, vis[101][101] = {0}, e[] = {0, 1, 0, -1};
    bool b = false;
    char a[101][101];
    queue<tuple<int, int, int>> q;
    cin >> m >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        for (int j = 0; j < m; j++) {
            if (a[i][j] == 'C') {
                if (!b) q.emplace(i, j, 1), b = true, vis[i][j] = 1, a[i][j] = '.';
                c = i, d = j;
            }
        }
    }
    while (!q.empty()) {
        auto [x, y, w] = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + e[i], ny = y + e[3 - i];
            while (nx >= 0 && nx < n && ny >= 0 && ny < m && a[nx][ny] != '*' &&
                   (!vis[nx][ny] || vis[nx][ny] == w + 1)) {
                if (!vis[nx][ny]) {
                    vis[nx][ny] = w + 1;
                    q.emplace(nx, ny, w + 1);
                }
                nx = nx + e[i];
                ny = ny + e[3 - i];
            }
        }
    }
    cout << vis[c][d] - 2;
}
