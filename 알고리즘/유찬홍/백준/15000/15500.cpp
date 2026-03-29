#include <stack>
#include <iostream>
#include <set>

using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int n, k = 0;
    stack<int> a, b;
    set<int> c;
    string r;
    cin >> n;
    for (int i = 0, j; i < n; i++) {
        cin >> j;
        a.push(j);
        c.insert(j);
    }
    while (n--) {
        if (c.find(n + 1) != c.end()) {
            while (a.top() != n + 1) {
                r += "1 2\n";
                b.push(a.top());
                c.erase(a.top());
                a.pop();
                k++;
            }
            r += "1 3\n";
            c.erase(a.top());
            a.pop();
        } else {
            while (b.top() != n + 1) {
                r += "2 1\n";
                c.insert(b.top());
                a.push(b.top());
                b.pop();
                k++;
            }
            r += "2 3\n";
            b.pop();
        }
        k++;
    }
    cout << k << "\n" << r;
}
