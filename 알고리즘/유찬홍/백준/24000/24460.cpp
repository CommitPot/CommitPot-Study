#include <iostream>
#include <algorithm>

using namespace std;

int n, arr[1024][1024];

int func(int x, int y, int z) {
    if (z == 1) return arr[x][y];
    int a[4];
    for (int i = x, k = 0; i < x + z; i += z / 2) {
        for (int j = y; j < y + z; j += z / 2) {
            a[k++] = func(i, j, z / 2);
        }
    }
    sort(a, a + 4);
    return a[1];
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> arr[i][j];
    cout << func(0, 0, n);
}
