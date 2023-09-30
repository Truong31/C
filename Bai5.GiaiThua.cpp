#include<stdio.h>
int main(){
	int n;
	int Giaithua=1;
	scanf("%d", &n);
	if(n==1||n==0){
		printf(" %d! = 1", n);
	}if(n>1){
		for(int i=1;i<=n;i++){
			Giaithua=Giaithua*i;
		}
	}
	printf("%d! = %d", n, Giaithua);
}
