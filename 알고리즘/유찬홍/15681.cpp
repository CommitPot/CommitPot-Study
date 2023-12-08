#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int dp[100001] = {1, 1};
bool vis[100001];
vector<int> arr[100001];

int dfs(int x) {
    if (vis[x]) return dp[x];
    vis[x] = true;
    for (int i: arr[x]) if (!vis[i]) dp[x] += dfs(i);
    return dp[x];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, r, q, a, b;
    cin >> n >> r >> q;
    for (int i = 2; i <= n; i++) {
        cin >> a >> b;
        arr[a].emplace_back(b);
        arr[b].emplace_back(a);
        dp[i] = 1;
    }
    dfs(r);
    while (q--) cin >> n, cout << dp[n] << "\n";
}
