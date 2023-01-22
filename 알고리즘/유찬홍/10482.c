#include <stdio.h>

int main() {
    int n, m, arr[32001] = {0};
    for (int i = 2; i <= 180; i++) {
        if (!arr[i]) {
            for (int j = i * 2; j <= 32000; j += i) {
                arr[j] = 1;
            }
        }
    }
    arr[0] = arr[1] = 1;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int count = 0;
        scanf("%d", &m);
        for (int j = 2; j <= m / 2; j++) {
            if (!arr[j] && !arr[m - j]) count++;
        }
        printf("%d has %d representation(s)\n", m, count);
        for (int j = 2; j <= m / 2; j++) {
            if (!arr[j] && !arr[m - j]) printf("%d+%d\n", j, m - j);
        }
        printf("\n");
    }
}