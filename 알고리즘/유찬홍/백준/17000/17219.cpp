#include <iostream>
#include <map>

using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    map<string, string> map;
    int n, m;
    string s, s1;
    cin >> n >> m;
    while (n--) {
        cin >> s >> s1;
        map[s] = s1;
    }
    while (m--) {
        cin >> s;
        cout << map[s] << endl;
    }
}
