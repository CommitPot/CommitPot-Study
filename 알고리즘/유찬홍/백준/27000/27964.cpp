#include <iostream>
#include <set>

using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n;
    set<string> s;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string a;
        cin >> a;
        if (a.size() < 6) continue;
        auto b = a.substr(a.size() - 6, 6);
        if (b == "Cheese" && s.find(a) == s.end()) s.insert(a);
    }
    cout << (s.size() > 3 ? "yummy" : "sad");
}
