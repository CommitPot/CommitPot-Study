#include <iostream>
#include <vector>
#include <algorithm>
#include <memory.h>

using namespace std;

vector<pair<int, int>> l[10001];
bool vis[10001];
int rs = 0, c1 = 0;

void dfs(int x, int c) {
    if (c > c1) {
        c1 = c;
        rs = x;
    }
    for (auto i: l[x]) {
        if (!vis[i.first]) {
            vis[i.first] = true;
            dfs(i.first, c + i.second);
        }
    }
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int a = 0, b, c;
    while (cin >> a >> b >> c) {
        l[a].emplace_back(b, c);
        l[b].emplace_back(a, c);
    }
    vis[a] = true;
    dfs(a, 0);
    memset(vis, 0, sizeof(vis));
    c1 = 0;
    vis[rs] = true;
    dfs(rs, 0);
    cout << c1;
}
