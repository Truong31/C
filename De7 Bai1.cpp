#include<stdio.h>
#include<math.h>
int kiemtra(int n){
	if(n<0) return 0;
	int kq=sqrt(n);
	if(pow(kq, 2)==n) return 1;
}
void xuat(int n){
	for(int i=0;i<=n;i++){
		if(kiemtra(i)==1){
			printf("%3d", i);
		}
	}
}
int main(){
	int n;
	scanf("%d", &n);
	xuat(n);
}
