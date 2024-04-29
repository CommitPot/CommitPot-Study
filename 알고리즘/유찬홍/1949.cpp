#include <iostream>
#include <vector>

using namespace std;
int dp[10001][2];
bool vis[10001];
vector<int> l[10001];

int f(int v, bool w, int p) {
    if (vis[v]) return dp[v][w];
    vis[v] = true;
    for (int i: l[v]) {
        if (i == p) continue;
        dp[v][0] += max(f(i, true, v), f(i, false, v));
        dp[v][1] += f(i, false, v);
    }
    return dp[v][w];
}


int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> dp[i][1];
    for (int i = 1, a, b; i < n; i++) {
        cin >> a >> b;
        l[a].emplace_back(b);
        l[b].emplace_back(a);
    }
    cout << max(f(1, true, 0), f(1, false, 0));
}
