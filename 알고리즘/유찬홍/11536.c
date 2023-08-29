#include <stdio.h>
#include <string.h>

int main() {
    int n, rs = 0;
    char arr[13], arr1[13];
    scanf("%d %s", &n, arr);
    for (int i = 1; i < n; i++) {
        scanf("%s", arr1);
        if (strcmp(arr1, arr) > 0) rs++;
        else rs--;
        strcpy(arr, arr1);
    }
    n--;
    printf("%s", n == rs ? "INCREASING" : n == rs * -1 ? "DECREASING" : "NEITHER");
}
