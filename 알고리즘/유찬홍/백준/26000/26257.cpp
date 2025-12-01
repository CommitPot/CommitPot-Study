#include <iostream>
#include <set>

using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n, m, q, a[200001] = {};
    set<int> r;
    string s, rs;
    cin >> n >> m >> q;
    for (int i = 1, b; i <= m; i++) {
        cin >> b;
        a[i] = b;
    }
    for (int i = 0, b, c, d; i < q; i++) {
        cin >> s;
        if (s[0] == 's') cin >> b >> c, d = a[b], a[b] = a[c], a[c] = d;
        else if (s[0] == 'r') cin >> b, a[b] = 0;
        else cin >> b >> c, a[b] = a[c];
    }
    for (int i = 1; i <= m; i++) {
        if (a[i]) r.insert(a[i]);
    }
    for (auto i: r) rs += to_string(i) + "\n";
    cout << r.size() << "\n" << rs;
}
