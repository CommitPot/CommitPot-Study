#include <stdio.h>
#include <string.h>

int main() {
    int count = 0;
    char arr[101];
    scanf("%s", arr);
    int len = strlen(arr);
    for (int i = 0; i < len - 1; i++) {
        switch (arr[i]) {
            case 'z':
            case 's':
                if (arr[i + 1] == '=') count++;
                break;
            case 'd':
                if (arr[i + 1] == '-') count++;
                if (arr[i + 1] == 'z' && arr[i + 2] == '=') count++;
                break;
            case 'c':
                if (arr[i + 1] == '-' || arr[i + 1] == '=') count++;
                break;
            case 'l':
            case 'n':
                if (arr[i + 1] == 'j') count++;
        }
    }
    printf("%d", len - count);
    return 0;
}