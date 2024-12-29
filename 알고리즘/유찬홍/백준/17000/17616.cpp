#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n, m, x, a, b, rs1 = 0, rs = 0;
    queue<int> q;
    cin >> n >> m >> x;
    bool vis[n + 1];
    memset(vis, 0, sizeof(vis));
    vector<int> l[n + 1], l1[n + 1];
    while (m--) {
        cin >> a >> b;
        l[a].emplace_back(b);
        l1[b].emplace_back(a);
    }
    q.emplace(x);
    vis[x] = true;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int i: l[v]) {
            if (!vis[i]) {
                vis[i] = true;
                q.emplace(i);
                rs1++;
            }
        }
    }
    memset(vis, 0, sizeof(vis));
    vis[x] = true;
    q.emplace(x);
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int i: l1[v]) {
            if (!vis[i]) {
                vis[i] = true;
                q.emplace(i);
                rs++;
            }
        }
    }
    cout << rs + 1 << " " << n - rs1;
}
