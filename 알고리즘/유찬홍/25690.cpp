#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

vector<int> l[100001];
ll dp[100001][2];
bool vis[100001];

ll f(int v, bool w) {
    if (vis[v]) return dp[v][w];
    vis[v] = true;
    for (int i: l[v]) {
        dp[v][0] += min(f(i, true), f(i, false));
        dp[v][1] += f(i, false);
    }
    return dp[v][w];
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n, a, b;
    cin >> n;
    for (int i = 1; i < n; i++) {
        cin >> a >> b;
        l[a].emplace_back(b);
    }
    for (int i = 0; i < n; i++) cin >> dp[i][0] >> dp[i][1], vis[i] = false;
    cout << min(f(0, true), f(0, false));
}
