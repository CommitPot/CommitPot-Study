#include <stdio.h>
#include <string.h>

int main() {
    char arr[1001];
    scanf("%s", arr);
    int len = strlen(arr);
    for (int i = 0; i < len; ++i) {
        printf("%c", arr[i] >= 68 ? arr[i] - 3 : arr[i] + 23);
    }
    return 0;
}
