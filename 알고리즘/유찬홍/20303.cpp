#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> a;

int f(int x) {
    return a[x] = a[x] == x ? x : f(a[x]);
}

bool u(int x, int y) {
    x = f(x);
    y = f(y);
    if (x == y) return true;
    a[max(x, y)] = min(x, y);
    return false;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n, m, k, b, c;
    cin >> n >> m >> k;
    vector<int> v(n + 1, 0), w(n + 1, 1);
    a.assign(n + 1, 0);
    for (int i = 1; i <= n; i++) cin >> v[i], a[i] = i;
    while (m--) {
        cin >> b >> c;
        u(b, c);
    }
    vector<int> dp(k + 1, 0);
    for (int i = 1; i <= n; i++) {
        if (a[i] != i) {
            int p = f(i);
            w[p] += w[i];
            v[p] += v[i];
        }
    }

    for (int i = 1; i <= n; i++) {
        if (a[i] != i) continue;
        for (int j = k - 1; j >= w[i]; j--) {
            dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
        }
    }
    cout << dp[k - 1];
}
