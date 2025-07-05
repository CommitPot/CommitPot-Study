#include <stdio.h>

int main() {
    int n, a[1001], r = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    for (int i = 0; i < n; i++) {
        int f = 0;
        for (int j = i + 1; j < n; j++) {
            if (a[i] == a[j]) f++;
        }
        r = r < f ? f : r;
    }
    printf("%d", ++r);
}
