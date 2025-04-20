#include <vector>
#include <iostream>

using namespace std;

vector<int> l[100001];
int dp[100001][2];

int dfs(int x, int p, int w) {
    if (dp[x][w] > -1) return dp[x][w];
    dp[x][w] = w;
    for (auto i: l[x]) {
        if (i == p) continue;
        dp[x][w] += w ? min(dfs(i, x, 0), dfs(i, x, 1)) : dfs(i, x, 1);
    }
    return dp[x][w];
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int n, a, b;
    cin >> n;
    for (int i = 1; i < n; i++) {
        cin >> a >> b;
        l[a].push_back(b);
        l[b].push_back(a);
        dp[i][0] = dp[i][1] = -1;
    }
    dp[n][0] = dp[n][1] = -1;
    cout << min(dfs(1, 0, 0), dfs(1, 0, 1));
}
