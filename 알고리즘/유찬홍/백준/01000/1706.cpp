#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n, m;
    string map[21];
    vector<string> l;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> map[i];
    }
    for (int i = 0; i < n; i++) {
        string a;
        for (int j = 0; j < m; j++) {
            if (map[i][j] == '#') {
                if (a.length() > 1) l.emplace_back(a);
                a.clear();
            } else {
                a += map[i][j];
            }
        }
        if (a.length() > 1) l.emplace_back(a);
    }
    for (int i = 0; i < m; i++) {
        string a;
        for (int j = 0; j < n; j++) {
            if (map[j][i] == '#') {
                if (a.length() > 1) l.emplace_back(a);
                a.clear();
            } else {
                a += map[j][i];
            }
        }
        if (a.length() > 1) l.emplace_back(a);
    }
    sort(l.begin(), l.end());
    cout << l[0];
}
