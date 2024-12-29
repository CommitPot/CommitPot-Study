#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n, m, a, b, c, s[101][101];
    cin >> n >> m;
    vector<int> l[n + 1][n + 1];
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            l[i][j].emplace_back(i);
            s[i][j] = i == j ? 0 : 1e9;
        }
    }
    while (m--) {
        cin >> a >> b >> c;
        if (s[a][b] > c) s[a][b] = c;
    }
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (s[i][j] > s[i][k] + s[k][j]) {
                    vector<int> o;
                    for (int p: l[i][k]) o.emplace_back(p);
                    for (int p: l[k][j]) o.emplace_back(p);
                    l[i][j].clear();
                    for (int p: o) l[i][j].emplace_back(p);
                    s[i][j] = s[i][k] + s[k][j];
                }
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << (s[i][j] == 1e9 ? 0 : s[i][j]) << " ";
        }
        cout << "\n";
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j || s[i][j] == 1e9) cout << 0 << "\n";
            else {
                cout << l[i][j].size() + 1 << " ";
                for (int k: l[i][j]) cout << k << " ";
                cout << j << "\n";
            }
        }
    }
}
