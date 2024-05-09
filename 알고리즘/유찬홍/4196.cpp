#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

int idx, scc_size, vis[100001], g[100001];
bool finished[100001];
vector<int> l[100001];
stack<int> s;

int f(int v) {
    int p = vis[v] = ++idx;
    s.push(v);
    for (int &i: l[v]) {
        if (!vis[i]) p = min(p, f(i));
        else if (!finished[i]) p = min(p, vis[i]);
    }

    if (vis[v] == p) {
        scc_size++;
        while (true) {
            int t = s.top();
            s.pop();
            finished[t] = true;
            g[t] = scc_size;
            if (t == v) break;
        }
    }
    return p;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t, n, m;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        int dg[100001] = {}, c = 0;
        for (int i = 0, a, b; i < m; i++) {
            cin >> a >> b;
            l[a].emplace_back(b);
        }
        for (int i = 1; i <= n; i++) if (!vis[i]) f(i);
        for (int i = 1; i <= n; i++) {
            for (int j: l[i]) {
                if (g[i] == g[j]) continue;
                dg[g[j]]++;
            }
        }
        for (int i = 0; i < scc_size; i++) if (!dg[i]) c++;
        cout << c << "\n";
        idx = scc_size = 0;
        for (int i = 1; i <= n; i++) {
            l[i].clear();
            vis[i] = finished[i] = false;
        }
    }
}
