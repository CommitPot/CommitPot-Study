#include <stdio.h>

int main() {
    int t, a, b;
    scanf("%d", &t);
    while (t--) {
        int c[1025] = {};
        scanf("%d %d", &a, &b);
        int min = a > b ? b : a, max = a > b ? a : b;
        c[min]++;
        while (min) {
            c[min / 2]++;
            min /= 2;
        }
        while (max) {
            if (c[max / 2]) {
                printf("%d\n", max / 2 * 10);
                break;
            }
            c[max / 2]++;
            max /= 2;
        }
    }
}
