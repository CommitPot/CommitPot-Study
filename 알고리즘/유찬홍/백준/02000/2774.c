#include <stdio.h>

int main() {
    int n, a;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int count = 0;
        scanf("%d", &a);
        int num[10] = {0};
        while (a > 0) {
            int b = a % 10;
            num[b]++;
            a /= 10;
        }
        for (int j = 0; j <= 9; j++) {
            if (num[j] != 0) count++;
        }
        printf("%d\n", count);
    }
}
