#include <stdio.h>
#include <string.h>

int main() {
    int max = 0;
    char arr[5001];
    scanf("%s", arr);
    int len = strlen(arr);
    int len1 = len;
    for (int i = 0; i < len1; i++) {
        int fail[5001] = {0};
        for (int j = 1, k = 0; j < len; j++) {
            while (k && arr[j] != arr[k]) k = fail[k - 1];
            if (arr[j] == arr[k]) fail[j] = ++k;
        }
        for (int j = 0; j < len; j++) {
            if (max < fail[j]) max = fail[j];
        }
        for (int j = 1; j <= len; j++) {
            arr[j - 1] = arr[j];
        }
        len--;
    }
    printf("%d", max);
    return 0;
}