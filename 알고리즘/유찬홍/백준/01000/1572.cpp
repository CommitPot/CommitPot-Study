#include <iostream>
#include <deque>

using namespace std;
int tree[1 << 17];

void u(int s, int e, int idx, int r, int n = 1) {
    if (idx < s || idx > e) return;
    tree[n] += r;
    if (s != e) {
        int m = (s + e) / 2;
        u(s, m, idx, r, n * 2);
        u(m + 1, e, idx, r, n * 2 + 1);
    }
}

int f(int k, int t, int n = 1) {
    if (n >= t) return n - t;
    if (tree[n * 2] >= k) return f(k, t, n * 2);
    return f(k - tree[n * 2], t, n * 2 + 1);
}


int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n, k;
    deque<int> q;
    long long s = 0;
    cin >> n >> k;
    for (int i = 1, a; i < k; i++) {
        cin >> a;
        q.emplace_back(a + 1);
        u(1, 1 << 16, a + 1, 1);
    }
    for (int i = k, a; i <= n; i++) {
        cin >> a;
        q.emplace_back(a + 1);
        u(1, 1 << 16, a + 1, 1);
        s += f((k + 1) / 2, 1 << 16);
        u(1, 1 << 16, q.front(), -1);
        q.pop_front();
    }
    cout << s;
}
