#include <iostream>

using namespace std;

int t, n, l[1001], m[1001];

string f(int s, int e, int k) {
    if (s >= e) return to_string(l[k]);
    string str;
    for (int i = s; i <= e; i++) {
        if (l[k] == m[i]) {
            if (k + 1 <= n && s <= i - 1) str += f(s, i - 1, k + 1) + " ";
            if (k + i - s + 1 <= n && i + 1 <= e) str += f(i + 1, e, k + i - s + 1) + " ";
        }
    }
    return str + f(k, k, k);
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++) cin >> l[i];
        for (int i = 1; i <= n; i++) cin >> m[i];
        cout << f(1, n, 1) << "\n";
    }
}
