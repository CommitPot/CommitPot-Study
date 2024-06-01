#include <iostream>
#include <algorithm>

using namespace std;

typedef short s;

s m[1025][1025];

s f(s w, s x, s y) {
    if (w == 1) return m[x][y];
    s a[4] = {f(w / 2, x, y), f(w / 2, x, y + w / 2), f(w / 2, x + w / 2, y), f(w / 2, x + w / 2, y + w / 2)};
    sort(a, a + 4);
    return a[2];
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cin.tie(nullptr);
    s n;
    cin >> n;
    for (s i = 0; i < n; i++) {
        for (s j = 0; j < n; j++) {
            cin >> m[i][j];
        }
    }
    cout << f(n, 0, 0);
}
