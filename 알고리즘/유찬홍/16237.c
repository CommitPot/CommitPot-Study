#include <stdio.h>

int main() {
    int a[6], r = 0;
    for (int i = 1; i < 6; i++) scanf("%d", &a[i]);
    for (int i = 5, s; i > 0; i--) {
        while (a[i]--) {
            s = i;
            for (int j = i; j > 0; j--) {
                while (s + j < 6 && a[j]) s += j, a[j]--;
            }
            r++;
        }
    }
    printf("%d", r);
}
