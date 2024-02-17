#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n;
    cin >> n;
    vector<int> l(n, 0);
    for (int i = 0; i < n; i++) {
        vector<int> a(5);
        for (int &j: a) cin >> j;
        for (int j = 0; j < 5; j++) {
            for (int k = j + 1; k < 5; k++) {
                for (int o = k + 1; o < 5; o++) {
                    l[i] = max(l[i], (a[j] + a[k] + a[o]) % 10);
                }
            }
        }
    }
    int rs = l[0], idx = 0;
    for (int i = 1; i < n; i++) {
        if (rs <= l[i]) rs = l[i], idx = i;
    }
    cout << idx + 1;
}
