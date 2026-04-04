#include <map>
#include <iostream>

using namespace std;

long long n, p, q;
map<long long, long long> m;

long long f(long long v) {
    if (m.find(v) != m.end()) return m[v];
    return m[v] = f(v / p) + f(v / q);
}


int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    cin >> n >> p >> q;
    m[0] = 1;
    cout << f(n);
}
