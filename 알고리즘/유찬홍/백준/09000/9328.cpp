#include <iostream>
#include <queue>
#include <memory.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t, d[] = {0, 1, 0, -1, 0};
    cin >> t;
    while (t--) {
        int h, w, rs = 0, cnt = 0;
        bool vis[105][105], alpha[27];
        memset(alpha, false, 26);
        string s;
        char map[105][105];
        queue<pair<int, int>> q;
        cin >> h >> w;
        for (int i = 1; i <= h; i++) {
            for (int j = 1; j <= w; j++) {
                cin >> map[i][j];
            }
        }
        for (int i = 0; i <= h + 1; i++) {
            for (int j = 0; j <= w + 1; j++) {
                if (!i || !j || i == h + 1 || j == w + 1) map[i][j] = '.';
            }
        }
        cin >> s;
        if (s[0] != '0') for (char i: s) alpha[i - 97] = true;
        do {
            for (auto &i: vis) for (bool &j: i) j = false;
            cnt = 0;
            vis[0][0] = true;
            q.emplace(0, 0);
            while (!q.empty()) {
                auto [x, y] = q.front();
                if (map[x][y] == '$') {
                    map[x][y] = '.';
                    rs++;
                }
                q.pop();
                for (int i = 0; i < 4; i++) {
                    int nx = x + d[i], ny = y + d[i + 1];
                    if (nx < 0 || nx > h + 1 || ny < 0 || ny > w + 1 || map[nx][ny] == '*' || vis[nx][ny]) continue;
                    if (64 < map[nx][ny] && map[nx][ny] < 91) {
                        if (alpha[map[nx][ny] - 65]) {
                            map[nx][ny] = '.';
                            vis[nx][ny] = true;
                            q.emplace(nx, ny);
                        }
                    }
                    if (96 < map[nx][ny] && map[nx][ny] < 123) {
                        alpha[map[nx][ny] - 97] = true;
                        cnt++;
                        map[nx][ny] = '.';
                        vis[nx][ny] = true;
                        q.emplace(nx, ny);
                    }
                    if (map[nx][ny] == '$' || map[nx][ny] == '.') {
                        vis[nx][ny] = true;
                        q.emplace(nx, ny);
                    }
                }
            }
        } while (cnt);
        cout << rs << "\n";
    }
}
