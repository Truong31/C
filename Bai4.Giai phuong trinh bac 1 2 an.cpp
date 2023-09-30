#include<stdio.h>
int main(){
	float a1, b1, c1, a2, b2, c2;
	printf("a1*x + b1*y = c1\n");
	printf("a2*x + b2*y = c2\n");
	printf("Nhap he so a1: "); scanf("%f", &a1);
	printf("\nNhap he so b1: "); scanf("%f", &b1);
	printf("\nNhap he so c1: "); scanf("%f", &c1);
	printf("\nNhap he so a2: "); scanf("%f", &a2);
	printf("\nNhap he so b2: "); scanf("%f", &b2);
	printf("\nNhap he so c2: "); scanf("%f", &c2);
	float D=a1*b2-a2*b1;
	float Dx=b2*c1-c2*b1;
	float Dy=a1*c2-c1*a2;
	if(D==0){
		if(Dx+Dy==0){
			printf("\nHe phuong trinh co vo so nghiem ");
		}
		else {
			printf("\nHe phuong trinh vo nghiem");
		}
	}
	else {
		printf("\nHe phuong trinh co 2 nghiem phan biet (x, y) = (%.2f, %.2f)", Dx/D, Dy/D );
	}
}
