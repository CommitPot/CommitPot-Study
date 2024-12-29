#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int p[1001];

int f(int x) { return p[x] = p[x] == x ? x : f(p[x]); }

bool u(int x, int y) {
    if (f(x) == f(y)) return false;
    p[min(f(x), f(y))] = max(f(x), f(y));
    return true;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n, m;
    pair<int, int> l[1001];
    cin >> n >> m;
    for (int i = 1, a, b; i <= n; i++) {
        p[i] = i;
        cin >> a >> b;
        l[i] = {a, b};
    }
    for (int i = 0, a, b; i < m; i++) {
        cin >> a >> b;
        u(a, b);
    }
    vector<tuple<double, int, int>> k;
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            k.emplace_back(sqrt(pow(l[i].first - l[j].first, 2) + pow(l[i].second - l[j].second, 2)), i, j);
        }
    }
    sort(k.begin(), k.end());
    double s = 0;
    for (auto [w, x, y]: k) {
        if (u(x, y)) s += w, m++;
    }
    cout << fixed;
    cout.precision(2);
    cout << s;
}
