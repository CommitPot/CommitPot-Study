#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> l[100001];
vector<long long> q;

int f(int n, int v, int p) {
    int r = 1;
    for (int u: l[v]) {
        if (u == p) continue;
        int b = f(n, u, v);
        q.emplace_back(1LL * b * (n - b));
        r += b;
    }
    return r;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int n, w[100001];
    cin >> n;
    for (int i = 1, a, b; i < n; i++) {
        cin >> a >> b;
        l[a].emplace_back(b);
        l[b].emplace_back(a);
    }
    for (int i = 1; i < n; i++) cin >> w[i - 1];
    f(n, 1, 0);
    sort(w, w + n - 1);
    sort(begin(q), end(q), greater<>());
    long long r = 0;
    for (int i = 0; i < n - 1; i++) {
        r = (r + q[i] * w[i]) % 1000000007;
    }
    cout << r;
}
