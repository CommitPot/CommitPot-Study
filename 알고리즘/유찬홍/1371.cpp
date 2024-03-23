#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    string s;
    int a[26] = {0};
    vector<char> l;
    while (cin >> s) {
        for (char i: s) a[i - 97]++;
    }
    for (int i = 0, j = 0; i < 26; i++) {
        if (j < a[i]) {
            l.clear();
            j = a[i];
            l.emplace_back(i + 97);
        } else if (j == a[i]) l.emplace_back(i + 97);
    }
    for (char i: l) cout << i;
}
