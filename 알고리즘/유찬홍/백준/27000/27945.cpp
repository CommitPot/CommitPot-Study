#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> p;

int f(int x) {
    return p[x] = p[x] == x ? x : f(p[x]);
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n, m, a, b, c, rs = 1;
    priority_queue<tuple<int, int, int>> q;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        q.emplace(-c, a, b);
    }
    for (int i = 0; i <= n; i++) p.emplace_back(i);
    while (!q.empty()) {
        auto [w, x, y] = q.top();
        q.pop();
        x = f(x), y = f(y);
        if (x == y) continue;
        if (rs != -w) break;
        p[max(x, y)] = min(x, y), rs++;
    }
    cout << rs;
}
