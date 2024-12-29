#include <stdio.h>
#include <stdlib.h>

typedef struct element {
    int a, b;
} element;

int comp(const void *a, const void *b) {
    return (((element *) a)->a - ((element *) b)->a);
}

int main() {
    int n, count = 0, dp[101] = {0};
    element arr[101];
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &arr[i].a, &arr[i].b);
    }
    qsort(arr, n, sizeof(arr[0]), comp);
    dp[0] = arr[0].b;
    for (int i = 1; i < n; i++) {
        if (dp[count] < arr[i].b) dp[++count] = arr[i].b;
        else {
            int s = 0, e = count;
            while (s < e) {
                int mid = (s + e) / 2;
                if (dp[mid] < arr[i].b) s = mid + 1;
                else e = mid;
            }
            dp[e] = arr[i].b;
        }
    }
    printf("%d", n - count - 1);
    return 0;
}