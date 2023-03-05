#include <stdio.h>
#include <string.h>

int main() {
    int t =0;

    char S[20] = {0};

    scanf("%d", &t);

    for(int i=0; i<t; i++) {
        scanf("%s", &S);
        if(strlen(S) >= 6 && strlen(S) <= 9) {
            printf("yes");
        }
        else {
            printf("no");
        }
        printf("\n");
    }
}
