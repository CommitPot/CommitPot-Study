#include <stdio.h>

int main() {
    int n, c, arr[100], cnt = 0;
    scanf("%d %d", &n, &c);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    for (int i = 1; i <= c; i++) {
        for (int j = 0; j < n; j++) {
            if (i % arr[j] == 0) {
                cnt++;
                break;
            }
        }
    }
    printf("%d", cnt);
}
