#include<stdio.h>
int kiemtra(int n){
	if(n<=1) return 0;
	for(int i=2;i<n-1;i++){
		if(n%i==0) return 0;
	}return 1;
}
void insont(int n){
	for(int i=1;i<=n;i++){
		if(kiemtra(i)==1)
		printf("%6d", i);
	}
}
int main(){
	int n;
	scanf("%d", &n);
	insont( n);
}
