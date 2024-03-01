#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

string add(string a, string b) {
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    if (a.length() < b.length()) swap(a, b);
    int c, j = 0;
    string d;
    for (int i = 0; i < a.length(); i++) {
        if (b[i] < 48 || b[i] > 49) b += '0';
        c = a[i] + b[i] - 96 + j;
        if (c > 1) {
            c %= 2;
            j = 1;
        } else j = 0;
        d += to_string(c);
    }
    if (j) d += to_string(j);
    reverse(d.begin(), d.end());
    for (int i = 0; i < d.length(); i++) {
        if (d[i] == '1') {
            return d.substr(i);
        }
    }
    return "0";
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    string a, b;
    cin >> a >> b;
    cout << add(a, b);
}
