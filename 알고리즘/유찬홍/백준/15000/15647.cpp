#include <tuple>
#include <vector>
#include <cstring>
#include <iostream>

using namespace std;

vector<pair<int, int> > l[300001];
tuple<int, int, int> q[300001];
long long dp[300001];

tuple<int, int, int> f(int v = 1, int p = 0) {
    int k = 0, w;
    for (auto [u, d]: l[v]) {
        if (p == u) {
            w = d;
            continue;
        }
        k += get<2>(f(u, v));
    }
    return q[v] = {p, w, k + 1};
}

long long g(int v = 1) {
    if (dp[v] != -1) return dp[v];
    dp[v] = 0;
    for (auto [u, d]: l[v]) {
        if (get<0>(q[v]) == u) continue;
        dp[v] += g(u) + d * get<2>(q[u]);
    }
    return dp[v];
}

void h(int n, int v = 1) {
    if (v != 1) {
        auto [p, w, k] = q[v];
        dp[v] += dp[p] - (dp[v] + k * w) + (n - k) * w;
    }
    for (auto [u, d]: l[v]) {
        if (get<0>(q[v]) != u) h(n, u);
    }
}


int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n;
    string s;
    cin >> n;
    for (int i = 1, u, v, d; i < n; i++) {
        cin >> u >> v >> d;
        l[u].emplace_back(v, d);
        l[v].emplace_back(u, d);
    }
    memset(dp, -1, sizeof(dp));
    q[1] = f(), g(), h(n);
    for (int i = 1; i <= n; i++) s += to_string(dp[i]) + "\n";
    cout << s;
}
