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
    int n, m, k, a, b, rs = 0, cnt = 0;
    vector<tuple<int, int, int>> q;
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++) {
        cin >> a >> b;
        q.emplace_back(i, a, b);
    }
    for (int i = 0; i < k; i++) {
        sort(q.begin(), q.end());
        for (int j = 0; j <= n; j++) p.push_back(j);
        for (int j = 0; j < m - i; j++) {
            auto [w, x, y] = q[j];
            x = f(x), y = f(y);
            if (x == y) continue;
            cnt++;
            p[max(x, y)] = min(x, y);
            rs += w;
        }
        get<0>(q[0]) = 1e9;
        get<1>(q[0]) = 1e9;
        get<2>(q[0]) = 1e9;
        cout << ("%d", cnt == n - 1 ? rs : 0) << " ";
        rs = 0;
        cnt = 0;
        p.clear();
    }
}
