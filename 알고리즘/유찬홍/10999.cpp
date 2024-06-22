#include <iostream>
#include <cmath>

using namespace std;

long long tree[1 << 21], lazy[1 << 21];

void lu(int s, int e, int n) {
    if (lazy[n]) {
        tree[n] += lazy[n] * (e - s + 1);
        if (s != e) {
            lazy[n * 2] += lazy[n];
            lazy[n * 2 + 1] += lazy[n];
        }
        lazy[n] = 0;
    }
}

void u(int s, int e, int l, int r, long long w, int n = 1) {
    lu(s, e, n);
    if (r < s || e < l) return;
    if (l <= s && e <= r) {
        tree[n] += w * (e - s + 1);
        if (s != e) {
            lazy[n * 2] += w;
            lazy[n * 2 + 1] += w;
        }
        return;
    }
    int m = (s + e) / 2;
    u(s, m, l, r, w, n * 2);
    u(m + 1, e, l, r, w, n * 2 + 1);
    tree[n] = tree[n * 2] + tree[n * 2 + 1];
}

long long f(int s, int e, int l, int r, int n = 1) {
    lu(s, e, n);
    if (e < l || r < s) return 0;
    if (l <= s && e <= r) return tree[n];
    return f(s, (s + e) / 2, l, r, n * 2) + f((s + e) / 2 + 1, e, l, r, n * 2 + 1);
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n, m, k;
    string r;
    cin >> n >> m >> k;
    int x = 1 << (int) ceil(log2(n));
    for (int i = x; i < x + n; i++) cin >> tree[i];
    for (int i = x - 1; i >= 1; i--) tree[i] = tree[i * 2] + tree[i * 2 + 1];
    for (int i = 0; i < m + k; i++) {
        int a, b, c;
        long long d;
        cin >> a >> b >> c;
        if (a == 1) {
            cin >> d;
            u(1, x, b, c, d);
        } else r += to_string(f(1, x, b, c)) + '\n';
    }
    cout << r;
}
