#include <iostream>
#include <vector>

using namespace std;

bool vis[1000001];
int dp[1000001][2];
vector<int> l[1000001];

int f(int v, int w, int p) {
    if (vis[v]) return dp[v][w];
    vis[v] = true;
    for (int i: l[v]) {
        if (i == p) continue;
        dp[v][0] += f(i, 1, v);
        dp[v][1] += min(f(i, 0, v), f(i, 1, v));
    }
    dp[v][1]++;
    return dp[v][w];
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n;
    cin >> n;
    for (int i = 1, a, b; i < n; i++) {
        cin >> a >> b;
        l[a].emplace_back(b);
        l[b].emplace_back(a);
    }
    cout << min(f(1, 0, 0), f(1, 1, 0));
}
