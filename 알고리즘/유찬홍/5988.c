#include <stdio.h>
#include <string.h>

int main() {
    int n;
    char arr[100];
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", arr);
        int len = strlen(arr);
        if ((arr[len - 1] - 48) % 2 == 0) printf("even\n");
        else printf("odd\n");
    }
}