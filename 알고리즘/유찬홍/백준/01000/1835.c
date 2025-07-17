#include <stdio.h>

int main() {
    int n, a[1002] = {};
    scanf("%d", &n);
    for (int i = 1, j = 0; i <= n; i++) {
        int k = i;
        while (k--) {
            j++;
            if (j >= n) j = 0;
            while (a[j]) {
                j++;
                if (j >= n) j = 0;
            }
        }
        a[j++] = i;
        if (i == n) break;
        if (j >= n) j = 0;
        while (a[j]) {
            j++;
            if (j >= n) j = 0;
        }
    }
    for (int i = 0; i < n; i++) printf("%d ", a[i]);
}
