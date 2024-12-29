#include <iostream>
#include <queue>
#include <map>

using namespace std;

typedef long long int ll;
queue<pair<ll, string>> q;
map<ll, bool> m;

void push(ll x, const string &s) {
    if (!m[x]) {
        q.emplace(x, s);
        m[x] = true;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int s, t;
    cin >> s >> t;
    if (s == t) {
        cout << 0;
        return 0;
    }
    q.emplace(s, "");
    m[s] = true;
    while (!q.empty()) {
        auto [x, c] = q.front();
        if (x == t) {
            cout << c;
            return 0;
        }
        q.pop();
        push(x * x, c + '*');
        push(x * 2, c + '+');
        push(1, c + '/');
    }
    cout << -1;
}
