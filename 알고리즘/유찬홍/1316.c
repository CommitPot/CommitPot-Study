#include <stdio.h>
#include <string.h>

int main() {
    int n, count = 0;
    char arr[101];
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", arr);
        int len = strlen(arr), c = 0, arr1[100] = {0};
        arr1[arr[0] - 65]++;
        for (int j = 1; j < len; j++) {
            arr1[arr[j] - 65]++;
            if (arr[j] != arr[j - 1] && arr1[arr[j] - 65] > 1) c++;
        }
        if (c == 0) count++;
    }
    printf("%d", count);
}