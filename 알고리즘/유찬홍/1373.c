#include <stdio.h>
#include <string.h>

int main() {
    int l = 0;
    char arr[1000001], arr1[333335];
    scanf("%s", arr);
    int len = strlen(arr);
    for (int i = len - 1, j = 1, sum = 0; i >= 0; i--) {
        if (arr[i] == 49) sum += j;
        j *= 2;
        if (j == 8 || !i) {
            arr1[l++] = sum + 48;
            j = 1;
            sum = 0;
        }
    }
    for (int i = l - 1; i >= 0; i--) {
        printf("%c", arr1[i]);
    }
}
