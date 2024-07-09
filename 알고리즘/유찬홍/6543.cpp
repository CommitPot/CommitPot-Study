#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;
int id, vis[5001], g[5001];
bool fin[5001];
vector<int> l[5001], l1[5001];
vector<vector<int>> scc;
stack<int> s;

int f(int v) {
    int p = vis[v] = ++id;
    s.push(v);
    for (int i: l[v]) {
        if (!vis[i]) p = min(p, f(i));
        else if (!fin[i]) p = min(p, vis[i]);
    }

    if (vis[v] == p) {
        vector<int> c;
        while (true) {
            int t = s.top();
            s.pop();
            c.emplace_back(t);
            fin[t] = true;
            g[t] = scc.size();
            if (t == v) break;
        }
        sort(c.begin(), c.end());
        scc.emplace_back(c);
    }
    return p;
}
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n, m;
    while (cin >> n >> m) {
        int c = 0;
        for (int i = 0, a, b; i < m; i++) {
            cin >> a >> b;
            l[a].emplace_back(b);
        }
        for (int i = 1; i <= n; i++) if (!vis[i]) f(i);
        for (int i = 1; i <= n; i++) {
            for (auto j : l[i]) {
                if (g[i] == g[j]) continue;
                l1[g[i]].emplace_back(g[j]);   
            }
        }
        vector<int> r;
        for (int i = 0; i < scc.size(); i++) {
            if (l1[i].empty()) {
                r.reserve(r.size() + scc[i].size());
                r.insert(r.end(), scc[i].begin(), scc[i].end());
            }
        }
        sort(r.begin(), r.end());
        for (int i : r) cout << i << ' ';
        cout << '\n';
        id = 0;
        scc.clear();
        while(!s.empty()) s.pop();
        for (int i = 0; i <= n; i++) {
            l[i].clear();
            l1[i].clear();
            vis[i] = g[i] = fin[i] = false;
        }
    }
}
