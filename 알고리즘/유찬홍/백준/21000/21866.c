#include <stdio.h>

int main() {
    int r = 0, a[] = {100, 200, 300, 400, 500};
    for (int i = 0, j; i < 9; i++) {
        scanf("%d", &j);
        if (a[i / 2] < j) {
            printf("hacker");
            return 0;
        }
        r += j;
    }
    printf("%s", r > 99 ? "draw" : "none");
}
