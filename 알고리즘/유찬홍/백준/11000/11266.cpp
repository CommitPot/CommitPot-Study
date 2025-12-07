#include <set>
#include <vector>
#include <iostream>

using namespace std;

int vis[100001], cnt = 0;
vector<int> l[100001];
set<int> st;

int f(int v, int r) {
    vis[v] = ++cnt;
    int n = cnt, c = 0;
    for (int u: l[v]) {
        if (vis[u]) n = min(n, vis[u]);
        else {
            c++;
            int s = f(u, 0);
            if (!r && vis[v] <= s) st.insert(v);
            n = min(n, s);
        }
    }
    if (r && c >= 2) st.insert(v);
    return n;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int n, m;
    string r;
    cin >> n >> m;
    for (int i = 0, a, b; i < m; i++) {
        cin >> a >> b;
        l[a].emplace_back(b);
        l[b].emplace_back(a);
    }
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) f(i, 1);
    }
    r += to_string(st.size()) + "\n";
    for (int i: st) r += to_string(i) + " ";
    cout << r;
}
