#include<stdio.h>
void nhapMang(int a, int n[100]){
	for(int i=0;i<a;i++){
		scanf("%d", &n[i]);
	}
}
void xuatMang(int a, int n[100]){
	for(int i=0;i<a;i++){
		printf("%d\t", n[i]);
	}
}
void SapXep(int a, int n[100]){
	int tg;
	for(int i=0;i<a;i++){
		for(int j=i+1;j<a;j++){
			if(n[i]>n[j]){
				tg=n[i];
				n[i]=n[j];
				n[j]=tg;
			}
		}
	}
}
int main(){
	int a, n[100];
	scanf("%d", &a);
	nhapMang(a, n);
	SapXep(a, n);
	xuatMang(a, n);
}
