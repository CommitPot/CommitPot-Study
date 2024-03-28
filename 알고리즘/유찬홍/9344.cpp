#include <iostream>
#include <algorithm>

using namespace std;

int a[10001];

int f(int x) { return a[x] = x == a[x] ? x : f(a[x]); }

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t, n, m, p, q, u, v, w;
    cin >> t;
    while (t--) {
        cin >> n >> m >> p >> q;
        vector<tuple<int, int, int>> l;
        int rs = 0;
        bool c = false;
        while (m--) {
            cin >> u >> v >> w;
            l.emplace_back(w, u, v);
        }
        sort(l.begin(), l.end());
        for (int i = 0; i <= n; i++) a[i] = i;
        for (auto [i, j, k]: l) {
            int r = f(j), s = f(k);
            if (r == s) continue;
            if ((j == p && k == q) || (k == p && j == q)) c = true;
            a[max(r, s)] = min(r, s);
            rs++;
        }
        cout << (c && rs == n - 1 ? "YES" : "NO") << "\n";
    }
}
