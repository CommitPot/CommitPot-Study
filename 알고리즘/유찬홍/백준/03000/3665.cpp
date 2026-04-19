#include <set>
#include <iostream>
#include <algorithm>

using namespace std;

typedef pair<int, int> pi;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n, m, s = 0, l[501][501] = {};
        pi p[501] = {};
        set<int> st;
        cin >> n;
        for (int i = 0, j; i < n; i++) {
            cin >> j;
            st.insert(j);
            for (int k = 1; k <= n; k++) {
                if (st.find(k) == st.end()) l[k][j] = 1;
            }
        }
        cin >> m;
        for (int i = 0, j, k; i < m; i++) {
            cin >> j >> k;
            swap(l[j][k], l[k][j]);
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) p[i].first += l[i][j];
            p[i] = {n - p[i].first, i};
        }
        st.clear();
        for (int i = 1; i <= n; i++) {
            if (st.find(p[i].first) != st.end()) s = 1;
            st.insert(p[i].first);
        }
        if (s) cout << "IMPOSSIBLE\n";
        else {
            sort(p + 1, p + n + 1, [](pi x, pi y) {
                return x.first > y.first;
            });
            string r;
            for (int i = 1; i <= n; i++) {
                r += to_string(p[i].second) + " ";
            }
            cout << r << "\n";
        }
    }
}
