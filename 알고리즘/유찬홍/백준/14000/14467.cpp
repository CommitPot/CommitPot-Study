#include <iostream>
#include <map>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    map<int, int> m;
    int n, a, b, cnt = 0;
    cin >> n;
    while (n--) {
        cin >> a >> b;
        if (m.find(a) == m.end()) {
            m[a] = b;
        } else {
            if (m[a] != b) {
                cnt++;
                m[a] = b;
            }
        }
    }
    cout << cnt;
}
