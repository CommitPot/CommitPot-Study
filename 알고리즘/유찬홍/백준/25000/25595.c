#include <stdio.h>

int main() {
    int n, a[101][101], b[2], r = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
            if (a[i][j] == 2) b[0] = i, b[1] = j;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = b[0] + b[1] + i & 1; j < n; j += 2) {
            if (a[i][j] == 1) r = 1;
        }
    }
    printf("%s", r ? "Kiriya" : "Lena");
}
