#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n;
    long long int rs = 0;
    cin >> n;
    int l[n];
    for (int i = 0; i < n; i++) cin >> l[i];
    sort(l, l + n, greater<int>());
    for (int i = 0; i < n; i++) {
        if (l[i] <= i) break;
        rs += l[i] - i;
    }
    cout << rs;
}
