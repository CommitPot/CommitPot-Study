#include <stdio.h>
#include <string.h>

int main() {
    char arr[1000001], arr1[1000001];
    scanf("%s %s", arr, arr1);
    if (strstr(arr, arr1) != NULL) printf("1");
    else printf("0");
    return 0;
}