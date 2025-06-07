#include <stack>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n, c[2020002] = {};
    stack<int> t;
    vector<pair<int, int> > l;
    cin >> n;
    for (int i = 0, a, b; i < n; i++) {
        cin >> a >> b;
        l.emplace_back(a - b, i);
        l.emplace_back(a + b, i);
        c[a - b + 1010000]++;
        c[a + b + 1010000]++;
    }
    sort(l.begin(), l.end());
    for (auto [a,b]: l) {
        if (t.empty()) t.emplace(b);
        else {
            if (t.top() == b) t.pop();
            else t.push(b);
        }
    }
    if (t.size()) cout << "NO";
    else {
        for (int i: c) {
            if (i > 1) {
                cout << "NO";
                return 0;
            }
        }
        cout << "YES";
    }
}
