#include <iostream>
#include <map>

using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    cout << fixed, cout.precision(4);
    string s;
    int c = 0;
    map<string, int> m;
    while (getline(cin, s)) m[s]++, c++;
    for (auto [a, b]: m) {
        cout << a << " " << (double) b / c * 100 << "\n";
    }
}
