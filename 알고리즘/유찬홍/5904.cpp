#include <iostream>

using namespace std;

char f(int n, int k, int t) {
    if (!n) {
        if (t == 1) return 'm';
        return 'o';
    }
    string a = " mo";
    for (int i = 0; i <= n; i++) a += 'o';
    int x = (k - n - 3) / 2;
    if (x >= t) return f(n - 1, x, t);
    if (x + n + 3 >= t) return a[t - x];
    return f(n - 1, x, t - x - n - 3);
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n, k = 0, r = 3;
    cin >> n;
    while (r < n) r = r * 2 + ++k + 3;
    cout << f(k, r, n);
}
