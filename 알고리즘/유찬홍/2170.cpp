#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n;
    cin >> n;
    pair<int, int> l[1000000];
    for (int i = 0, a, b; i < n; i++) {
        cin >> a >> b;
        l[i] = {a, b};
    }
    sort(l, l + n);
    int s = -1e9 - 1, e = -1e9 - 1, r = 0;
    for (auto [a, b]: l) {
        if (e < a) {
            r += e - s;
            s = a, e = b;
        } else if (e < b) e = b;
    }
    cout << r + (e - s);
}
