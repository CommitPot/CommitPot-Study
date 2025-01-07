#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
    int n, m, t, a[41][41], b[9], r = 0;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    scanf("%d", &t);
    for (int i = 0; i < n - 2; i++) {
        for (int j = 0; j < m - 2; j++) {
            for (int k = 0; k < 3; k++) {
                for (int l = 0; l < 3; l++) {
                    b[k * 3 + l] = a[i + k][j + l];
                }
            }
            sort(b, b + 9);
            if (b[4] >= t) r++;
        }
    }
    printf("%d", r);
}
