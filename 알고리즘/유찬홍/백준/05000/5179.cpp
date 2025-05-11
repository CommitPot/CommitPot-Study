#include <queue>
#include <vector>
#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n, m, s, e;
    while (cin >> n >> m) {
        if (!n) break;
        cin >> s >> e;
        queue<pair<int, int>> q;
        priority_queue<pair<int, int>> pq;
        vector<pair<int, int>> l[501], r[501];
        int d[501];
        bool vis[501] = {}, p[501][501] = {};
        for (int i = 0, a, b, c; i < m; i++) {
            cin >> a >> b >> c;
            l[a].emplace_back(b, c);
            r[b].emplace_back(a, c);
        }
        auto ds = [&]() -> void {
            for (int i = 0; i < n; i++) d[i] = 1e9;
            pq.emplace(0, s);
            d[s] = 0;
            while (!pq.empty()) {
                auto [w, v] = pq.top();
                pq.pop();
                for (auto [u, nw]: l[v]) {
                    if (!p[v][u] && -w + nw < d[u]) {
                        d[u] = -w + nw;
                        pq.emplace(-d[u], u);
                    }
                }
            }
            return;
        };
        ds();
        q.emplace(e, 0);
        vis[e] = true;
        while (!q.empty()) {
            auto [v, w] = q.front();
            q.pop();
            for (auto [u, uw]: r[v]) {
                if (w + uw + d[u] == d[e]) {
                    p[u][v] = true;
                    if (!vis[u]) {
                        vis[u] = true;
                        q.emplace(u, w + uw);
                    }
                }
            }
        }
        ds();
        cout << (d[e] == 1e9 ? -1 : d[e]) << '\n';
    }
}
