#include <tuple>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int f(int x, int *p) {
    return p[x] == x ? x : p[x] = f(p[x], p);
}

bool u(int a, int b, int *p) {
    a = f(a, p), b = f(b, p);
    return a == b ? false : p[b] = a;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int n, p;
    int c[10001], pa[10001];
    vector<tuple<int, int, int> > ed;

    cin >> n >> p;
    long long r = 1e5;
    for (int i = 1; i <= n; i++) {
        cin >> c[i], pa[i] = i;
        if (c[i] < r) r = c[i];
    }
    for (int i = 0; i < p; i++) {
        int s, e, l;
        cin >> s >> e >> l;
        ed.emplace_back(l * 2 + c[s] + c[e], s, e);
    }
    sort(ed.begin(), ed.end());

    for (auto [w, s, e]: ed) {
        if (u(s, e, pa)) {
            r += w;
            if (--n == 1) break;
        }
    }
    cout << r;
}
