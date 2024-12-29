#include <iostream>
#include <map>

using namespace std;

int main() {
    int n, m;
    string s;
    map<string, int> strMap;
    map<int, string> intMap;
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> s;
        strMap[s] = i;
        intMap[i] = s;
    }
    for (int i = 0; i < m; i++) {
        cin >> s;
        if (s[0] < 65) {
            int v = stoi(s);
            cout << intMap[v] << "\n";
        } else {
            cout << strMap[s] << "\n";
        }
    }
}
