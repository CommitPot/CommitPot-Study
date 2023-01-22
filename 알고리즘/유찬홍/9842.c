#include <stdio.h>

int main() {
    int n, l = 0, k = 2, arr[100000001] = {0};
    for (int i = 2; i <= 10000; i++) {
        if (!arr[i]) {
            for (int j = i * 2; j <= 100000000; j += i) {
                arr[j] = 1;
            }
        }
    }
    scanf("%d", &n);
    while (n > l) {
        if (!arr[k]) l++;
        k++;
    }
    printf("%d", k - 1);
}