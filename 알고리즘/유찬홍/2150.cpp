#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

int idx, vis[10001];
bool fin[10001];
vector<int> l[10001];
vector<vector<int>> scc;
stack<int> s;

int f(int v) {
    vis[v] = ++idx;
    s.push(v);
    int p = vis[v];
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
            if (t == v) break;
        }
        sort(c.begin(), c.end());
        scc.push_back(c);
    }
    return p;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int v, e;
    cin >> v >> e;
    for (int i = 0, a, b; i < e; i++) {
        cin >> a >> b;
        l[a].emplace_back(b);
    }
    for (int i = 1; i <= v; i++) if (!vis[i]) f(i);
    cout << scc.size() << "\n";
    sort(scc.begin(), scc.end());
    for (const auto &i: scc) {
        for (int j: i) cout << j << " ";
        cout << "-1\n";
    }
}
