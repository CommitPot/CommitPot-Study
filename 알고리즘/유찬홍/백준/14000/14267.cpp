#include <iostream>
#include <vector>

using namespace std;

vector<int> l[100001], dp;

void dfs(int v, int c) {
    dp[c] += dp[v];
    for (int i: l[c]) {
        dfs(c, i);
    }
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n, m, a;
    cin >> n >> m;
    dp.assign(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> a;
        if (i == 1) continue;
        l[a].emplace_back(i);
    }
    while (m--) {
        cin >> a >> n;
        dp[a] += n;
    }
    for (int i: l[1]) dfs(1, i);
    int len = dp.size();
    for (int i = 1; i < len; i++) {
        cout << dp[i] << " ";
    }
}
