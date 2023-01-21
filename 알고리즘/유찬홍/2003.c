#include <stdio.h>

int main() {
    int n, m, arr[10000], count = 0, a = 0, b = 0;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    while (b < n) {
        int sum = 0;
        for (int k = a; k <= b; k++) {
            sum += arr[k];
        }
        if (sum == m) {
            count++;
            a++;
            b++;
        } else if (sum > m) a++;
        else b++;
    }
    printf("%d", count);
}