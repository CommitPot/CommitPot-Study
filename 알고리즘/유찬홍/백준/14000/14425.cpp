#include <iostream>
#include <map>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m;
    string s;
    map<string, int> map;
    cin >> n >> m;
    while (n--) {
        cin >> s;
        map[s] = 1;
    }
    while (m--) {
        cin >> s;
        if (map[s] == 1) n++;
    }
    cout << n + 1;
}
