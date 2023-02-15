#include <stdio.h>
#include <string.h>

int main() {
    int n;
    char arr[21], arr1[21];
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s %s", arr, arr1);
        int len = strlen(arr);
        printf("Distances:");
        for (int j = 0; j < len; j++) {
            printf(" %d", arr1[j] >= arr[j] ? arr1[j] - arr[j] : arr1[j] + 26 - arr[j]);
        }
        printf("\n");
    }
    return 0;
}
