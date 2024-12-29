#include <stdio.h>

int main() {
    int n, a, b, count = 0, arr[200001] = {0};
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &a, &b);
        if (arr[a] == b) count++;
        else arr[a] = b;
    }
    for (int i = 0; i < 200001; i++) {
        if (arr[i]) count++;
    }
    printf("%d", count);
    return 0;
}