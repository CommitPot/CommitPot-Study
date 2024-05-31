#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n, s, p, rs = -1;
    cin >> n >> s >> p;
    vector<int> l(p + 1, -1);
    map<int, int> m;
    for (int i = 1; i <= n; i++) cin >> l[i], m[l[i]]++;
    for (int i = 1; i <= p; i++) {
        if (s > l[i]) {
            rs = i - m[s];
            break;
        }
    }
    cout << rs;
}
