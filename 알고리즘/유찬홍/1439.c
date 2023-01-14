#include <stdio.h>
#include <string.h>

int main() {
    char arr[1000001];
    scanf("%s", arr);
    int len = strlen(arr), z = 0, o = 0;
    for (int i = 0; i < len; i++) {
        if (arr[i] != arr[i + 1]) {
            if (arr[i] == '0') z++;
            else o++;
        }
    }
    printf("%d", z < o ? z : o);
    return 0;
}