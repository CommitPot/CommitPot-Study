#include <iostream>

using namespace std;

int f(string a, string b, int k) {
    if (a.size() + k > b.size()) return 1e9;
    int l = 0;
    for (int i = 0; i < a.size(); i++) {
        if (a[i] != b[i + k]) l++;
    }
    return min(l, f(a, b, k + 1));
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    string a, b;
    cin >> a >> b;
    cout << f(a, b, 0);
}
