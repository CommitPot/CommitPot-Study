#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n, b = 0, c;
    string a;
    cin >> n;
    while (n--) {
        cin >> a;
        if (a == "add") {
            cin >> c;
            b |= (1 << c);
        } else if (a == "check") {
            cin >> c;
            cout << ((b & (1 << c)) ? 1 : 0) << "\n";
        } else if (a == "toggle") {
            cin >> c;
            b ^= (1 << c);
        } else if (a == "all") {
            b = -1;
        } else if (a == "empty") {
            b = 0;
        } else {
            cin >> c;
            b &= ~(1 << c);
        }
    }
}
