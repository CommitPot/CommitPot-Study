#include <iostream>
#include <map>

using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    map<string, int> m;
    string s;
    int n;
    cin >> n;
    while (n--) {
        cin >> s;
        m[s]++;
    }
    for (const auto &i: m) {
        if (n < i.second) {
            n = i.second;
            s = i.first;
        }
    }
    cout << s;
}
