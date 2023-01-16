#include <stdio.h>

int main() {
    int n, arr[1001] = {1, 0, 1, 1};
    for (int i = 4; i < 1001; i++) {
        if (arr[i - 1] + arr[i - 3] + arr[i - 4] < 3) arr[i] = 1;
        else arr[i] = 0;
    }
    scanf("%d", &n);
    if (arr[n - 1] == 1) printf("SK");
    else printf("CY");
    return 0;
}