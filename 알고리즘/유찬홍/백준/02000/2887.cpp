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
    int n, a, b, c, rs = 0;
    vector<pair<int, int>> t[3];
    vector<tuple<int, int, int>> q;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a >> b >> c;
        t[0].emplace_back(a, i);
        t[1].emplace_back(b, i);
        t[2].emplace_back(c, i);
        p.emplace_back(i);
    }
    for (auto &i: t) {
        sort(i.begin(), i.end());
        for (int j = 0; j < n - 1; j++) {
            q.emplace_back(abs(i[j].first - i[j + 1].first), i[j].second, i[j + 1].second);
        }
    }
    sort(q.begin(), q.end());
    for (auto [w, x, y]: q) {
        x = f(x), y = f(y);
        if (x == y) continue;
        p[max(x, y)] = min(x, y);
        rs += w;
    }
    cout << rs;
}
