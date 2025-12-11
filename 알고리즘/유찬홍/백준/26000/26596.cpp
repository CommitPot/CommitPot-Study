#include <map>
#include <cmath>
#include <vector>
#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    map<string, int> m;
    vector<int> v;
    int t, n;
    string s;
    cin >> t;
    while (t--) {
        cin >> s >> n;
        m[s] += n;
    }
    for (auto [a, b]: m) v.emplace_back(b);
    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < i; j++) {
            if (floor(v[i] * 1.618) == v[j] || floor(v[j] * 1.618) == v[i]) {
                cout << "Delicious!";
                return 0;
            }
        }
    }
    cout << "Not Delicious...";
}
