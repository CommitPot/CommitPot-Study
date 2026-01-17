#include <vector>
#include <iostream>

using namespace std;

vector<pair<int, int> > l[100001];
pair<int, int> vis[100001];

pair<int, int> o(int v, int p = -1) {
    pair k = {v, 0};
    for (auto [u, d]: l[v]) {
        if (u == p) continue;
        auto x = o(u, v);
        if (k.second < x.second + d) {
            k = {x.first, x.second + d};
        }
    }
    return k;
}

pair<int, int> s(int v) {
    pair k = {v, 0};
    for (auto [u, d]: l[v]) {
        if (vis[u].first != -1) continue;
        vis[u] = {v, d};
        auto x = s(u);
        if (k.second < x.second + d) {
            k = {x.first, x.second + d};
        }
    }
    return k;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 0, u, v, d; i < m; i++) {
        cin >> u >> v >> d;
        l[u].emplace_back(v, d);
        l[v].emplace_back(u, d);
    }
    for (int i = 0; i < n; i++) vis[i] = {-1, 0};
    vector<pair<int, int> > st;
    for (int i = 0; i < n; i++) {
        if (vis[i].first == -1) {
            int a = o(i).first;
            vis[a] = {-2, 0};
            pair x = s(a);
            vector<pair<int, int> > t;
            int q = x.first;
            while (vis[q].first != -2) {
                t.emplace_back(q, vis[q].second);
                q = vis[q].first;
            }
            t.emplace_back(q, vis[q].second);
            pair<int, int> r = x;
            int c = 0;
            for (int j = 1; j < t.size(); j++) {
                c += t[j - 1].second;
                int w = max(c, x.second - c);
                if (r.second > w) r = {t[j].first, w};
            }
            st.emplace_back(r);
        }
    }
    pair r = {-1, -1};
    for (auto [u, w]: st) {
        if (r.second < w) r = {u, w};
    }
    for (auto [u, v]: st) {
        if (r.first == u) continue;
        l[u].emplace_back(r.first, k);
        l[r.first].emplace_back(u, k);
    }
    cout << o(o(0).first).second;
}
