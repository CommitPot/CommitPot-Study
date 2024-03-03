#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    string a, b;
    while (cin >> a >> b) {
        bool c = false;
        for (int i = 0, j = 0; i < b.length(); i++) {
            if (a[j] == b[i]) j++;
            if (j == a.length()) c = true;
        }
        cout << (c ? "Yes" : "No") << "\n";
    }
}
