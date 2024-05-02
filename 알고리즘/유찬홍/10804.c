#include <stdio.h>

int main() {
    int l[21];
    for (int i = 1; i < 21; i++) l[i] = i;
    for (int i = 0, a, b; i < 10; i++) {
        scanf("%d %d", &a, &b);
        for (int j = a, k = b; j < k; j++, k--) {
            int t = l[j];
            l[j] = l[k];
            l[k] = t;
        }
    }
    for (int i = 1; i < 21; i++) {
        printf("%d ", l[i]);
    }
}
