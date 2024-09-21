#include <unordered_set>
#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n, m;
    string a;
    unordered_set<string> s;
    cin >> n >> m;
    while (n--) {
        cin >> a;
        s.insert(a);
    }
    while (m--) {
        cin >> a;
        string b;
        for (char i: a) {
            if (i == ',') s.erase(b), b = "";
            else b += i;
        }
        s.erase(b);
        cout << s.size() << '\n';
    }
}
