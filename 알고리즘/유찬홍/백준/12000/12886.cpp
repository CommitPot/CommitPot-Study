#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int a, b, c, vis[1501][1501] = {};
    cin >> a >> b >> c;
    queue<tuple<int, int, int>> q;
    q.emplace(a, b, c);
    while (!q.empty()) {
        auto [x, y, z] = q.front();
        q.pop();
        if (x == y && y == z) {
            cout << 1;
            return 0;
        }
        a = min(x, y);
        b = max(x, y);
        if (b >= a && !vis[a + a][b - a]) {
            vis[a + a][b - a] = 1;
            q.emplace(a + a, b - a, z);
        }

        a = min(x, z);
        b = max(x, z);
        if (b >= a && !vis[a + a][b - a]) {
            vis[a + a][b - a] = 1;
            q.emplace(a + a, y, b - a);
        }

        a = min(y, z);
        b = max(y, z);
        if (b >= a && !vis[a + a][b - a]) {
            vis[a + a][b - a] = 1;
            q.emplace(x, a + a, b - a);
        }
    }
    cout << 0;
}
