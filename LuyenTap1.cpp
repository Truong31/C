#include<stdio.h>
void nhapMang(int a[], int n){
	for(int i=0;i<n;i++){
		scanf("%d", &a[i]);
	}
}
void xuatMang(int a[], int n){
	for(int i=0;i<n;i++){
		printf("%5d", a[i]);
	}
}
int TimKiem(int a[], int n, int tk){
	int kq=0;
	for(int i=0;i<n;i++){
		if(a[i]==tk){
			kq=1;
			return 1;
		}
	}
	return kq;
}
void ThucHienTK(int a[], int n){
	int tk, dem=0;
	scanf("%d", &tk);
	if(TimKiem(a, n, tk)==1){
		printf("Tim Thay ");
	}
	for(int i=0;i<n;i++){
		if(a[i]==tk)
		dem++;
	}
	printf("%d", dem);
}
int main(){
	int a[100], n;
	scanf("%d", &n);
	nhapMang(a, n);
	xuatMang(a, n);
	printf("\n");
	ThucHienTK(a, n);
}
