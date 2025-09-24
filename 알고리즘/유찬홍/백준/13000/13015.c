#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) printf("*");
    for (int i = 0; i < n * 2 - 3; i++) printf(" ");
    for (int i = 0; i < n; i++) printf("*");
    printf("\n");
    for (int i = 1; i < n - 1; i++) {
        for (int j = 0; j < i; j++) printf(" ");
        printf("*");
        for (int j = 2; j < n; j++) printf(" ");
        printf("*");
        for (int j = i * 2; j < n * 2 - 3; j++) printf(" ");
        printf("*");
        for (int j = 2; j < n; j++) printf(" ");
        printf("*\n");
    }
    for (int i = 1; i < n; i++) printf(" ");
    printf("*");
    for (int j = 2; j < n; j++) printf(" ");
    printf("*");
    for (int i = 2; i < n; i++) printf(" ");
    printf("*\n");
    for (int i = n - 2; i > 0; i--) {
        for (int j = 0; j < i; j++) printf(" ");
        printf("*");
        for (int j = 2; j < n; j++) printf(" ");
        printf("*");
        for (int j = i * 2; j < n * 2 - 3; j++) printf(" ");
        printf("*");
        for (int j = 2; j < n; j++) printf(" ");
        printf("*\n");
    }
    for (int i = 0; i < n; i++) printf("*");
    for (int i = 0; i < n * 2 - 3; i++) printf(" ");
    for (int i = 0; i < n; i++) printf("*");
}
