#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n;
    cin >> n;
    pair<int, int> l[2000000];
    for (int i = 0, a, b; i < n; i++) {
        cin >> a >> b;
        l[i] = {a, 1};
        l[i + n] = {b, -1};
    }
    int e = 0, u, r = 0;
    sort(l, l + n * 2);
    for (auto [v, w]: l) {
        if (!e) u = v;
        e += w;
        if (!e) r += v - u;
    }
    cout << r;
}
