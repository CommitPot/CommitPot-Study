#include <iostream>
#include <set>

using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    set<string> s;
    string a[4];
    for (auto &i: a) cin >> i;
    for (const auto &i: a) {
        for (const auto &j: a) {
            s.insert(i + " " + j);
        }
    }
    for (const auto &i: s) cout << i << "\n";
}
