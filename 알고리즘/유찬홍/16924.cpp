#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n, m, d[] = {0, 1, 0, -1};
    vector<tuple<int, int, int>> p;
    char a[101][101], b[101][101];
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == '*') {
                int l = 1;
                while (true) {
                    int c = 0;
                    for (int k = 0; k < 4; k++) {
                        int x = i + (d[k] ? d[k] * l : 0), y = j + (d[3 - k] ? d[3 - k] * l : 0);
                        if (x >= 0 && x < n && y >= 0 && y < m && a[x][y] == '*') c++;
                    }
                    if (c == 4) l++;
                    else break;
                }
                if (l > 1) {
                    b[i][j] = '*';
                    p.emplace_back(i + 1, j + 1, l - 1);
                }
                for (int k = 1; k < l; k++) {
                    for (int o = 0; o < 4; o++) {
                        int x = i + (d[o] ? d[o] * k : 0), y = j + (d[3 - o] ? d[3 - o] * k : 0);
                        b[x][y] = '*';
                    }
                }
            } else b[i][j] = '.';
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] != b[i][j]) {
                cout << -1;
                return 0;
            }
        }
    }
    cout << p.size();
    for (auto [i, j, k]: p) {
        cout << "\n" << i << " " << j << " " << k;
    }
}
