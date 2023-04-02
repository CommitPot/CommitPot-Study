#include <stdio.h>
#include <string.h>

int main(){
    int n, a, b;
    char arr[100];
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s %d %d", arr, &a, &b);
        int len = strlen(arr);
        for (int j = 0; j < len; j++) {
            if (j < a || j >= b) printf("%c", arr[j]);
        }
        printf("\n");
    }
}