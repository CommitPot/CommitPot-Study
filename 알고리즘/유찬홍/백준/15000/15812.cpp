#include <queue>
#include <vector>
#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int n, m, d[] = {0, 1, 0, -1}, r = 1e9;
    queue<pair<int, int> > q;
    vector<pair<int, int> > l, p;
    string a[21];
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == 48) l.emplace_back(i, j);
            else p.emplace_back(i, j);
        }
    }
    for (int i = 0; i < l.size(); i++) {
        for (int j = i + 1; j < l.size(); j++) {
            q.emplace(l[i]);
            q.emplace(l[j]);
            int c[21][21] = {}, e = 0;
            c[l[i].first][l[i].second] = c[l[j].first][l[j].second] = 1;
            while (!q.empty()) {
                auto [x, y] = q.front();
                q.pop();
                for (int k = 0; k < 4; k++) {
                    int nx = x + d[k], ny = y + d[3 - k];
                    if (nx >= 0 && nx < n && ny >= 0 && ny < m && !c[nx][ny]) {
                        q.emplace(nx, ny);
                        c[nx][ny] = c[x][y] + 1;
                    }
                }
            }
            for (auto [x, y]: p) {
                if (c[x][y] > e) e = c[x][y];
            }
            if (e < r) r = e;
        }
    }
    cout << r - 1;
}
