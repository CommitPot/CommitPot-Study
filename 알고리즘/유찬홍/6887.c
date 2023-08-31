#include <stdio.h>

int main() {
    int n, rs;
    scanf("%d", &n);
    for (int i = n; i * i > n; i--) {
        rs = i;
    }
    printf("The largest square has side length %d.", n != 1 ? rs - 1 : 1);
}
