#include <stdio.h>

int main() {
    int n, m, j = 0, k = 1, count = 100000, arr[100000] = {0};
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &arr[i]);
        arr[i] += arr[i - 1];
    }
    while (k <= n) {
        int sum = arr[k] - arr[j];
        if (m > sum) k++;
        else {
            j++;
            count = count > k - j + 1 ? k - j + 1 : count;
        }
    }
    printf("%d", count == 10000 ? 0 : count);
}