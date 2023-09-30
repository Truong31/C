#include<stdio.h>
#include<malloc.h>
#include<string.h>
struct Danhsach{
	char Ho_ten[20];
	int Tuoi;
	float Diem_toan, Diem_ly, Diem_hoa, Tong_diem;
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
void Khoi_tao(List *l){
	l->head=l->tail=NULL;
}
node *Tao_node(Danhsach x){
	node *p=(node*)malloc(sizeof(node));
	if(p==NULL){
		printf("Loi cap nhat ");
		return NULL;
	}
	p->data=x;
	p->next=NULL;
}
void chen_cuoi(list *l, node *p){
	if(l->head==NULL){
		l->head=l->tail=p;
	}else{
		l->tail->next=p;
		l->tail=p;
	}
}
void chen_giua(list *l, node *p, node *q){
	if(l->head==NULL){
		l->head=l->tail=NULL;
	}else{
		p->next=q->next;
		q->next=p;
	}
}
node *timKiem(list *l, char Ho_ten[20]){
	node *p=l->head;
	while(p!=NULL){
		if(strcmp(p->data.Ho_ten, Ho_ten)==0){
			return p;
		}
		p=p->next;
		}
	return NULL;
}
void xoa_node(list *l, char Ho_ten[20]){
	node *p=timKiem(l, Ho_ten);
	if(p!=NULL){
		if(p==l->head){
			l->head=p->next;
			free(p);
			return;
		}
		node *q;
		q->next=p->next;
		if(p==l->tail){
			l->tail=q;
		}
		free(p);
	}
}

void Nhap1Nguoi(Danhsach *x){
//	printf("\nNhap STT ");
//	scanf("%d", &x->STT);
	fflush(stdin);
	printf("\nNhap Ho ten ");
	gets(x->Ho_ten);
	printf("\nNhap Tuoi ");
	scanf("%d", &x->Tuoi);
	printf("\nNhap Diem Toan ");
	scanf("%f", &x->Diem_toan);
	printf("\nNhap Diem Ly ");
	scanf("%f", &x->Diem_ly);
	printf("\nNhap Diem Hoa ");
	scanf("%f", &x->Diem_hoa);
}
void Xuat1Nguoi(Danhsach x){
	printf(" %s \t %d \t %f \t %f \t %f \t %f \n", x.Ho_ten, x.Tuoi, x.Diem_toan, x.Diem_ly, x.Diem_hoa, x.Tong_diem=x.Diem_hoa+x.Diem_ly+x.Diem_toan);
}
int main(){
	list l;
	Danhsach x;
	node *p;
	char Ho_ten[20];
	Khoi_tao(&l);
	int a;
	printf("\nNhap So luong thi sinh ");
	scanf("%d", &a);
	for(int i=0;i<a;i++){
		Nhap1Nguoi(&x);
		p=Tao_node(x);
		chen_cuoi(&l, p);
	}
	node *p1=l.head;
	printf("\n \t DANH SACH SINH VIEN ");
	printf("\n STT \t Ho ten \t Tuoi \t Diem toan \t Diem Ly \t Diem hoa \t Tong diem \n");
	int stt=1;
	for(node* i=l.head;i!=NULL;i=i->next)
	{
		if((i->data.Diem_hoa+i->data.Diem_ly+i->data.Diem_toan)>=20){
			printf("%d\t", stt++);
			Xuat1Nguoi(i->data);
		}
	}
	fflush(stdin);
	printf("\nNhap Ten nguoi can xoa ");
	gets(Ho_ten);
	xoa_node(&l, Ho_ten);
	node *p2=l.head;
	while(p2!=NULL){
			Xuat1Nguoi(p2->data);
			p2=p2->next;
		}
	node *q=timKiem(&l, Ho_ten);
	Nhap1Nguoi(&x);
	node *q1=Tao_node(x);
	fflush(stdin);
	printf("\nNhap ten thi sinh can chen sau ");
	gets(Ho_ten);
	node *p3=l.head;
	while(p!=NULL){
		if(strcmp(p3->data.Ho_ten, Ho_ten)==0){
			chen_giua(&l, q1, p3);
			break;
		}else{
			p3=p3->next;
		}
	}
	node *q2=l.head;
	while(q2!=NULL){
			Xuat1Nguoi(q2->data);
			q2=q2->next;
	}
}







