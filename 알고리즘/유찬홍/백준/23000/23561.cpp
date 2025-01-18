#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int n, a[300001];
    cin >> n;
    for (int i = 0; i < n * 3; i++) cin >> a[i];
    sort(a, a + n * 3);
    cout << a[n * 2 - 1] - a[n];
}
