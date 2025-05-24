#include <queue>
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
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
            int f = stoi(e);
            if (m.find(f) == m.end()) {
                m[f] = m[a] + 1;
                q.emplace(f, d[b][i] - 48);
            }
        }
    }
    string str;
    int r = 0;
    for (int i = 0; i < 9; i++) {
        char c;
        cin >> c;
        if (c == 'X') c = '9', r = i;
        str += c;
    }
    int k = stoi(str);
    cout << m[k] - 1 << '\n';
    while (m[k] > 1) {
        for (int i = 0; d[r][i]; i++) {
            string e = to_string(k);
            swap(e[r], e[d[r][i] - 48]);
            int f = stoi(e);
            if (m[f] == m[k] - 1) {
                k = f;
                cout << str[d[r][i] - 48] << ' ';
                swap(str[r], str[d[r][i] - 48]);
                r = d[r][i] - 48;
                break;
            }
        }
    }
}
