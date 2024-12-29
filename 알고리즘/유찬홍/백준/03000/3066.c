#include <stdio.h>

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++) {
        int n, arr[40001], rs[40001] = {0}, rs1 = 0;
        scanf("%d", &n);
        for (int j = 0; j < n; j++) {
            scanf("%d", &arr[j]);
        }
        rs[0] = arr[0];
        for (int j = 1; j < n; j++) {
            if (arr[j] > rs[rs1]) rs[++rs1] = arr[j];
            else {
                int s = 0, e = rs1;
                while (s < e) {
                    int mid = (s + e) / 2;
                    if (rs[mid] < arr[j]) s = mid + 1;
                    else e = mid;
                }
                rs[e] = arr[j];
            }
        }
        printf("%d\n", rs1 + 1);
    }
    return 0;
}