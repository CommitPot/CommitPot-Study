#include <vector>
#include <iostream>

using namespace std;

vector<pair<int, int> > l[100001];
int q;

int f(int v, int p, int e) {
    if (v == e) return 1;
    int r = 0;
    for (auto [u, w]: l[v]) {
        if (u == p) continue;
        int x = f(u, v, e);
        if (x) r += w + x, q = max(q, w);
    }
    return r;
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n, s, e, a, b, c;
    cin >> n >> s >> e;
    while (--n) {
        cin >> a >> b >> c;
        l[a].emplace_back(b, c);
        l[b].emplace_back(a, c);
    }
    cout << f(s, 0, e) - 1 - q;
}
