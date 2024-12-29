#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

int idx, vis[100001];
bool finished[100001];
vector<int> l[100001];
vector<vector<int>> scc;
stack<int> s;

int f(int v) {
    int p = vis[v] = ++idx;
    s.push(v);
    for (int i: l[v]) {
        if (!vis[i]) p = min(p, f(i));
        else if (!finished[i]) p = min(p, vis[i]);
    }
    if (vis[v] == p) {
        vector<int> c;
        while (true) {
            int t = s.top();
            s.pop();
            finished[t] = true;
            c.emplace_back(t);
            if (t == v) break;
        }
        sort(c.begin(), c.end());
        scc.emplace_back(c);
    }
    return p;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t, n, m;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        idx = 0;
        for (int i = 0; i < n; i++) l[i].clear(), vis[i] = finished[i] = false;
        scc.clear();
        int v[100001] = {}, dg[100001] = {};
        for (int i = 0, a, b; i < m; i++) {
            cin >> a >> b;
            l[a].emplace_back(b);
        }
        for (int i = 0; i < n; i++) if (!vis[i]) f(i);
        for (int i = 0; i < scc.size(); i++) {
            for (int j: scc[i]) {
                v[j] = i;
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j: l[i]) {
                if (v[i] == v[j]) continue;
                dg[j]++;
            }
        }

        vector<int> ans;
        int cnt = 0;
        for (auto &i: scc) {
            int c = 0;
            for (int j: i) c += dg[j];
            if (!c) {
                cnt++;
                for (int j: i) ans.emplace_back(j);
            }
        }
        if (cnt != 1) cout << "Confused\n\n";
        else {
            for (int i: ans) {
                cout << i << "\n";
            }
            cout << "\n";
        }
    }
}
