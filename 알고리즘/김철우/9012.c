#include <stdio.h>
#include <string.h>
char str[51];
int n;
int main() {
    int value = 0;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        value = 0;
        scanf("%s", str);
        for (int j = 0; j < strlen(str); j++) {
            if (value < 0)
                break;
            if (str[j] == '(')
                value++;
            if (str[j] == ')')
                value--;
        }
        if (value == 0)
            printf("YES\n");
        else
            printf("NO\n");
    }
}
