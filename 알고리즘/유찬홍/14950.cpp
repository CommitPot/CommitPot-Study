#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> p;

int f(int x) {
    return p[x] = p[x] == x ? x : f(p[x]);
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n, m, t, a, b, c, cnt = 0, rs = 0;
    vector<tuple<int, int, int>> q;
    cin >> n >> m >> t;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        q.emplace_back(c, a, b);
    }
    sort(q.begin(), q.end());
    for (int i = 0; i <= n; i++) p.push_back(i);
    for (auto [w, x, y]: q) {
        x = f(x);
        y = f(y);
        if (x == y) continue;
        p[max(x, y)] = min(x, y);
        rs += w + cnt++ * t;
    }
    cout << rs;
}
