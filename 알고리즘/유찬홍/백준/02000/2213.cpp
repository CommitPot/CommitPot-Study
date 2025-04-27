#include <cstdio>
#include <algorithm>

using namespace std;

int dp[10001][2], vis[10001];
vector<int> r, l[10001], rs;

int f(int v, int w, int p) {
    if (dp[v][w] > -1) return dp[v][w];
    dp[v][w] = w ? r[v] : 0;
    for (int i : l[v]) {
        if (i == p) continue;
        if (w) dp[v][w] += f(i, 0, v);
        else dp[v][w] += max(f(i, 0, v), f(i, 1, v));
    }
    return dp[v][w];
}

void g(int v, int p) {
    if (dp[v][1] > dp[v][0] && !vis[p]) {
        rs.emplace_back(v);
        vis[v] = 1;
    }
    for (int i : l[v]) {
        if (i == p) continue;
        g(i, v);
    }
}

int main() {
    int n;
    scanf("%d", &n);
    r.emplace_back(0);
    for (int i = 0, a; i < n; i++) {
        scanf("%d", &a);
        r.emplace_back(a);
        dp[i + 1][0] = dp[i + 1][1] = -1;
    }
    for (int i = 1, a, b; i < n; i++) {
        scanf("%d %d", &a, &b);
        l[a].emplace_back(b);
        l[b].emplace_back(a);
    }
    printf("%d\n", max(f(1, 0, 0), f(1, 1, 0)));
    g(1, 0);
    sort(rs.begin(), rs.end());
    for (int i : rs) printf("%d ", i);
}
