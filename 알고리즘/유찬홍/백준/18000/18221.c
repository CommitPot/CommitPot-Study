#include <stdio.h>
#include <math.h>

int main() {
    int n, b[4], r = 0;
    char a[1000][2001];
    scanf("%d ", &n);
    for (int i = 0; i < n; i++) {
        scanf(" %[^\n]", a[i]);
        for (int j = 0; j < n * 2; j += 2) {
            if (a[i][j] == 50) b[0] = i, b[1] = j;
            if (a[i][j] == 53) b[2] = i, b[3] = j;
        }
    }
    for (int i = b[0]; i + (b[0] < b[2] ? -1 : 1) != b[2]; i += (b[0] < b[2] ? 1 : -1)) {
        for (int j = b[1]; j + (b[1] < b[3] ? -2 : 2) != b[3]; j += (b[1] < b[3] ? 2 : -2)) {
            if (a[i][j] == 49) r++;
        }
    }
    printf("%d", pow(b[0] - b[2], 2) + pow(b[1] / 2 - b[3] / 2, 2) >= 25 && r > 2);
}
