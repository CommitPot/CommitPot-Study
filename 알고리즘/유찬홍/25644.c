#include <stdio.h>

int main() {
    int n, a, min, max = 0;
    scanf("%d %d", &n, &min);
    while (--n) {
        scanf("%d", &a);
        if (max < a - min) max = a - min;
        if (min > a) min = a;
    }
    printf("%d", max);
}
