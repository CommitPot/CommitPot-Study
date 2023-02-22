#include <stdio.h>
#include <string.h>


int main() {
    int c = 0;
    char arr[251], arr1[251], a = 0;
    scanf("%s", arr);
    int len = strlen(arr);
    for (int i = 0; i <= len; i++) {
        if (a != arr[i]){
            a = arr[i];
            arr1[c++] = arr[i];
        }
    }
    printf("%s", arr1);
    return 0;
}