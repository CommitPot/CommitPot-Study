#include <iostream>
#include <map>

using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    string a, b;
    map<string, string, greater<>> m;
    int n;
    cin >> n;
    while (n--) {
        cin >> a >> b;
        m[a] = b;
    }
    for (const auto &i: m) {
        if (i.second == "enter")
            cout << i.first << "\n";
    }
}
