#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n, c = 0;
    stack<int> s;
    cin >> n;
    vector<int> l, r(n);
    string a;
    getline(cin, a);
    getline(cin, a);
    for (int i = 0; a[i]; i++) {
        if (a[i] == ' ') {
            l.emplace_back(c);
            c = 0;
        } else c = c * 10 + a[i] - 48;
    }
    a.clear();
    l.emplace_back(c);
    for (int i = n - 1; i >= 0; i--) {
        while (!s.empty() && s.top() <= l[i]) s.pop();
        r[i] = s.empty() ? -1 : s.top();
        s.emplace(l[i]);
    }
    for (int i: r) a += to_string(i) + " ";
    cout << a;
}
