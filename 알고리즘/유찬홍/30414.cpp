#include <iostream>
#include <vector>

using namespace std;

int dp[100001], vis[100001];
vector<int> l[100001];

int f(int v, int p) {
    if (vis[v] < vis[p]) return 0;
    for (int i: l[v]) {
        dp[v] += f(i, v);
    }
    return dp[v] = min(dp[v], 0);
}

void dfs(int v) {
    for (int i: l[v]) {
        if (!vis[i]) {
            vis[i] = vis[v] + 1;
            dfs(i);
        }
    }
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n, p, u, v;
    cin >> n >> p;
    for (int i = 1; i <= n; i++) cin >> v, dp[i] += v;
    for (int i = 1; i <= n; i++) cin >> v, dp[i] -= v;
    for (int i = 1; i < n; i++) {
        cin >> u >> v;
        l[u].emplace_back(v);
        l[v].emplace_back(u);
    }
    vis[p] = 1;
    dfs(p);
    cout << -f(p, 0);
}
