
#include <stdio.h>

int main() {
    int n, k, s = 0, e = 0, rs = 0, arr[1000000];
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    int c = 0, w = 0;
    while (e < n) {
        if (arr[e++] % 2 == 0) w++;
        else c++;
        if (c <= k) {
            if (rs < e - s - c) rs = e - s - c;
        } else {
            if (arr[s++] % 2 == 0) w--;
            else c--;
        }
    }
    printf("%d", rs);
    return 0;
}