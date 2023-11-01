#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m, arr[31][31];
    cin >> n >> m;
    m -= n;
    for (int i = 1; i <= m + n - 1; i++) {
        for (int j = 0; j <= i; j++) {
            if (j == 0 || i == j) arr[i][j] = 1;
            else arr[i][j] = arr[i - 1][j] + arr[i - 1][j - 1];
        }
    }
    cout << arr[m + n - 1][m];
}
