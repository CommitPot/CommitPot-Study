#include <stdio.h>

int main() {
    int n, m, r = 0;
    char a[51][51];
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%s", a[i]);
    }
    for (int i = 0; i < (n < m ? n : m); i++) {
        for (int j = 0; j < n - i; j++) {
            for (int k = 0; k < m - i; k++) {
                if (a[j][k] == a[j][k + i] && a[j][k] == a[j + i][k] && a[j][k] == a[j + i][k + i]) r = i + 1;
            }
        }
    }
    printf("%d", r * r);
}
