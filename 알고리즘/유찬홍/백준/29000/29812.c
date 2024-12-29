#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n, d, m, c = 0, rs = 0;
    vector<int> h(3, 0);
    string s;
    cin >> n >> s >> d >> m;
    for (char i: s) {
        if (i != 'H' && i != 'Y' && i != 'U') c++;
        else {
            if (i == 'H') h[0]++;
            else if (i == 'Y') h[1]++;
            else h[2]++;
            rs += min(d * c, d + m);
            c = 0;
        }
    }
    if (d * c < d + m) rs += d * c;
    else rs += d + m;
    sort(h.begin(), h.end());
    cout << (!rs ? "Nalmeok" : to_string(rs)) << "\n" << (!h[0] ? "I love HanYang University" : to_string(h[0]));
}
