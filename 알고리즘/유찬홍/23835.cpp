#include <iostream>
#include <vector>

using namespace std;
vector<int> vis(1001, 0), vis1(1001, 0);
vector<int> l[1001];

void dfs(int v, int c, int d) {
    if (v == c) {
        int x = vis1[v];
        vis[v] += d--;
        while (x != -1) {
            vis[x] += d--;
            x = vis1[x];
        }
        return;
    }
    for (int i: l[v]) {
        if (!vis1[i]) {
            vis1[i] = v;
            dfs(i, c, d + 1);
        }
    }
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n, a, b, c;
    cin >> n;
    while (--n) {
        cin >> a >> b;
        l[a].emplace_back(b);
        l[b].emplace_back(a);
    }
    cin >> n;
    while (n--) {
        cin >> a;
        if (a == 1) {
            cin >> b >> c;
            vis1[b] = -1;
            dfs(b, c, 0);
            vis1.assign(1001, 0);
        } else {
            cin >> b;
            cout << vis[b] << "\n";
        }
    }
}
