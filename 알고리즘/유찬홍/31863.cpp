#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n, m, c = 0, e = 0, d[] = {0, 1, 0, -1};
    cin >> n >> m;
    bool vis[1001][1001] = {};
    string a[1001];
    queue<tuple<int, int, int>> q;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        for (int j = 0; j < m; j++) {
            if (a[i][j] == '@') q.emplace(i, j, 1), a[i][j] = '.', vis[i][j] = true;
        }
    }
    while (!q.empty()) {
        auto [x, y, z] = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + d[i], ny = y + d[3 - i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m || vis[nx][ny] || a[nx][ny] == '|') continue;
            if (a[nx][ny] == '#') a[nx][ny] = '*';
            else if (a[nx][ny] == '.') vis[nx][ny] = true;
            else if (a[nx][ny] == '*') {
                a[nx][ny] = '.';
                c++;
                vis[nx][ny] = true;
                q.emplace(nx, ny, 0);
            } else continue;
            if (z == 0) continue;
            nx = x + d[i] * 2;
            ny = y + d[3 - i] * 2;
            if (nx < 0 || nx >= n || ny < 0 || ny >= m || vis[nx][ny] || a[nx][ny] == '|') continue;
            if (a[nx][ny] == '#') a[nx][ny] = '*';
            else if (a[nx][ny] == '.') vis[nx][ny] = true;
            else if (a[nx][ny] == '*') {
                a[nx][ny] = '.';
                c++;
                vis[nx][ny] = true;
                q.emplace(nx, ny, 0);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (char j: a[i]) if (j == '*' || j == '#') e++;
    }
    cout << c << " " << e;
}
