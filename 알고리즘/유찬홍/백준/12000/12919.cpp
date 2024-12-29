#include <iostream>
#include <string>

using namespace std;
string a, b;
int rs;

string reverse(string s) {
    int len = s.length();
    for (int i = 0; i < s.length() / 2; i++) {
        swap(s[i], s[len - i - 1]);
    }
    return s;
}

void func(string s) {
    if (s == a) {
        rs = 1;
        return;
    }
    if (s.front() == 'A' && s.back() == 'A') func(s.substr(0, s.length() - 1));
    if (s.front() == 'B' && s.back() == 'A') {
        func(s.substr(0, s.length() - 1));
        func(reverse(s).substr(0, s.length() - 1));
    }
    if (s.front() == 'B' && s.back() == 'B') func(reverse(s).substr(0, s.length() - 1));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> a >> b;
    func(b);
    cout << rs;
}
