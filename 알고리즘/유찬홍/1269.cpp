#include <iostream>
#include <set>

using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    set<int> s, s1;
    int a, b, c, cnt = 0;
    cin >> a >> b;
    while (a--) {
        cin >> c;
        s.emplace(c);
    }
    while (b--) {
        cin >> c;
        s1.emplace(c);
    }
    for (auto i: s) {
        auto j = s1.find(i);
        if (j == s1.end()) cnt++;
    }
    for (auto i: s1) {
        auto j = s.find(i);
        if (j == s.end()) cnt++;
    }
    cout << cnt;
}
