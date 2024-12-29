#include <iostream>

using namespace std;

char a[64][65];

bool check(int w, int x, int y) {
    for (int i = x; i < w + x; i++) {
        for (int j = y; j < w + y; j++) {
            if (a[x][y] != a[i][j]) return false;
        }
    }
    return true;
}

string f(int w, int x, int y) {
    if (check(w, x, y)) return a[x][y] == '0' ? "0" : "1";
    w >>= 1;
    return "(" + f(w, x, y) + f(w, x, y + w) + f(w, x + w, y) +
           f(w, x + w, y + w) + ")";
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    cout << f(n, 0, 0);
}
