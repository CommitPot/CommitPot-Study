#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int vis[100001], cnt = 0;
vector<int> l[100001];
vector<pair<int, int>> r;

int f(int v, int p) {
    vis[v] = ++cnt;
    int n = cnt;
    for (int u: l[v]) {
        if (u == p) continue;
        if (vis[u]) n = min(n, vis[u]);
        else {
            int s = f(u, v);
            if (vis[v] < s) r.emplace_back(min(v, u), max(v, u));
            n = min(n, s);
        }
    }
    return n;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int n, m;
    string str;
    cin >> n >> m;
    for (int i = 0, a, b; i < m; i++) {
        cin >> a >> b;
        l[a].emplace_back(b);
        l[b].emplace_back(a);
    }
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) f(i, 0);
    }
    sort(r.begin(), r.end());
    str += to_string(r.size()) + "\n";
    for (auto [s, e]: r) str += to_string(s) + " " + to_string(e) + "\n";
    cout << str;
}
