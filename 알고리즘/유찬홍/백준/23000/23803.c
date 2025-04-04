#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n * 5; i++) {
        for (int j = 0; j < n * (i < n * 4 ? 1 : 5); j++) printf("@");
        printf("\n");
    }
}
