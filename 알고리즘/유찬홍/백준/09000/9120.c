#include <stdio.h>
#include <string.h>

char arr[1000001], arr1[1000001];
int fail[1000001] = {0};

void failFunc() {
    int len1 = strlen(arr1);
    for (int i = 1, j = 0; i < len1; i++) {
        while (j && arr1[i] != arr1[j]) j = fail[j - 1];
        if (arr1[i] == arr1[j]) fail[i] = ++j;
    }
}

int kmp() {
    failFunc();
    int cnt = 0, len = strlen(arr), len1 = strlen(arr1);

    for (int i = 0, j = 0; i < len; i++) {
        while (j && arr[i] != arr1[j]) j = fail[j - 1];
        if (arr[i] == arr1[j]) {
            if (j == len1 - 1) {
                cnt++;
                j = fail[j];
            } else j++;
        }
    }
    return cnt;
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s %s", arr1, arr);
        int cnt = kmp();
        printf("%d\n", cnt);
    }
    return 0;
}