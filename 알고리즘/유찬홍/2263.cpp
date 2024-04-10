#include <iostream>

using namespace std;

int n, c, l[100001], m[100001], o[100001], r[100001];

void f(int s, int e, int k) {
    if (s == e) {
        r[c++] = m[k];
        return;
    }
    f(k, k, k);
    int a = o[m[k]];
    if (k - e + a > 1 && a - 1 >= s) f(s, a - 1, k - e + a - 1);
    if (k > 1 && a + 1 <= e) f(a + 1, e, k - 1);
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> l[i];
    for (int i = 1; i <= n; i++) cin >> m[i], o[l[i]] = i;
    f(1, n, n);
    for (int i = 0; i < c; i++) {
        cout << r[i] << " ";
    }
}
