#include <iostream>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n, k, a, b, l[100001];
    cin >> n >> k;
    string s;
    for (int i = 1; i < n; i++) {
        cin >> a >> b;
        l[b] = a;
    }
    getline(cin, s);
    getline(cin, s);
    int c = 0, d = 0;
    for (int i = 0; s[i]; i++) {
        if (s[i] == ' ') {
            if (c == k) break;
            c = 0, d++;
        } else c = c * 10 + s[i] - 48;
    }
    c = 1;
    while (l[d] != 0) d = l[d], c++;
    cout << (k ? c : 0);
}
