#include <iostream>
#include <queue>

using namespace std;

int main() {
    int n, rs = 0, vis[2][51] = {0}, r[101] = {0}, d[] = {0, 1, 0, -1, 0};
    char m[2][51];
    queue<pair<int, int>> q;
    cin >> n;
    cin >> m[0] >> m[1];
    if (m[0][0] == '.') q.emplace(0, 0), vis[0][0] = 1;
    if (m[1][0] == '.') q.emplace(1, 0), vis[1][0] = 1;
    while (!q.empty()) {
        auto [x, y] = q.front();
        if (y == n - 1) break;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + d[i], ny = y + d[i + 1];
            if (nx < 0 || nx > 1 || ny < 0 || ny >= n || vis[nx][ny] || m[nx][ny] == '#') continue;
            vis[nx][ny] = vis[x][y] + 1;
            q.emplace(nx, ny);
        }
    }
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < n; j++) {
            if (m[i][j] == '#') continue;
            if (!vis[i][j]) {
                rs++;
                continue;
            }
            if (!r[vis[i][j]]) r[vis[i][j]] = 1;
            else rs++;
        }
    }
    cout << rs;
}
