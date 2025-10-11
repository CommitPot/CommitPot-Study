#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> m[100001];

int t[100001];

int f(int v, int p, int l) {
    if (t[v] >= 0) return t[v];
    t[v] = l ? -1e9 : 1e9;
    for (int i: m[v]) {
        if (i == p) continue;
        int r = f(i, v, !l);
        t[v] = l ? max(t[v], r) : min(t[v], r);
    }
    return t[v];
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n, r, l, q;
    cin >> n >> r;
    for (int i = 1, u, v; i < n; i++) {
        cin >> u >> v;
        m[u].emplace_back(v);
        m[v].emplace_back(u);
    }
    for (int i = 1; i <= n; i++) t[i] = -1;
    cin >> l;
    for (int i = 0, a, b; i < l; i++) {
        cin >> a >> b;
        t[a] = b;
    }
    f(r, 0, 1);
    cin >> q;
    while (q--) {
        cin >> r;
        cout << t[r] << '\n';
    }
}
