#include <iostream>
#include <algorithm>
#include <cmath>

#define ll long long

using namespace std;

pair<ll, ll> f(ll w, const string &s, int l, ll x, ll y) {
    if (w == 1) return {x, y};
    if (s[l] == '1') return f(w / 2, s, l + 1, x, y + w / 2);
    if (s[l] == '2') return f(w / 2, s, l + 1, x, y);
    if (s[l] == '3') return f(w / 2, s, l + 1, x + w / 2, y);
    return f(w / 2, s, l + 1, x + w / 2, y + w / 2);
}

string g(ll w, const string &s, ll x, ll y) {
    if (x < 0 || x >= w || y < 0 || y >= w) return "-1";
    if (w == 1) return s;
    if (x < w / 2 && y < w / 2) return g(w / 2, s + '2', x, y);
    if (x < w / 2 && y >= w / 2) return g(w / 2, s + '1', x, y - w / 2);
    if (x >= w / 2 && y < w / 2) return g(w / 2, s + '3', x - w / 2, y);
    return g(w / 2, s + '4', x - w / 2, y - w / 2);
}


int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    ll d, a, b;
    string s;
    cin >> d >> s >> a >> b;
    auto c = f(pow(2, d), s, 0, 0, 0);
    cout << g(pow(2, d), "", c.first - b, a + c.second);
}
