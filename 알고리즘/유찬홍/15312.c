#include <stdio.h>
#include <string.h>

int arr[4001][4001] = {0};

int main() {
    int alpha[26] = {3, 2, 1, 2, 3, 3, 2, 3, 3, 2, 2, 1, 2, 2, 1, 2, 2, 2, 1, 2, 1, 1, 1, 2, 2, 1};
    char arr2[2001], arr3[2001];
    scanf("%s %s", arr2, arr3);
    int len = strlen(arr2) * 2;
    int k = 0, l = 0;
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < len - i; j++) {
            if (!i) {
                if (j % 2 == 0) {
                    arr[i][j] = alpha[arr2[k++] - 65];
                } else arr[i][j] = alpha[arr3[l++] - 65];
            } else {
                arr[i][j] = (arr[i - 1][j] + arr[i - 1][j + 1]) % 10;
            }
        }
    }
    printf("%d%d", arr[len - 2][0], arr[len - 2][1]);
}
