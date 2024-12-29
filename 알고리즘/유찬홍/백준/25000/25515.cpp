#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

vector<ll> l[100000], dp;

ll f(ll v) {
    for (ll i: l[v]) {
        ll t = f(i);
        dp[v] += t > 0 ? t : 0;
    }
    return dp[v];
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n, a, b;
    cin >> n;
    dp.assign(n, 0);
    while (--n) {
        cin >> a >> b;
        l[a].emplace_back(b);
    }
    for (ll &i: dp) cin >> i;
    cout << f(0);
}
