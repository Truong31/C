#include<stdio.h>
#include<malloc.h>
//void nhapmang(int a[], int n){
//	for(int i=0;i<n;i++){
//		scanf("%d", &a[i]);
//	}
//}
//int timkiem(int a[], int n, int tk){
//	int kq=0;
//	for(int i=0;i<n;i++){
//		if(a[i]==tk){
//			kq=1;
//			return 1;
//		}
//	}return kq;
//}
//void THtimkiem(int a[], int n){
//	int tk;
//	int dem=0;
//	scanf("%d", &tk);
//	if(timkiem(a, n, tk)==1){
//		printf("Tim thay");
//	}else printf("Khong tim thay");
//	for(int i=0;i<n;i++){
//		if(a[i]==tk)
//			dem++;
//	}
//	printf("\nSo lan xuat hien %d", dem);
//}
//int main(){
//	int n, x;
//	int a[n];
//	scanf("%d", &n);
//	nhapmang(a, n);
//	printf("\n");
//	timkiem(a, n, x);
//	THtimkiem(a, n);
//}


struct Danhsach{
	int STT, so_bao_danh;
	float diem_toan, diem_ly, diem_tieng_anh, tong_diem;
	char ho_ten[20];
};
struct Node{
	Danhsach data;
	Node *next;
};
typedef struct Node node;
struct List{
	node *head;
	node *tail;
};
typedef struct List list;
void khoitao(list *l){
	l->head=NULL;
	l->tail=NULL;
}
node *tao_node(Danhsach x){
	node *p=(node*)malloc(sizeof(node));
	if(p==NULL){
		printf("Loi cap nhat");
		return NULL;
	}
	p->data=x;
	p->next=NULL;
	return p;
}
void chen_dau(list *l, node *p){
	if(l->head==NULL){
		l->head=l->tail=p;
	}else{
		p->next=l->head;
		l->head=p;
	}
}
void chen_cuoi(list *l, node *p){
	if(l->head==NULL){
		l->head=l->tail=p;
	}
	else{
		l->tail->next=p;
		l->tail=p;
	}
}
void chen_giua(node *p, node *q, list *l){
	if(q!=NULL){
		p->next=q->next;
		q->next=p;
		if(q==l->tail){
			l->tail=p;
		}
	}else{
		chen_dau(l, p);
	}
}

void nhapThongTin(list *l){
	int n;
	printf("Nhap vao so luong hoc sinh ");
	scanf("%d", &n);
	for(int i=0;i<n;i++){
		Danhsach x;
		node *p;
		printf("\nNhap STT "); 
		scanf("%d", &x.STT);
		printf("\nNhap SBD "); 
		scanf("%d", &x.so_bao_danh);
		fflush(stdin);
		printf("\nNhap Ho ten "); 
		gets(x.ho_ten);
		printf("\nNhap Diem Toan "); 
		scanf("%f", &x.diem_toan);
		printf("\nNhap Diem Ly "); 
		scanf("%f", &x.diem_ly);
		printf("\nNhap Diem Tieng Anh "); 
		scanf("%f", &x.diem_tieng_anh);
		p=tao_node(x);
		chen_cuoi(l, p);
	}
	
}
void xuatDanhSach(list *l){
	node *p;
	printf("\tANH SACH DIEM THI THPT\n ");
	printf("STT \t SBD \t Ho ten \t Diem Toan \t Diem Ly \t Diem Tieng Anh \t Tong diem\n");
	for(p=l->head;p!=NULL;p=p->next){
		printf("%d \t %d \t %s \t %f \t %f \t %f \t %f\n", p->data.STT, p->data.so_bao_danh, p->data.ho_ten, p->data.diem_toan, p->data.diem_ly, p->data.diem_tieng_anh, p->data.tong_diem=p->data.diem_toan+p->data.diem_ly+p->data.diem_tieng_anh);
	}
}
int main(){
	list l;
	khoitao(&l);
	while(1){
		printf("1.Tao danh sach thi sinh\n");
		printf("2.Hien thi danh sach thi sinh\n");
		printf("3.Sap xep thi sinh\n");
		printf("4.Ket thuc\n");
		int n;
		printf("Nhap lua chon ");
		scanf("%d", &n);
		if(n==1){
			nhapThongTin(&l);
		}else if(n==2){
			xuatDanhSach(&l);
		}else if(n==3){
			printf("------");
		}else if(n==4){
			break;
		}
	}
}

























