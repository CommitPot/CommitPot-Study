#include <stdio.h>

int main() {
    int a, b, count = 0, arr[200001] = {0};
    scanf("%d %d", &a, &b);
    for (int i = 2; i <= 450; i++) {
        if (arr[i] == 0) {
            for (int j = i * 2; j <= 200000; j += i) {
                arr[j] = 1;
            }
        }
    }
    arr[0] = arr[1] = 1;
    for (int i = a; i <= b; i++) {
        int c = 0, k = 2, d = i;
        while (d > 1) {
            if (d % k == 0) {
                d /= k;
                c++;
            } else do k++; while (arr[k]);
        }
        if (arr[c] == 0 && k != d) count++;
    }
    printf("%d", count);
}