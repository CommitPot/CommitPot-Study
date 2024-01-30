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
    int n, m, a, b, rs = 0;
    priority_queue<tuple<int, int, int>> q;
    vector<pair<int, int>> k;
    cin >> n >> m;
    for (int i = 0; i <= n; i++) p.emplace_back(i);
    while (m--) {
        cin >> a >> b;
        a = f(a), b = f(b);
        p[max(a, b)] = min(a, b);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a;
            if (i != 1 && i < j) {
                q.emplace(-a, i, j);
            }
        }
    }
    while (!q.empty()) {
        if (k.size() == n - 2) break;
        auto [w, x, y] = q.top();
        q.pop();
        a = f(x), b = f(y);
        if (a == b) continue;
        k.emplace_back(x, y);
        p[max(a, b)] = min(a, b), rs += -w;
    }
    cout << rs << " " << k.size() << "\n";
    for (auto [x, y]: k) {
        cout << x << " " << y << "\n";
    }
}
