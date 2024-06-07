#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int p[201];

int f(int v) { return p[v] = p[v] == v ? v : f(p[v]); }

bool u(int x, int y) {
    x = f(x), y = f(y);
    if (x == y) return false;
    p[max(x, y)] = min(x, y);
    return true;
}

int main() {
    int n, s = 0;
    vector<tuple<int, int, int>> l;
    cin >> n;
    for (int i = 1; i <= n; i++) p[i] = i;
    for (int i = 1; i <= n; i++) {
        for (int j = 1, a; j <= n; j++) {
            cin >> a;
            if (i < j) {
                if (a < 0) u(i, j), s += -a;
                l.emplace_back(a, i, j);
            }
        }
    }
    sort(l.begin(), l.end());
    vector<pair<int, int>> r;
    for (auto [a, b, c]: l) {
        if (u(b, c)) {
            s += a;
            r.emplace_back(b, c);
        }
    }
    cout << s << " " << r.size() << "\n";
    for (auto [a, b]: r) {
        cout << a << " " << b << "\n";
    }
}
