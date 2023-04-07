#include <stdio.h>
#include <string.h>

int main() {
    int top = -1;
    char arr[1000001], stack[1000001];
    scanf("%s", arr);
    int len = strlen(arr);
    for (int i = 0; i < len; i++) {
        stack[++top] = arr[i];
        if (i >= 3 && stack[top] == 'P' && stack[top - 1] == 'A' && stack[top - 2] == 'P' && stack[top - 3] == 'P') {
            top -= 3;
        }
    }
    if (stack[top] == 'P' && top == 0) printf("PPAP");
    else printf("NP");
}