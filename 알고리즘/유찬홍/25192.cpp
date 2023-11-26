#include <iostream>
#include <set>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, cnt = 0;
    set<string> s;
    string str;
    cin >> n;
    while (n--) {
        cin >> str;
        if (str == "ENTER") {
            s.clear();
        } else if (s.find(str) == s.end()) {
            s.insert(str);
            cnt++;
        }
    }
    cout << cnt;
}
