#include <iostream>

using namespace std;
int n, t[16], p[16];

int f(int w, int len) {
    if (len > n) return 0;
    if (len == n) return w;
    return max(f(w, len + 1), f(w + p[len], len + t[len]));
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    cin >> n;
    for (int i = 0; i < n; i++) cin >> t[i] >> p[i];
    cout << f(0, 0);
}
