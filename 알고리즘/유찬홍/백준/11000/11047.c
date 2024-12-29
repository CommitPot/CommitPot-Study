#include <stdio.h>

int main() {
    int n, k, arr[10], j = 0, count = 0;
    scanf("%d %d", &n, &k);
    for (int i = n - 1; i >= 0; i--) {
        scanf("%d", &arr[i]);
    }
    while (k > 0){
        count += k / arr[j];
        k %= arr[j];
        j++;
    }
    printf("%d", count);
    return 0;
}