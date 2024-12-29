#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<int> p;

int f(int x) { return p[x] = p[x] == x ? x : f(p[x]); }

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    priority_queue<tuple<int, int, int>> q;
    vector<int> v(1, 0);
    int n, m, a, b, c, rs = 0;
    p.assign(1, 0);
    cin >> n >> m;
    while (m--) {
        cin >> a >> b >> c;
        q.emplace(-c, a, b);
    }
    for (int i = 1; i <= n; i++) {
        cin >> v.emplace_back();
        p.emplace_back(i);
    }
    while (!q.empty()) {
        auto [w, x, y] = q.top();
        q.pop();
        x = f(x), y = f(y);
        if (x == y) continue;
        if (v[x] > -w || v[y] > -w) {
            if (v[x] > v[y]) v[x] = -w, p[x] = y;
            else v[y] = -w, p[y] = x;
        }
    }
    for (int i: v) rs += i;
    cout << rs;
}
