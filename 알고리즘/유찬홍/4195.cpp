#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
vector<int> p;

int f(int x) {
    return p[x] = p[x] == x ? x : f(p[x]);
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t, n;
    string a, b;
    cin >> t;
    while (t--) {
        int c = 1;
        unordered_map<string, int> m;
        unordered_map<int, int> m1;
        p.assign(1, 0);
        cin >> n;
        while (n--) {
            cin >> a >> b;
            if (m.find(a) == m.end()) p.emplace_back(c), m[a] = c, m1[c++] = 1;
            if (m.find(b) == m.end()) p.emplace_back(c), m[b] = c, m1[c++] = 1;
            int d = f(m[a]), e = f(m[b]);
            if (d != e) p[max(d, e)] = min(d, e), m1[min(d, e)] += m1[max(d, e)];
            cout << m1[min(d, e)] << "\n";
        }
    }
}
