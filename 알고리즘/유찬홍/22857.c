#include <stdio.h>

int main() {
    int n, k, s = 0, e = 0, rs = 0, arr[1000000];
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    while (e < n) {
        int maxlen = 0, c = 0;
        for (int i = s; i <= e; i++) {
            if (arr[i] % 2 == 0) maxlen++;
            else {
                if (c <= k) c++;
            }
        }
        if (c <= k) {
            if (rs < maxlen)rs = maxlen;
            e++;
        } else s++;
    }
    printf("%d", rs);
    return 0;
}