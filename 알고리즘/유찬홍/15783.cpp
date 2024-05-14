#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int id = 0, vis[100001], pa[100001];
bool fin[100001];
vector<int> l[100001];
vector<vector<int>> scc;
stack<int> s;

int f(int v) {
    int p = vis[v] = ++id;
    s.push(v);
    for (int i: l[v]) {
        if (!vis[i]) p = min(p, f(i));
        else if (!fin[i]) p = min(p, vis[i]);
    }

    if (p == vis[v]) {
        vector<int> c;
        while (true) {
            int x = s.top();
            s.pop();
            pa[x] = scc.size();
            c.emplace_back(x);
            fin[x] = true;
            if (x == v) break;
        }
        scc.emplace_back(c);
    }
    return p;
}

void dfs(int v) {
    for (int i: scc[v]) {
        if (!fin[i]) {
            fin[i] = true;
            dfs(i);
        }
    }
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n, m, cnt = 0, dg[100001] = {};
    cin >> n >> m;
    vector<int> e;
    while (m--) {
        int a, b;
        cin >> a >> b;
        l[a].emplace_back(b);
    }
    for (int i = 0; i < n; i++) if (!vis[i]) f(i);
    for (int i = 0; i < n; i++) fin[i] = false;
    for (auto &i: scc) {
        vector<int> c;
        for (int j: i) {
            for (int k: l[j]) {
                if (pa[j] != pa[k]) c.emplace_back(pa[k]), dg[pa[k]]++;
            }
        }
        i = c;
    }
    for (int i = 0; i < scc.size(); i++) {
        if (!fin[i] && !dg[i]) {
            cnt++;
            fin[i] = true;
            dfs(i);
        }
    }
    cout << cnt;
}
