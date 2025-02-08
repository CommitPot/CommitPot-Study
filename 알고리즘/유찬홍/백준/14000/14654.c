#include <stdio.h>

int main() {
    int n, a[601], r = 0;
    scanf("%d", &n);
    for (int i = 0; i < n * 2; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 0, b[2] = {}; i < n; i++) {
        if (a[i] == a[n + i]) {
            if (b[0]) {
                b[1]++;
                b[0] = 0;
            } else {
                b[0]++;
                b[1] = 0;
            }
        } else if ((a[i] == 2 && a[n + i] == 1) || (a[i] == 3 && a[n + i] == 2) || (a[i] == 1 && a[n + i] == 3)) {
            b[0]++;
            b[1] = 0;
        } else {
            b[1]++;
            b[0] = 0;
        }
        r = b[0] > r ? b[0] : r;
        r = b[1] > r ? b[1] : r;
    }
    printf("%d", r);
}
