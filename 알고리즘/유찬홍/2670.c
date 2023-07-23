#include <stdio.h>

int main() {
    int n;
    double arr[10001], max = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%lf", &arr[i]);
    }
    for (int i = 0; i < n; i++) {
        double rs = 1;
        for (int j = i; j < n; j++) {
            rs *= arr[j];
            if (max < rs) max = rs;
        }
    }
    printf("%.3lf", max);
}
