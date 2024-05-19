#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n, a, b, cnt = 0;
    cin >> n >> a >> b;
    vector<int> l;
    for (int i = 1; i <= n; i++) l.emplace_back(i);
    while (!l.empty()) {
        auto m = l;
        cnt++;
        l.clear();
        int len = m.size() / 2 * 2;
        for (int i = 0; i < len; i += 2) {
            if (m[i] == a || m[i] == b || m[i + 1] == a || m[i + 1] == b) {
                if ((m[i] == a && m[i + 1] == b) || (m[i] == b && m[i + 1] == a)) {
                    cout << cnt;
                    return 0;
                }
                if (m[i] == a || m[i] == b) l.emplace_back(m[i]);
                else l.emplace_back(m[i + 1]);
            } else l.emplace_back(m[i]);
        }
        if (m.size() % 2) l.emplace_back(m.back());
    }
}
