#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n;
    while (cin >> n, n ? 1 : 0) {
        int a;
        vector<int> l;
        while (n--) {
            cin >> a;
            if (l.empty() || l[l.size() - 1] != a) l.emplace_back(a);
        }
        for (int i: l) cout << i << " ";
        cout << "$\n";
    }
}
