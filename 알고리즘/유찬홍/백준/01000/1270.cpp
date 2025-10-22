#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n, t;
    long long a[100001];
    cin >> n;
    string s, r;
    while (n--) {
        cin >> t;
        long long e = 0, c = 0;
        for (int i = 0; i < t; i++) cin >> a[i];
        for (int i = 0; i < t; i++) {
            if (!c) e = a[i];
            if (a[i] == e) c++;
            else c--;
        }
        c = 0;
        for (int i = 0; i < t; i++) {
            if (a[i] == e) c++;
        }
        if (c > t / 2) r += to_string(e) + "\n";
        else r += "SYJKGW\n";
    }
    cout << r;
}
