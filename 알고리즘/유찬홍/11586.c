#include <stdio.h>

int main() {
    int n, m;
    char s[100][101];
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%s", s[i]);
    scanf("%d", &m);
    if (m == 1) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                printf("%c", s[i][j]);
            }
            printf("\n");
        }
    }
    if (m == 2) {
        for (int i = 0; i < n; i++) {
            for (int j = n - 1; j >= 0; j--) {
                printf("%c", s[i][j]);
            }
            printf("\n");
        }
    }
    if (m == 3) {
        for (int i = n - 1; i >= 0; i--) {
            for (int j = 0; j < n; j++) {
                printf("%c", s[i][j]);
            }
            printf("\n");
        }
    }
}
