#include <iostream>

using namespace std;

string l, m;

string f(int s, int e, int k) {
    if (s > e) return "";
    if (s == e) {
        string a;
        a += l[k];
        return a;
    }
    string str;
    for (int i = s; i <= e; i++) {
        if (l[k] == m[i]) {
            str += f(s, i - 1, k + 1);
            str += f(i + 1, e, k + i - s + 1);
        }
    }
    return str + l[k];
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    while (cin >> l >> m) {
        cout << f(0, l.length() - 1, 0) << "\n";
    }
}
