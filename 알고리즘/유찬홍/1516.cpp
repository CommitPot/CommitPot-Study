#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n, a;
    cin >> n;
    queue<pair<int, int>> q;
    vector<int> time, graph[n + 1], ind(n + 1, 0), dp(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> time.emplace_back();
        cin >> a;
        while (a != -1) {
            graph[a].emplace_back(i);
            ind[i]++;
            cin >> a;
        }
    }
    for (int i = 1; i <= n; i++) if (!ind[i]) q.emplace(i, 1), dp[i] = time[i - 1];
    while (!q.empty()) {
        auto [v, d] = q.front();
        q.pop();
        for (int i: graph[v]) {
            dp[i] = max(dp[i], dp[v] + time[i - 1]);
            if (!--ind[i]) q.emplace(i, d + 1);
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << dp[i] << "\n";
    }
}
