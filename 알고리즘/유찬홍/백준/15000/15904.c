#include <stdio.h>
#include <string.h>

int main() {
    char arr[1001], ucpc[] = "UCPC";
    scanf("%[^\n]s", arr);
    int len = strlen(arr), index = 0, count = 0;
    for (int i = 0; i < len; i++) {
        if (arr[i] == ucpc[index]){
            index++;
            count++;
        }
    }
    if (count == 4) printf("I love UCPC");
    else printf("I hate UCPC");
    return 0;
}