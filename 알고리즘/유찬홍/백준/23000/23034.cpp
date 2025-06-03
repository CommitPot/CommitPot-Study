#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int f(int v, int *q) {
    return q[v] == v ? v : f(q[v], q);
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    vector<pair<int, int> > l[1001];
    vector<tuple<int, int, int> > v;
    int n, m, a, b, c, d = 0, r = 0, p[1001], u[1001][1001] = {};
    queue<pair<int, int> > q;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) p[i] = i;
    while (m--) {
        cin >> a >> b >> c;
        v.emplace_back(c, a, b);
    }
    sort(v.begin(), v.end());
    for (auto [w, x, y]: v) {
        if (f(x, p) != f(y, p)) {
            p[f(x, p)] = f(y, p);
            l[x].emplace_back(y, w);
            l[y].emplace_back(x, w);
            d++;
            r += w;
        }
        if (d == n - 1) break;
    }
    for (int i = 1; i <= n; i++) {
        bool vis[1001] = {};
        vis[i] = true;
        q.emplace(i, 0);
        while (!q.empty()) {
            auto [x, w] = q.front();
            q.pop();
            for (auto [z, W]: l[x]) {
                if (vis[z]) continue;
                vis[z] = true;
                q.emplace(z, max(w, W));
                u[i][z] = max(W, w);
            }
        }
    }
    cin >> m;
    while (m--) {
        cin >> a >> b;
        cout << r - u[a][b] << '\n';
    }
}
