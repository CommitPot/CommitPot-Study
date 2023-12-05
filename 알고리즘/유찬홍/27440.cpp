#include <iostream>
#include <queue>
#include <map>

using namespace std;
typedef long long int ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    queue<ll> q;
    map<ll, ll> m;
    ll n;
    cin >> n;
    m[n] = 0;
    q.emplace(n);
    while (!q.empty()) {
        ll x = q.front();
        if (x == 1) {
            cout << m[1];
            return 0;
        }
        q.pop();
        if (x % 3 == 0 && m.find(x / 3) == m.end()) {
            q.push(x / 3);
            m[x / 3] = m[x] + 1;
        }
        if (x % 2 == 0 && m.find(x / 2) == m.end()) {
            q.push(x / 2);
            m[x / 2] = m[x] + 1;
        }
        if (m.find(x - 1) == m.end()) {
            q.push(x - 1);
            m[x - 1] = m[x] + 1;
        }
    }
}
