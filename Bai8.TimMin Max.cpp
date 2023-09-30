#include<stdio.h>
void nhapMang(int a, int x[100]){
	for(int i=0;i<a;i++){
		scanf("%d", &x[i]);
	}
}
void xuatMang(int a, int x[100]){
	for(int i=0;i<a;i++){
		printf("%6d", x[i]);
	}
}
int TimMax(int a, int x[100]){
	int Max=x[0];
	for(int i=0;i<a;i++){
		if(Max<x[i]){
			Max=x[i];
		}
	}
	return Max;
}
int TimMin(int a, int x[100]){
	int Min=x[0];
	for(int i=0;i<a;i++){
		if(Min>x[i]){
			Min=x[i];
		}
	}
	return Min;
}
int main(){
	int a, x[100];
	scanf("%d", &a);
	nhapMang(a, x);
	xuatMang(a, x);
	printf("\nPhan tu lon nhat cua mang la %d", TimMax(a, x));
	printf("\nPhan tu nho nhat cua mang la %d", TimMin(a, x));
}
