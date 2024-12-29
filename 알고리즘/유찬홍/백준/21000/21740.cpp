#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

string f(const string &a, const string &b) {
    string c = a + b;
    for (char &i: c) {
        if (i == '6') i = '9';
        else if (i == '9') i = '6';
    }
    reverse(c.begin(), c.end());
    return c;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n;
    cin >> n;
    vector<string> s;
    string a, r;
    for (int i = 0; i < n; i++) {
        cin >> a;
        s.emplace_back(a);
    }
    sort(s.begin(), s.end(), [](const string &a, const string &b) {
        if (a.size() == b.size()) return f(a, b) < f(b, a);
        return a.size() > b.size();
    });
    s.emplace_back(s[0]);
    sort(s.begin(), s.end(), [&](const string &a, const string &b) {
        return f(a, b) > f(b, a);
    });
    for (const auto &i: s) {
        cout << i;
    }
}
