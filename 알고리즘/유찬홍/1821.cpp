#include <iostream>

using namespace std;
int n, f;
bool vis[11], isSuc;

void bt(int *v, int cnt) {
    if (isSuc) return;
    if (cnt == n) {
        int arr[n + 1][n + 1];
        for (int i = 0; i < n; i++) arr[0][i] = v[i];
        for (int i = 1; i < n; i++) {
            for (int j = i; j < n; j++) {
                arr[i][j] = arr[i - 1][j] + arr[i - 1][j - 1];
            }
        }
        if (arr[n - 1][n - 1] == f) {
            for (int i = 0; i < n; i++) {
                cout << v[i] << " ";
            }
            isSuc = true;
        }
        return;
    }
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            vis[i] = true;
            v[cnt++] = i;
            bt(v, cnt--);
            vis[i] = false;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int arr[11];
    cin >> n >> f;
    bt(arr, 0);
}
