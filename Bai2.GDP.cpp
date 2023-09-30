#include<stdio.h>
#include<math.h>
int main(){
	int dem=2014;
	float GDP, a;
	scanf("%f%f", &GDP, &a);
	printf("\nNam  \t  GDP\n");
	for(int i=1;;i++){
		float TongGDP=GDP*pow((1+a), i);
		++dem;
		printf("%d  \t  %.2f\n", dem, TongGDP);
		if(TongGDP>=2*GDP){
			break;
		}
	}
}
