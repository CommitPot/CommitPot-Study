#include <stdio.h>
#include <stdlib.h>

int comp(const void *a, const void *b) {
    return *(int *) a - *(int *) b;
}

int main() {
    int t, n, k, arr[1000001] = {0};
    scanf("%d", &t);
    for (int i = 0; i < t; i++) {
        scanf("%d %d", &n, &k);
        for (int j = 0; j < n; j++) {
            scanf("%d", &arr[j]);
        }
        qsort(arr, n, 4, comp);
        int s = 0, e = n - 1, c1 = 200000001, c2 = 0, c3 = 0;
        while (s < e) {
            int sum = arr[s] + arr[e];
            if (sum > k) {
                if (abs(sum - k) < c1) {
                    c1 = abs(sum - k);
                    c2 = 1;
                } else if (abs(sum - k) == c1) c2++;
                e--;
            } else if (sum < k) {
                if (abs(sum - k) < c1) {
                    c1 = abs(sum - k);
                    c2 = 1;
                } else if (abs(sum - k) == c1) c2++;
                s++;
            } else {
                s++, e--;
                c1 = 0;
                c3++;
            }
        }
        printf("%d\n", c3 > 0 ? c3 : c2);
    }
    return 0;
}