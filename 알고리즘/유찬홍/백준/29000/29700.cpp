#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n, m, k, rs = 0;
    string s;
    cin >> n >> m >> k;
    while (n--) {
        cin >> s;
        int c = 0;
        for (auto i: s) {
            if (i == 49) {
                if (c >= k) rs += c - k + 1;
                c = 0;
            } else {
                c++;
            }
        }
        if (c >= k) rs += c - k + 1;
    }
    cout << rs;
}
