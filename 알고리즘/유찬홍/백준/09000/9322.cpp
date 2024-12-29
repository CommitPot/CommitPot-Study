#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t, n;
    string s;
    cin >> t;
    while (t--) {
        cin >> n;
        unordered_map<string, int> m;
        vector<string> l(n), l2(n), l3(n);
        for (int i = 0; i < n; i++) {
            cin >> s;
            m[s] = i;
        }
        for (int i = 0; i < n; i++) cin >> l[i];
        for (int i = 0; i < n; i++) cin >> l2[i];
        for (int i = 0; i < n; i++) l3[m[l[i]]] = l2[i];
        for (const auto &i: l3) {
            cout << i << " ";
        }
        cout << "\n";
    }
}
