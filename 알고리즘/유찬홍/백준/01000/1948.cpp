#include <queue>
#include <vector>
#include <iostream>

using namespace std;

vector<pair<int, int>> l[10001];
int dp[10001];

int f(int v) {
    if (dp[v] != -1) return dp[v];
    dp[v] = 0;
    for (auto [u, w]: l[v]) {
        dp[v] = max(f(u) + w, dp[v]);
    }
    return dp[v];
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n, m, s, e;
    queue<int> q;
    bool vis[10001] = {};
    cin >> n >> m;
    for (int i = 0, a, b, c; i < m; i++) {
        cin >> a >> b >> c;
        l[b].emplace_back(a, c);
    }
    for (int i = 1; i <= n; i++) dp[i] = -1;
    cin >> s >> e;
    int p = f(e), r = 0;
    q.emplace(e);
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        if (vis[v]) continue;
        vis[v] = true;
        for (auto [u, x]: l[v]) {
            if (dp[u] + x == dp[v]) q.emplace(u), r++;
        }
    }
    cout << p << '\n' << r;
}
