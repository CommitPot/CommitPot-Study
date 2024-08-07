#include <algorithm>
#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n, m, a[1048577];
    string r;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    cin >> m;
    int d = n / m;
    for (int i = 0; i < n; i += d) sort(a + i, a + i + d);
    for (int i = 0; i < n; i++) r += to_string(a[i]) + " ";
    cout << r;
}
