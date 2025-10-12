#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> m[100001];
int t[100001];

void g(int v, int p, int l) {
    t[v] = l;
    for (int i: m[v]) {
        if (i == p) continue;
        g(i, v, l + 1);
    }
}

int f(int v, int p, int l) {
    int k = l;
    for (int i: m[v]) {
        if (i == p) continue;
        k = max(k, f(i, v, l + 1));
    }
    return k;
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int c, n;
    cin >> c;
    while (c--) {
        cin >> n;
        for (int i = 0; i < n; i++) m[i].clear(), t[i] = 0;
        for (int i = 1, a, b; i < n; i++) {
            cin >> a >> b;
            m[a].emplace_back(b);
            m[b].emplace_back(a);
        }
        g(0, -1, 1);
        int v = 0;
        for (int i = 0, j = 0; i < n; i++) {
            if (j < t[i]) j = t[i], v = i;
        }
        cout << f(v, -1, 1) / 2 << '\n';
    }
}
