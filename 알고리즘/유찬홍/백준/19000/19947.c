#include <stdio.h>

int max(int a, int b) { return a > b ? a : b; }

int main() {
    int h, y, a[11] = {};
    scanf("%d %d", &h, &y);
    a[0] = h;
    for (int i = 1; i <= y; i++) {
        a[i] = a[i - 1] * 1.05;
        if (i >= 3) a[i] = max(a[i], a[i - 3] * 1.2);
        if (i >= 5) a[i] = max(a[i], a[i - 5] * 1.35);
    }
    printf("%d", a[y]);
}
