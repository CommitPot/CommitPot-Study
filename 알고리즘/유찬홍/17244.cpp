#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n, m, vis[51][51][33] = {0}, d[] = {0, 1, 0, -1, 0}, a = 48, rs = -1;
    string map[51];
    queue<tuple<int, int, int, int>>
            q;
    cin >> m >> n;
    for (int i = 0; i < n; i++) {
        cin >> map[i];
        int len = map[i].length();
        for (int j = 0; j < len; j++) {
            if (map[i][j] == 'S') {
                vis[i][j][0] = 1;
                map[i][j] = '.';
                q.emplace(i, j, 0, 0);
            }
            if (map[i][j] == 'X') {
                map[i][j] = a++;
            }
        }
    }
    while (!q.empty()) {
        auto [x, y, w, b] = q.front();
        if (map[x][y] == 69 && w == a - 48) {
            rs = vis[x][y][b] - 1;
            break;
        }
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + d[i], ny = y + d[i + 1], c = b;
            if (nx < 0 || nx >= n || ny < 0 || ny >= m || map[nx][ny] == '#') continue;
            if (47 < map[nx][ny] && map[nx][ny] < 53) {
                c |= (1 << (map[nx][ny] - 48));
                if (!(b & (1 << (map[nx][ny] - 48))) && !vis[nx][ny][c]) {
                    vis[nx][ny][c] = vis[x][y][b] + 1;
                    q.emplace(nx, ny, w + 1, c);
                }
            }
            if (!vis[nx][ny][b]) {
                vis[nx][ny][b] = vis[x][y][b] + 1;
                q.emplace(nx, ny, w, b);
            }
        }
    }
    cout << rs;
}
