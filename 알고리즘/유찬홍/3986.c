#include <stdio.h>
#include <string.h>

int main() {
    int n, c = 0;
    char arr[100001], stack[100001];
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", arr);
        int len = strlen(arr), top = -1;
        for (int j = 0; j < len; j++) {
            stack[++top] = arr[j];
            if (stack[top - 1] == stack[top]) top -= 2;
        }
        if (top == -1) c++;
    }
    printf("%d", c);
    return 0;
}