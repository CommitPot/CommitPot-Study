#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

long long a[1 << 18];

void u(int s, int e, int l, int r, int w, int n = 1) {
    if (e < l || r < s) return;
    if (l <= s && e <= r) {
        a[n] = w;
        return;
    }
    int m = (s + e) / 2;
    u(s, m, l, r, w, n * 2);
    u(m + 1, e, l, r, w, n * 2 + 1);
    a[n] = a[n * 2] + a[n * 2 + 1];
}

long long f(int s, int e, int l, int r, int n = 1) {
    if (e < l || r < s) return 0;
    if (l <= s && e <= r) return a[n];
    return f(s, (s + e) / 2, l, r, n * 2) + f((s + e) / 2 + 1, e, l, r, n * 2 + 1);
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n, m;
    vector<pair<int, int>> l;
    vector<tuple<int, int, int, int>> r;
    cin >> n;
    int x = 1 << (int) ceil(log2(n));
    for (int i = x; i < x + n; i++) cin >> a[i];
    for (int i = x + n - 1; i > 1; i--) a[i / 2] += a[i];
    cin >> m;
    while (m--) {
        int b, c, d, e;
        cin >> b;
        if (b == 1) {
            cin >> c >> d;
            l.emplace_back(c, d);
        } else {
            cin >> c >> d >> e;
            r.emplace_back(c, d, e, r.size());
        }
    }
    vector<long long> v(r.size());
    sort(r.begin(), r.end());
    int p = 0, q = 0;
    for (auto [b, c, d, e]: r) {
        while (p != b) {
            p++;
            auto [f, s] = l[q++];
            u(1, x, f, f, s);
        }
        v[e] = f(1, x, c, d);
    }
    for (auto i: v) cout << i << '\n';
}
