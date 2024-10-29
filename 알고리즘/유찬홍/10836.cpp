#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int m, n, a[1402] = {};
    string r;
    cin >> m >> n;
    while (n--) {
        int b, c, d;
        cin >> b >> c >> d;
        a[b]++;
        a[b + c]++;
    }
    for (int i = 0; i < m * 2; i++) a[i + 1] += a[i]++;
    for (int i = m; i < m * 2; i++) r += to_string(a[i - 1]) + " ";
    r += "\n";
    for (int i = 1; i < m; i++) {
        r += to_string(a[m - i - 1]) + " ";
        for (int j = m + 1; j < m * 2; j++) r += to_string(a[j - 1]) + " ";
        r += "\n";
    }
    cout << r;
}
