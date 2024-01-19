#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

vector<int> p;

int f(int v) {
    if (p[v] == v) return v;
    return p[v] = f(p[v]);
}

bool u(int x, int y) {
    x = f(x);
    y = f(y);
    if (x == y) return false;
    p[min(x, y)] = max(x, y);
    return true;
}

double dist(pair<double, double> a, pair<double, double> b) {
    return sqrt(pow(a.first - b.first, 2) + pow(a.second - b.second, 2));
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    cout.precision(3);
    int n;
    double x, y, rs = 0;
    vector<pair<double, double>> m;
    vector<tuple<double, int, int>> t;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        m.emplace_back(x, y);
    }
    for (int i = 0; i < n; i++) p.emplace_back(i);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            t.emplace_back(dist(m[i], m[j]), i, j);
        }
    }
    sort(t.begin(), t.end());
    for (auto i: t) {
        auto [w, x1, y1] = i;
        if (u(x1, y1)) rs += w;
    }
    cout << rs;
}
