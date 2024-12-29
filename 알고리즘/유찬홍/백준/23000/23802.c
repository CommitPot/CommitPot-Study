#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n * 5; j++) {
            printf("@");
        }
        printf("\n");
    }
    for (int i = 0; i < n * 4; i++) {
        for (int j = 0; j < n; j++) {
            printf("@");
        }
        printf("\n");
    }
}
