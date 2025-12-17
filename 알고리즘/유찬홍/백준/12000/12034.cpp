#include <map>
#include <vector>
#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t, n;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> n;
        map<int, int> m;
        vector<int> k, r;
        for (int j = 0, a; j < n * 2; j++) {
            cin >> a;
            k.emplace_back(a);
            m[a]++;
        }
        for (int j: k) {
            if (m[j] != 0 && m[j / 3 * 4] != 0) {
                r.emplace_back(j);
                m[j / 3 * 4]--;
                m[j]--;
            }
        }
        cout << "Case #" << i + 1 << ":";
        for (int j: r) cout << " " << j;
        cout << "\n";
    }
}
