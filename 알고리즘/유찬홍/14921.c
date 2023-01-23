#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, arr[100000], count = 2000000001, p;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    int j = 0, k = n - 1;
    while (j < k) {
        int sum = arr[j] + arr[k];
        if (count > abs(sum)) {
            count = abs(sum);
            p = sum;
        }
        if (sum < 0) j++;
        else k--;
    }
    printf("%d", p);
}