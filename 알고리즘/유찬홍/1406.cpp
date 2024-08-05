#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int n;
    char c;
    string s;
    stack<int> a, b;
    cin >> s >> n;
    for (char i: s) a.emplace(i);
    while (n--) {
        cin >> c;
        if (c == 'L' && !a.empty()) b.emplace(a.top()), a.pop();
        else if (c == 'D' && !b.empty()) a.emplace(b.top()), b.pop();
        else if (c == 'B' && !a.empty()) a.pop();
        else if (c == 'P') {
            cin >> c;
            a.emplace(c);
        }
    }
    s.clear();
    while (!a.empty()) s += a.top(), a.pop();
    reverse(s.begin(), s.end());
    while (!b.empty()) s += b.top(), b.pop();
    cout << s;
}
