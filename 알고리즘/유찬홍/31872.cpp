#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n, k, l[100001];
    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> l[i];
    sort(l, l + n);
    for (int i = 0, j = 0; i < n; i++) {
        int t = l[i] - j;
        j = l[i];
        l[i] = t;
    }
    sort(l, l + n, greater<int>());
    int s = 0;
    for (int i = k; i < n; i++) s += l[i];
    cout << s;
}
