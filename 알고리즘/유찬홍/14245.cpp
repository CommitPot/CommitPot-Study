#include <iostream>
#include <cmath>

using namespace std;

int tree[1 << 20], lazy[1 << 20];

void u(int s, int e, int l, int r, int w, int n = 1) {
    tree[n] ^= lazy[n];
    if (s != e) {
        lazy[n * 2] ^= lazy[n];
        lazy[n * 2 + 1] ^= lazy[n];
    }
    lazy[n] = 0;
    if (r < s || e < l) return;
    if (l <= s && e <= r) {
        tree[n] ^= w;
        if (s != e) {
            lazy[n * 2] ^= w;
            lazy[n * 2 + 1] ^= w;
        }
        return;
    }
    int m = (s + e) / 2;
    u(s, m, l, r, w, n * 2);
    u(m + 1, e, l, r, w, n * 2 + 1);
    tree[n] = tree[n * 2] ^ tree[n * 2 + 1];
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n, m;
    string r;
    cin >> n;
    int x = 1 << (int) ceil(log2(n));
    for (int i = x; i < x + n; i++) cin >> tree[i];
    for (int i = x - 1; i >= 1; i--) tree[i] ^= tree[i * 2] ^ tree[i * 2 + 1];
    cin >> m;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b;
        if (a == 1) {
            cin >> c >> a;
            u(1, x, b + 1, c + 1, a);
        } else {
            u(1, x, b + 1, b + 1, 0);
            r += to_string(tree[x + b]) + '\n';
        }
    }
    cout << r;
}
