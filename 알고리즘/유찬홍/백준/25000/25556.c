#include <stdio.h>

int main() {
    int n, a[4] = {};
    scanf("%d", &n);
    for (int i = 0, j; i < n; i++) {
        scanf("%d", &j);
        int r = 1;
        for (int k = 0; k < 4; k++) {
            if (a[k] < j) {
                a[k] = j, r = 0;
                break;
            }
        }
        if (r) {
            printf("NO");
            return 0;
        }
    }
    printf("YES");
}
