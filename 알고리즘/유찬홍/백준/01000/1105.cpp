#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    string a, b;
    cin >> a >> b;
    int c = 0;
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    for (int i = 0; i < max(a.length(), b.length()); i++) {
        if (a[i] == b[i]) {
            if (a[i] == '8') c++;
        } else c = 0;
    }
    cout << c;
}
