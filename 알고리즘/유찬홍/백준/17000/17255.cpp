#include <iostream>
#include <unordered_set>

using namespace std;

unordered_set<string> m;

int f(const string &s, const string &p) {
    if (s.empty()) {
        if (m.find(p) != m.end()) return 0;
        m.insert(p);
        return 1;
    }
    return f(s.substr(0, s.size() - 1), p + s) + f(s.substr(1, s.size() - 1), p + s);
}

int main() {
    string s;
    cin >> s;
    cout << f(s, +"");
}
