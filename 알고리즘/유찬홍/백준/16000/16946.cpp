#include <cstring>
#include <vector>
#include <iostream>

using namespace std;

int n, m, d[] = {0, 1, 0, -1}, r[1001][1001] = {};
bool vis[1001][1001];
string a[1001];
vector<pair<int, int> > p;

int f(int x, int y) {
    int k = 0;
    for (int i = 0; i < 4; i++) {
        int nx = x + d[i], ny = y + d[3 - i];
        if (nx < 0 || ny < 0 || nx >= n || ny >= m || a[nx][ny] & 1 || vis[nx][ny]) continue;
        vis[nx][ny] = true;
        k += f(nx, ny);
    }
    return k + 1;
}

void g(int x, int y, int v) {
    for (int i = 0; i < 4; i++) {
        int nx = x + d[i], ny = y + d[3 - i];
        if (nx < 0 || ny < 0 || nx >= n || ny >= m || a[nx][ny] & 1 || !vis[nx][ny]) continue;
        p.emplace_back(nx, ny);
        vis[nx][ny] = false;
        r[nx][ny] = v;
        g(nx, ny, v);
    }
}

void h(int x, int y, int v) {
    for (int i = 0; i < 4; i++) {
        int nx = x + d[i], ny = y + d[3 - i];
        if (nx < 0 || ny < 0 || nx >= n || ny >= m || vis[nx][ny]) continue;
        vis[nx][ny] = true;
        if (a[nx][ny] == 49) {
            p.emplace_back(nx, ny);
            r[nx][ny] += v;
            continue;
        }
        h(nx, ny, v);
    }
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (~a[i][j] & 1 && !vis[i][j]) {
                vis[i][j] = true;
                r[i][j] = f(i, j);
                g(i, j, r[i][j]);
                for (auto [x, y]: p) vis[x][y] = true;
                p.clear();
            }
        }
    }
    memset(vis, false, sizeof(vis));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (vis[i][j] || a[i][j] == 49) continue;
            vis[i][j] = true;
            h(i, j, r[i][j]);
            for (auto [x, y]: p) vis[x][y] = false;
            p.clear();
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << (a[i][j] & 1 ? (r[i][j] + 1) % 10 : 0);
        }
        cout << '\n';
    }
}
