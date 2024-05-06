#include <stdio.h>

int main() {
    int a[5][5] = {}, x[26], y[26];
    for (int i = 0; i < 5; i++) {
        for (int j = 0, b; j < 5; j++) {
            scanf("%d", &b);
            x[b] = i, y[b] = j;
        }
    }
    for (int i = 0, b; i < 25; i++) {
        scanf("%d", &b);
        a[x[b]][y[b]] = 1;
        int r = 0;
        for (int j = 0; j < 5; j++) {
            int cnt = 0, cnt1 = 0;
            for (int k = 0; k < 5; k++) cnt += a[j][k], cnt1 += a[k][j];
            r += cnt == 5;
            r += cnt1 == 5;
        }
        int cnt = 0, cnt1 = 0;
        for (int j = 0; j < 5; j++) {
            cnt += a[j][j];
            cnt1 += a[j][4 - j];
        }
        r += cnt == 5;
        r += cnt1 == 5;
        if (r > 2) {
            printf("%d", i + 1);
            break;
        }
    }
}
