#include<stdio.h>
int main(){
	int thang, nam;
	scanf("%d%d", &thang, &nam);
	switch(thang){
		case 1: case 3: case 5: case 7: case 8: case 10: case 12:
			printf("\nThang %d nam %d co 31 ngay ", thang, nam);
			break;
		case 4: case 6: case 9: case 11:
			printf("\nThang %d nam %d co 30 ngay ", thang, nam);
			break;
		case 2:
			if(nam%4==0||(nam%400==0&&nam%100!=0)){
				printf("\nThang %d nam %d co 29 ngay ", thang, nam);
			}
			else{
				printf("\nThang %d nam %d co 28 ngay", thang , nam);
			}
	}
}
