#include <iostream>
#include <queue>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int w, h, d[] = {0, 1, 0, -1, 0};
    cin >> w >> h;
    while (w | h) {
        string map[h + 1];
        queue<tuple<int, int, int>> q;
        int vis[21][21][1025] = {0}, rs = -1;
        char z = 48;
        for (int i = 0; i < h; i++) {
            cin >> map[i];
            for (int j = 0; j < w; j++) {
                if (map[i][j] == 'o') map[i][j] = '.', q.emplace(i, j, 0), vis[i][j][0] = 1;
                if (map[i][j] == '*') map[i][j] = z++;
            }
        }
        while (!q.empty()) {
            auto [x, y, b] = q.front();
            if (b == pow(2, z - 48) - 1) {
                rs = vis[x][y][b] - 1;
                break;
            }
            q.pop();
            for (int i = 0; i < 4; i++) {
                int nx = x + d[i], ny = y + d[i + 1], c = b;
                if (nx < 0 || nx >= h || ny < 0 || ny >= w || map[nx][ny] == 'x') continue;
                if (map[nx][ny] == '.') c = b;
                if (map[nx][ny] > 47 && map[nx][ny] < 58) {
                    c |= (1 << (map[nx][ny] - 48));
                    if (!vis[nx][ny][c] && (b & (1 << (map[nx][ny] - 48)))) c = b;
                }
                if (!vis[nx][ny][c]) {
                    vis[nx][ny][c] = vis[x][y][b] + 1;
                    q.emplace(nx, ny, c);
                }
            }
        }
        cout << rs << "\n";
        cin >> w >> h;
    }
}
