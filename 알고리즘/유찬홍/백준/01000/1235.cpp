#include <map>
#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int n, r = 0;
    string s[1000];
    cin >> n;
    for (int i = 0; i < n; i++) cin >> s[i];
    int l = s[0].size();
    for (int i = l - 1, p = 0; !r; i--) {
        map<string, int> m;
        for (int j = 0; j < n; j++) {
            string b;
            for (int k = i; k < l; k++) b += s[j][k];
            m[b]++;
        }
        for (auto [k, v]: m) {
            if (v > 1) p = 1;
        }
        if (!p) r = l - i;
        p = 0;
    }
    cout << r;
}
