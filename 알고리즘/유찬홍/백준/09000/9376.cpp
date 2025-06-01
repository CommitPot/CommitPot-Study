#include <queue>
#include <vector>
#include <cstring>
#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int t, n, m, d[] = {0, 1, 0, -1};
    cin >> t;
    while (t--) {
        cin >> n >> m;
        int r = 1e9, vis[3][102][102] = {};
        char s[102][103];
        memset(s, '.', sizeof(s));
        vector<pair<int, int>> p, o;
        deque<pair<int, int>> q;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                cin >> s[i][j];
                if (s[i][j] == '$') p.emplace_back(i, j);
            }
        }
        p.emplace_back(0, 0);
        for (int i = 0; i < 3; i++) {
            q.emplace_back(p[i]);
            vis[i][p[i].first][p[i].second] = 1;
            while (!q.empty()) {
                auto [a, b] = q.front();
                q.pop_front();
                for (int j = 0; j < 4; j++) {
                    int x = a + d[j], y = b + d[3 - j];
                    if (x < 0 || x > n + 1 || y < 0 || y > m + 1 || vis[i][x][y] || s[x][y] == '*') continue;
                    if (s[x][y] == '.' || s[x][y] == '$') {
                        vis[i][x][y] = vis[i][a][b];
                        q.emplace_front(x, y);
                    } else {
                        vis[i][x][y] = vis[i][a][b] + 1;
                        q.emplace_back(x, y);
                    }
                }
            }
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (s[i][j] == '*' || !vis[0][i][j] || !vis[1][i][j] || !vis[2][i][j]) {
                    vis[0][i][j] = vis[1][i][j] = vis[2][i][j] = 1e5;
                }
                r = min(r, vis[0][i][j] + vis[1][i][j] + vis[2][i][j] - 3 - (s[i][j] == '#' ? 2 : 0));
            }
        }
        cout << r << '\n';
    }
}
