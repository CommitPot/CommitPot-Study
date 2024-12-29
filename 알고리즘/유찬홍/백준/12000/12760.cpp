#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n, m, a[101][101], b[101] = {0};
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
        sort(a[i], a[i] + m);
    }
    for (int i = 0; i < m; i++) {
        vector<int> l;
        int v = 0;
        for (int j = 0; j < n; j++) {
            if (v == a[j][i]) l.emplace_back(j);
            else if (v < a[j][i]) {
                v = a[j][i];
                l.clear();
                l.emplace_back(j);
            }
        }
        for (int j: l) b[j]++;
    }
    vector<int> l;
    int v = 0;
    for (int i = 0; i < n; i++) {
        if (v == b[i]) l.emplace_back(i);
        else if (v < b[i]) {
            v = b[i];
            l.clear();
            l.emplace_back(i);
        }
    }
    for (int i: l) {
        cout << i + 1 << " ";
    }
}
