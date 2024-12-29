#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n, a, b;
    cin >> n;
    pair<int, int> l[2000001];
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        l[i] = {a, 1};
        l[i + n] = {b, -1};
    }
    sort(l, l + n * 2);
    int r = 0, s = 0;
    for (int i = 0; i < n * 2; i++) {
        r += l[i].second;
        s = max(s, r);
    }
    cout << s;
}
