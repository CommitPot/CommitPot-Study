#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int maxV = 0, s = 0;
vector<int> p;
vector<bool> vis;
vector<pair<int, int>> l[1001];

int f(int x) { return p[x] = p[x] == x ? x : f(p[x]); }

void dfs(int v, int x) {
    if (maxV < x) {
        maxV = x;
        s = v;
    }
    for (auto [u, w]: l[v]) {
        if (!vis[u]) {
            vis[u] = true;
            dfs(u, w + x);
        }
    }
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    priority_queue<tuple<int, int, int>> q;
    int n, k, a, b, c, rs = 0;
    cin >> n >> k;
    p.assign(n, 0), vis.assign(n, false);
    while (k--) {
        cin >> a >> b >> c;
        q.emplace(-c, a, b);
    }
    for (int i = 0; i < n; i++) p[i] = i;
    while (!q.empty()) {
        auto [w, x, y] = q.top();
        q.pop();
        a = f(x), b = f(y);
        if (a == b) continue;
        l[x].emplace_back(y, -w);
        l[y].emplace_back(x, -w);
        p[max(a, b)] = min(a, b);
        rs += -w;
    }
    vis[0] = true;
    dfs(0, 0);
    vis.assign(n, false);
    vis[s] = true;
    dfs(s, 0);
    cout << rs << "\n" << maxV;
}
