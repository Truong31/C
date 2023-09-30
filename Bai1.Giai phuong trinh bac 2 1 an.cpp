#include<stdio.h>
#include<math.h>
int main(){
	float a, b, c, x;
	scanf("%f%f%f", &a, &b, &c);
	if(a==0){
		printf("\nNghiem phuong trinh la %.2f", x=-c/b);
	}
	if(a==0&&b==0&&c==0){
		printf("\nPhuong trinh co vo so nghiem ");
	}
	if(a==0&&b==0){
		printf("\nPhuong trinh vo nghiem ");
	}
	if(a!=0){
		float delta=b*b-4*a*c;
		if(delta>0){
			printf("\nPhuong trinh co 2 nghiem phan biet la ");
			printf("%.2f  %.2f", (-b+sqrt(delta))/(2*a), (-b-sqrt(delta))/(2*a));
		}else if(delta==0){
			printf("\nPhuong trinh co nghiem kep ");
			printf("%.2f", -b/(2*a));
		}else{
			printf("\nPhuong trinh vo nghiem ");
		}
	}
}
