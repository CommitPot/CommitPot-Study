#include <stdio.h>

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++) {
        int n;
        char arr[1002], rs[2004];
        scanf("%d ", &n);
        int f = 1000, r = 1000;
        for (int j = 0; j < n; j++) {
            scanf(" %c", &arr[j]);
        }
        rs[r] = arr[0];
        for (int j = 1; j < n; j++) {
            if (rs[f] >= arr[j]) rs[--f] = arr[j];
            else rs[++r] = arr[j];
        }
        for (int j = f; j <= r; j++) {
            printf("%c", rs[j]);
        }
        printf("\n");
    }
}
