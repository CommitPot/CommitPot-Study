#include <stdio.h>


int main(){
	int i, max=0, count;
	
	scanf("%d", &count);
	double study[count], avg=0;
	
	for(i=0;i<count;i++){
		scanf("%lf", &study[i]);
		if(study[i]>max)
			max=study[i];
	}
	
	for(i=0;i<count;i++){
		study[i]=study[i]/max*100;
		avg+=study[i];
	}
	avg/=count;
	printf("%lf",avg);
	
}
