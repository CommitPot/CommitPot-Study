#include <stdio.h>

int main() {
    int n, arr[1001], s[1001], top = -1, a = 1, idx = 1;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &arr[i]);
    }
    while (a <= n) {
        if (arr[idx] == a) {
            idx++, a++;
        } else if (s[top] == a) {
            top--, a++;
        } else {
            s[++top] = arr[idx++];
            if (idx > n) {
                printf("Sad");
                return 0;
            }
        }
    }
    printf("Nice");
}
