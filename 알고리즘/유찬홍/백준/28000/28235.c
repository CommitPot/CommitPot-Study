#include <stdio.h>
#include <string.h>

int main() {
    char arr[100];
    scanf("%s", arr);
    if (!strcmp("SONGDO", arr)) printf("HIGHSCHOOL");
    else if (!strcmp("CODE", arr)) printf("MASTER");
    else if (!strcmp("2023", arr)) printf("0611");
    else printf("CONTEST");
}
