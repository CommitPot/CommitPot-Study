#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n * 5; i++) {
        for (int j = 0; j < n; j++) printf("@");
        if (i / n == 0 || i / n == 4) for (int j = 0; j < n * 4; j++) printf("@");
        printf("\n");
    }
}
