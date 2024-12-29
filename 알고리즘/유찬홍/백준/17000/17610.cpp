#include <iostream>
#include <bitset>

using namespace std;
int n, s, l[13];
bitset<2600001> a;

int f(int w, int len) {
    if (len == n) {
        if (w > s || w < 1 || a[w]) return 0;
        return a[w] = true;
    }
    int c = 0;
    c += f(w + l[len], len + 1);
    c += f(w - l[len], len + 1);
    c += f(w, len + 1);
    return c;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    cin >> n;
    for (int i = 0; i < n; i++) cin >> l[i], s += l[i];
    cout << s - f(0, 0);
}
