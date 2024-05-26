#include <iostream>
#include <map>

using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n;
    char s[1000001];
    map<string, char> m;
    cin >> n >> s;
    m["AA"] = m["AC"] = m["CA"] = m["TG"] = m["GT"] = 'A';
    m["AG"] = m["GA"] = m["CC"] = 'C';
    m["GC"] = m["CG"] = m["TT"] = 'T';
    m["AT"] = m["TA"] = m["TC"] = m["CT"] = m["GG"] = 'G';
    for (int i = n - 2; i >= 0; i--) {
        string a = {s[i], s[i + 1]};
        s[i] = m[a];
    }
    cout << s[0];
}
