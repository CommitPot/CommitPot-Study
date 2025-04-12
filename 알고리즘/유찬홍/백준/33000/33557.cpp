#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int n, m, w[100002] = {};
    bool vis[100002] = {};
    vector<int> l[100001];
    cin >> n >> m;
    for (int i = 0, a, b; i < m; i++) {
        cin >> a >> b;
        l[a].emplace_back(b);
        l[b].emplace_back(a);
        w[a]++, w[b]++;
    }
    int t = 0;
    while (w[++t] > 1);
    if (n != m || t == n + 1 || l[t].empty()) {
        cout << "NO";
        return 0;
    }
    vis[t] = true;
    t = l[t].front();
    while (w[t] == 2 && !vis[t]) {
        vis[t] = true;
        for (int i: l[t]) {
            if (!vis[i]) t = i;
        }
    }
    int s = 0;
    for (int i: l[t]) {
        if (!vis[i]) s = i;
    }
    vis[t] = false;
    auto p = find(l[s].begin(), l[s].end(), t);
    if (p == l[s].end()) {
        cout << "NO";
        return 0;
    }
    l[s].erase(p);
    while (w[s] == 2 && !vis[s]) {
        vis[s] = true;
        for (int i: l[s]) {
            if (!vis[i]) s = i;
        }
    }
    vis[t] = true;
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            s = -1;
            break;
        }
    }
    cout << (s == t ? "YES" : "NO");
}
