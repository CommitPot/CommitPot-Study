#include <stdio.h>

int main(){
    int time, drink;
    scanf("%d %d", &time, &drink);

    if((time >= 12 && time <= 16) && drink == 0 ) {
        printf("320");
    }
    else if(drink == 1 || !(time >= 12 && time <= 16)) {
        printf("280");
    }
    return 0;
}