#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n;
    string a;
    cin >> n;
    while (n--) {
        cin >> a;
        string b = a;
        reverse(a.begin(), a.end());
        int c = stoi(a) + stoi(b);
        a = to_string(c);
        bool d = false;
        for (int i = 0, j = a.size() - 1; i < j; i++, j--) {
            if (a[i] != a[j]) d = true;
        }
        cout << (d ? "NO" : "YES") << '\n';
    }
}
