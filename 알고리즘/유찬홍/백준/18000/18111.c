#include <stdio.h>

int main() {
    int n, m, b, arr[501][501], max = -1, min = 1000000000, minTime = 1000000000, maxHeight = -1;
    scanf("%d %d %d", &n, &m, &b);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &arr[i][j]);
            if (max < arr[i][j]) max = arr[i][j];
            if (min > arr[i][j]) min = arr[i][j];
        }
    }
    if (max > 256) max = 256;
    for (int i = min; i <= max; i++) {
        int time = 0, inb = b;
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < m; k++) {
                if (i > arr[j][k]) {
                    time += i - arr[j][k];
                    inb -= i - arr[j][k];
                } else if (i < arr[j][k]) {
                    time += (arr[j][k] - i) * 2;
                    inb += arr[j][k] - i;
                }
            }
        }
        if (inb < 0) continue;
        if (minTime >= time && maxHeight < i) {
            minTime = time;
            maxHeight = i;
        }
    }
    printf("%d %d", minTime, maxHeight);
}
