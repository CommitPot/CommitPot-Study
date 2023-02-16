#include <stdio.h>
 
int main(){
    int arr[30] = {0};  
    for(int i=0; i<28; i++){
        int n;
        scanf("%d", &n);
        arr[n-1]++;
    }
 
    for(int j=0; j<30; j++){
        if(arr[j]==0)
            printf("%d\n", j+1);
    }
}
