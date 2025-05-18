#include <queue>
#include <vector>
#include <iostream>

using namespace std;

int f(int v, int *a) {
    return a[v] = a[v] == v ? v : f(a[v], a);
}

void u(int a, int b, int *c) {
    a = f(a, c);
    b = f(b, c);
    if (a == b) return;
    c[a] = b;
}

int main() {
    int n, m, t = 0, d[] = {0, 1, 0, -1}, p[2250000];
    bool vis[2250000] = {};
    vector<pair<int, int> > s;
    char a[1500][1501];
    queue<pair<int, int> > wq, q;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        scanf("%s", a[i]);
        for (int j = 0; j < m; j++) {
            int x = i * m + j;
            p[x] = x;
            if (a[i][j] == 'L') s.emplace_back(i, j);
            if (a[i][j] != 'X') {
                vis[x] = true;
                q.emplace(i, j);
            }
        }
    }
    while (!q.empty() || !wq.empty()) {
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            bool v = false;
            for (int i = 0; i < 4; i++) {
                int nx = x + d[i], ny = y + d[3 - i], w = nx * m + ny;
                if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                    if (a[nx][ny] != 'X') u(x * m + y, w, p);
                    if (vis[w]) continue;
                    if (a[nx][ny] != 'X') {
                        vis[w] = true;
                        q.emplace(nx, ny);
                    } else v = true;
                }
            }
            if (v) wq.emplace(x, y);
        }
        if (f(s[0].first * m + s[0].second, p) == f(s[1].first * m + s[1].second, p)) {
            cout << t;
            break;
        }
        while (!wq.empty()) {
            auto [x, y] = wq.front();
            wq.pop();
            for (int i = 0; i < 4; i++) {
                int nx = x + d[i], ny = y + d[3 - i], w = nx * m + ny;
                if (nx >= 0 && nx < n && ny >= 0 && ny < m && !vis[w]) {
                    if (a[nx][ny] == 'X') {
                        a[nx][ny] = '.';
                        vis[w] = true;
                        q.emplace(nx, ny);
                    }
                }
            }
        }
        t++;
    }
}
