#include <algorithm>
#include <iostream>
#include <map>
#include <set>

using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int n, m, a[51], c[51], d[51] = {}, r = 2;
    string b;
    map<int, int> p;
    set<string> q;
    cin >> n >> m;
    for (int i = 0; i < m; i++) cin >> a[i];
    copy(a, a + m, c);
    sort(c, c + m);
    cin >> b;
    p[c[0]] = 1;
    for (int i = 1; i < m; i++) {
        if (c[i] != c[i - 1]) p[c[i]] = r++;
    }
    string e(--r, 48);
    q.insert(e);
    for (int i = 0; i < m; i++) {
        string s;
        d[p[a[i]]] += b[i] == '+' ? 1 : -1;
        for (int j = 1; j <= r; j++) s += to_string(d[j]);
        if (q.find(s) != q.end()) {
            cout << 0;
            return 0;
        }
        q.insert(s);
    }
    cout << 1;
}
