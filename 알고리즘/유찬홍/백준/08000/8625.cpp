#include <set>
#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    long long n, k, a, r;
    set<long long> s;
    cin >> n >> k;
    while (n--) {
        cin >> a;
        s.insert(a);
    }
    r = k;
    while (s.find(r) != s.end()) r += k;
    cout << r;
}
