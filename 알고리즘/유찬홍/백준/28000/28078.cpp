#include <iostream>
#include <algorithm>
#include <deque>

using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n, r = 0, e[2] = {};
    char c;
    deque<char> q;
    string s;
    cin >> n;
    while (n--) {
        cin >> s;
        if (s == "push") {
            cin >> c;
            if (c == 'b' && (r == 3 || (r == 1 && !q.size()))) continue;
            q.emplace_back(c);
            e[c % 2]++;
        }
        if (s == "pop" && q.size()) {
            e[q.front() % 2]--;
            q.pop_front();
            if (r == 1) {
                while (q.size() && q.front() != 'w') {
                    q.pop_front();
                    e[0]--;
                }
            }
        }
        if (s == "rotate") {
            cin >> c;
            if (c == 'r') r = (r + 1) % 4;
            else r = (r + 3) % 4;
            if (r == 1) {
                while (q.size() && q.front() != 'w') {
                    q.pop_front();
                    e[0]--;
                }
            }
            if (r == 3) {
                while (q.size() && q.back() != 'w') {
                    q.pop_back();
                    e[0]--;
                }
            }
        }
        if (s == "count") {
            cin >> c;
            cout << e[c % 2] << '\n';
        }
    }
}
