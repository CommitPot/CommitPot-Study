#include <stdio.h>

int main() {
    int n, arr[1000001] = {0}, c = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        if (i && arr[i] <= arr[i - 1]) c++;
    }
    printf("%d", arr[n - 1] >= arr[0] ? c + 1 : c);
}
