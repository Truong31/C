#include<stdio.h>
#include<math.h>
void nhapHeSo(float n, float a[100]){
	for(int i=0;i<n;i++){
		scanf("%f", &a[i]);
	}
}
void inHeSo(float n, float a[100]){
	for(int i=0;i<n;i++){
		printf("%6.2f", a[i]);
	}
}
float TinhGiaTriDaThuc(float n, float a[100], float x){
	float GiaTri=1;
	for(int i=0;i<n;i++){
		GiaTri+=a[i]*pow(x, i);
	}
	return GiaTri;
}
int main(){
	float m, n, a[100], b[100];
	while(1){
		printf("\n1.Nhap he so cua 1 da thuc\n");
		printf("2.In he so cua 1 da thuc\n");
		printf("3.Tinh gia tri cua 1 da thuc va in ra man hinh\n");
		printf("4.Tinh he so cua da thuc tong\n");
		int chon;
		printf("Nhap lua chon ");
		scanf("%d", &chon);
		if(chon==1){
			printf("\nNhap so he so cua da thuc A: ");
			scanf("%f", &m);
			nhapHeSo(m, a);
			printf("\nNhap so he so cua da thuc B: ");
			scanf("%f", &n);
			nhapHeSo(n, b);
		}
		else if(chon==2){
			printf("\nHe so cua da thuc A la: ");
			inHeSo(m, a);
			printf("\nHe so cua da thuc B la: ");
			inHeSo(n, b);
		}
		else if(chon==3){
			float x;
			printf("\nNhap gia tri cua x: ");
			scanf("%f", &x);
			printf("\nGia tri cua da thuc A la: %.2f", TinhGiaTriDaThuc(m, a, x));
		}
	}
	
}
