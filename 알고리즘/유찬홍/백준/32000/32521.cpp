#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool t[100005];
vector<int> l[100001];
int rs = 0, k;

int f(int p, int v) {
    if (l[v].size() == 1 && l[v][0] == p) return t[v];
    int r = t[v];
    vector<int> m;
    for (int x: l[v]) {
        if (p == x) continue;
        m.emplace_back(f(v, x));
    }
    sort(m.begin(), m.end());
    for (int i: m) {
        if (i + r > k) rs++;
        else r += i;
    }
    return r;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> t[i];
    for (int i = 1, a, b; i < n; i++) {
        cin >> a >> b;
        l[a].emplace_back(b);
        l[b].emplace_back(a);
    }
    f(0, 1);
    cout << rs;
}
