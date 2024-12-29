#include <stdio.h>
#include <stdlib.h>

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++) {
        int n, c = 0, b = 0, w = 0;
        char arr[100001], arr1[100001];
        scanf("%d", &n);
        for (int j = 0; j < n; j++) {
            scanf(" %c", &arr[j]);
        }
        for (int j = 0; j < n; j++) {
            scanf(" %c", &arr1[j]);
        }
        for (int j = 0; j < n; j++) {
            if (arr[j] != arr1[j]) {
                c++;
                if (arr[j] == 'B') b++;
                else w++;
            }
        }
        if (!b || !w) {
            printf("%d\n", c);
        } else if (abs(b - w) > 1) {
            printf("%d\n", b > w ? b : w);
        } else {
            printf("%d\n", c % 2 == 0 ? c / 2 : (c / 2) + 1);
        }
    }
}
