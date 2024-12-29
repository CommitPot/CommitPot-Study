#include <iostream>
#include <vector>

using namespace std;
int cnt = 0;
vector<int> l(1, 0), vis, tree[200001];

void dfs(int v, int c) {
    if (c != l[v] && l[v]) {
        cnt++;
        c = l[v];
    }
    for (int i: tree[v]) {
        if (vis[i] == -1) {
            vis[i] = c;
            dfs(i, c);
        }
    }
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n, a, b;
    cin >> n;
    vis.assign(n + 1, -1);
    for (int i = 0; i < n; i++) cin >> l.emplace_back();
    while (--n) {
        cin >> a >> b;
        tree[a].emplace_back(b);
        tree[b].emplace_back(a);
    }
    if (l[1] > 0) cnt++;
    vis[1] = l[1];
    dfs(1, l[1]);
    cout << cnt;
}
