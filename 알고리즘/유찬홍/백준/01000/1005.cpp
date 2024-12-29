#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t, n, k, a, b, w;
    queue<pair<int, int>> q;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        vector<int> l[1001], kv, dp(n + 1, 0), ind(n + 1, 0);
        for (int i = 0; i < n; i++) cin >> kv.emplace_back();
        while (k--) {
            cin >> a >> b;
            l[a].emplace_back(b);
            ind[b]++;
        }
        cin >> w;
        for (int i = 1; i <= n; i++) if (!ind[i]) q.emplace(i, 1), dp[i] = kv[i - 1];
        while (!q.empty()) {
            auto [v, p] = q.front();
            q.pop();
            for (int i: l[v]) {
                dp[i] = max(dp[i], dp[v] + kv[i - 1]);
                if (!--ind[i]) {
                    q.emplace(i, p + 1);
                }
            }
        }
        cout << dp[w] << "\n";
    }
}
