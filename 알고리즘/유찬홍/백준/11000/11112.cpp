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
    int n;
    char d[9][5] = {"13", "024", "15", "046", "1357", "248", "37", "468", "57"};
    unordered_map<int, int> m;
    int s = 123456789;
    m[s] = 1;
    queue<pair<int, int>> q;
    q.emplace(s, 8);
    while (!q.empty()) {
        auto [a, b] = q.front();
        q.pop();
        for (int i = 0; d[b][i]; i++) {
            string e = to_string(a);
            swap(e[b], e[d[b][i] - 48]);
            int f1 = f(e, 8);
            if (m.find(f1) == m.end()) {
                m[f1] = m[a] + 1;
                q.emplace(f1, d[b][i] - 48);
            }
        }
    }
    cin >> n;
    string o;
    while (n--) {
        s = 0;
        for (int i = 0; i < 3; i++) {
            string str;
            cin >> str;
            for (char j: str) {
                s = s * 10 + (j == '#' ? 9 : j - 48);
            }
        }
        if (m.find(s) == m.end()) o += "impossible";
        else o += to_string(m[s] - 1);
        o += "\n";
    }
    cout << o;
}
