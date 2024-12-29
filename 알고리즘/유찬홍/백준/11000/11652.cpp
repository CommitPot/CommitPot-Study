#include <iostream>
#include <map>

typedef long long int ll;
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    map<ll, ll> m;
    ll n, a;
    cin >> n;
    while (n--) {
        cin >> a;
        if (m[a] > 0) m[a]++;
        else m[a] = 1;
    }
    for (auto i: m) {
        if (n < i.second) {
            a = i.first;
            n = i.second;
        }
    }
    cout << a;
}
