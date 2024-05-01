#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    unordered_map<string, int> m;
    string s;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s;
        m[s]++;
    }
    for (int i = 1; i < n; i++) {
        cin >> s;
        m[s]--;
    }
    for (auto [k, v]: m) {
        if (v) {
            cout << k;
            break;
        }
    }
}
