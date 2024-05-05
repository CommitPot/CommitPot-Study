#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        vector<int> l;
        int c = 0, s;
        cin >> s;
        for (int i = 0, a; i < 20; i++) {
            cin >> a;
            if (l.empty() || l.back() < a) l.emplace_back(a);
            else {
                for (int j = 0; j < l.size(); j++) {
                    if (a < l[j]) {
                        l.insert(l.begin() + j, a);
                        c += l.size() - 1 - j;
                        break;
                    }
                }
            }
        }
        cout << s << " " << c << "\n";
    }
}
