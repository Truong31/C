#include<stdio.h>
int main(){
	float a, b, c;
	scanf("%f%f%f", &a, &b, &c);
	if(((a+b)>c)&&((a+c)>b)&&((c+b)>a))	{
		if((a==b)&&(b==c)){
			printf("\nLa tam giac deu ");
		}
		else if(a==b||b==c||a==c){
			printf("\nLa tam giac can ");
		}
		else if((a==b||b==c||a==c)&&((a*a==b*b+c*c)||(b*b==a*a+c*c)||(c*c==a*a+b*b))){
			printf("\nLa Tam giac vuong can ");
		}
		else if((a*a==b*b+c*c)||(b*b==a*a+c*c)||(c*c==a*a+b*b)){
			printf("\nLa tam giac vuong ");
		}
		else{
			printf("\nla tam giac thuong ");
		}
	}
	else printf("\nKhong phai la 3 canh cua tam giac ");
}
