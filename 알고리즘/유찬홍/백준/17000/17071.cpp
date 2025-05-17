#include <queue>
#include <iostream>

using namespace std;

int main() {
    int n, k, r = 1e9, vis[500001][2] = {};
    queue<pair<int, int>> q;
    cin >> n >> k;
    q.emplace(n, 0);
    vis[n][0] = 1;
    while (!q.empty()) {
        auto [v, w] = q.front();
        q.pop();
        w++;
        if (v < 500000 && !vis[v + 1][w % 2]) {
            vis[v + 1][w % 2] = vis[v][(w - 1) % 2] + 1;
            q.emplace(v + 1, w);
        }
        if (v && !vis[v - 1][w % 2]) {
            vis[v - 1][w % 2] = vis[v][(w - 1) % 2] + 1;
            q.emplace(v - 1, w);
        }
        if (v <= 250000 && !vis[v * 2][w % 2]) {
            vis[v * 2][w % 2] = vis[v][(w - 1) % 2] + 1;
            q.emplace(v * 2, w);
        }
    }
    for (int i = 0; i + k < 500001; i++) {
        k += i;
        for (int j = 0; j < 2; j++) {
            if (vis[k][j] && (i % 2 == (vis[k][j] - 1) % 2) && i >= vis[k][j] - 1) r = min(r, i);
        }
    }
    cout << (r == 1e9 ? -1 : r);
}
