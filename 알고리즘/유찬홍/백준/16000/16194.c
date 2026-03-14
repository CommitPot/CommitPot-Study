#include <stdio.h>

int main() {
    int n, a[1001];
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        for (int j = 0; j < i; j++) {
            int x = a[j] + a[i - j - 1];
            if (a[i] > x) a[i] = x;
        }
    }
    printf("%d", a[--n]);
}
