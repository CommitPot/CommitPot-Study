#include <iostream>
#include <vector>

using namespace std;

bool vis[100001];
int dp[100001];
vector<pair<int, int>> l[100001];

int f(int v, int w) {
    if (vis[v]) return dp[v];
    vis[v] = true;
    int s = 0;
    for (auto [i, j]: l[v]) s += f(i, j);
    return dp[v] = s ? min(w, s) : w;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int a, b, c, n;
    cin >> n;
    for (int i = 1; i < n; i++) {
        cin >> a >> b >> c;
        l[a].emplace_back(b, c);
        l[b].emplace_back(a, c);
    }
    cout << f(1, 1e9);
}
