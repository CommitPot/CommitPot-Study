#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <queue>

using namespace std;

int f(const string &a, int x) {
    int b = a[x] - 48;
    if (!x) return b;
    return f(a, x - 1) * 10 + b;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int w;
    char d[9][5] = {"13", "024", "15", "046", "1357", "248", "37", "468", "57"};
    unordered_map<int, int> m;
    int s = 0;
    for (int i = 0, a; i < 9; i++) {
        cin >> a;
        s = s * 10 + a;
        if (!a) w = i;
    }
    m[s] = 1;
    queue<pair<int, int>> q;
    q.emplace(s, w);
    while (!q.empty()) {
        auto [a, b] = q.front();
        q.pop();
        if (a == 123456780) {
            cout << m[a] - 1;
            return 0;
        }
        for (int i = 0; d[b][i]; i++) {
            string e;
            if (a / 100000000 == 0) e += "0";
            e += to_string(a);
            swap(e[b], e[d[b][i] - 48]);
            int f1 = f(e, 8);
            if (m.find(f1) == m.end()) {
                m[f1] = m[a] + 1;
                q.emplace(f1, d[b][i] - 48);
            }
        }
    }
    cout << -1;
}
