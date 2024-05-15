#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

int id = 0, vis[1201], pa[1201];
bool fin[1201];
vector<vector<int>> scc;
vector<int> l[1201];
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

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n;
    string a;
    cin >> n;
    map<string, int> m;
    for (int i = 0, b; i < n; i++) {
        cin >> a >> b;
        if (m.find(a) == m.end()) m[a] = m.size();
        for (int j = 0; j < b; j++) {
            string c;
            cin >> c;
            if (m.find(c) == m.end()) m[c] = m.size();
            l[m[c]].emplace_back(m[a]);
        }
    }
    cin >> a;
    for (int i = 0; i < m.size(); i++) if (!vis[i]) f(i);
    int ind[1201] = {};
    vector<vector<int>> l1;
    for (auto &i: scc) {
        bool vis2[1201] = {};
        vector<int> c;
        for (int j: i) {
            for (int k: l[j]) {
                if (pa[j] != pa[k] && !vis2[pa[k]]) {
                    ind[pa[k]]++;
                    vis2[pa[k]] = true;
                    c.emplace_back(pa[k]);
                }
            }
        }
        l1.emplace_back(c);
    }
    queue<int> q;
    vector<int> tp;
    for (int i = 0; i < scc.size(); i++) if (!ind[i]) q.emplace(i);
    while (!q.empty()) {
        auto p = q.front();
        q.pop();
        tp.emplace_back(p);
        for (int i: l1[p]) {
            if (!--ind[i]) q.emplace(i);
        }
    }
    long long rs[1201] = {};
    for (int i = 0; i < m.size(); i++) rs[i] = 1;
    for (int i: tp) {
        for (int j: scc[i]) {
            for (int k: l[j]) {
                if (pa[j] != pa[k]) rs[k] += rs[j];
            }
        }
    }
    cout << rs[m[a]];
}
