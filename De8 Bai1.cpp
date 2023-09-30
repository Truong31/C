#include<stdio.h>
#include<math.h>
int main(){
//	float A;
//	scanf("%f", &A);
//	printf("%.0f", log(1.5)/log(1.008));	
	int A;
	float a;
	scanf("%d", &A);
	for(int i=1;;i++){
		a=A*pow(1.008, i);
		if(a>=1.5*A){
			printf("%d", i);
			break;		
		}
	}
}
