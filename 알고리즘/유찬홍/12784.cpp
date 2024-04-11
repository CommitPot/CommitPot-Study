#include <iostream>
#include <vector>

using namespace std;

bool vis[1001];
int dp[1001];
vector<pair<int, int>> l[1001];

int f(int v, int w) {
    if (vis[v]) return dp[v];
    vis[v] = true;
    int s = 0;
    for (auto [i, j]: l[v]) s += f(i, j);
    if (!s) return dp[v] = w;
    return dp[v] = min(s, w);
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t, n, m, a, b, c;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        while (m--) {
            cin >> a >> b >> c;
            l[a].emplace_back(b, c);
            l[b].emplace_back(a, c);
        }
        int x = f(1, 1e9);
        cout << (x == 1e9 ? 0 : x) << "\n";
        for (int i = 1; i <= n; i++) dp[i] = vis[i] = false, l[i].clear();
    }
}
