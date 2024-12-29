#include <stdio.h>
#include <string.h>

int main() {
    int n;
    char arr[1001];
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", arr);
        int len = strlen(arr);
        if (arr[len / 2] == arr[len / 2 - 1]) printf("Do-it\n");
        else printf("Do-it-Not\n");
    }
    return 0;
}