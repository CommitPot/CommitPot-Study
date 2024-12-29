#include <stdio.h>

int main() {
    int a, b, c, d;
    char e[50][51];
    scanf("%d %d %d %d", &a, &b, &c, &d);
    for (int i = 0; i < a; i++) {
        scanf("%s", e[i]);
    }
    for (int i = 0; i < a * c; i++) {
        for (int j = 0; j < b * d; j++) {
            printf("%c", e[i / c][j / d]);
        }
        printf("\n");
    }
}
