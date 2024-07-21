#include <cstdio>
#include <vector>
#include <queue>

using namespace std;
int vis[3001];
vector<int> l[3001];

int c(int v, int p) {
    vis[v] = 1;
    int b = 0;
    for (int i: l[v]) {
        if (!vis[i]) { if (c(i, v) == 1) b++; }
        else if (i != p) b++;
    }
    return vis[v] = b;
}

int main() {
    int n;
    queue<int> q;
    scanf("%d", &n);
    for (int i = 0, a, b; i < n; i++) {
        scanf("%d %d", &a, &b);
        l[a].emplace_back(b);
        l[b].emplace_back(a);
    }
    c(1, 0);
    for (int i = 1; i <= n; i++) if (vis[i]) vis[i] = 1, q.emplace(i);
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int i: l[v]) {
            if (!vis[i]) {
                vis[i] = vis[v] + 1;
                q.emplace(i);
            }
        }
    }
    for (int i = 1; i <= n; i++) printf("%d ", vis[i] - 1);
}
