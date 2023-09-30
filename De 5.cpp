#include<stdio.h>
#include<malloc.h>
#include<string.h>
struct Danhsach{
	int STT, So_CCCD, Tuoi;
	char Ho_ten[20], Nghe_nghiep[20];
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
void Khoi_Tao(list *l){
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
	return p;
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
node *timKiem(list *l, int So_CCCD){
	node *p=l->head;
	while(p!=NULL){
		if(So_CCCD==p->data.So_CCCD){
			return p;
		}
		p=p->next;
	}
	return NULL;
}
void xoa_node(list *l, int So_CCCD){
	node *p=timKiem(l, So_CCCD);
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
void suaThongTin(list *l , int So_CCCD, char NgheNghiep[20]){
	node *p=timKiem(l, So_CCCD);
	if(p!=NULL){
		strcpy(p->data.Nghe_nghiep, NgheNghiep);
	}else{
		printf("Khong tim thay ");
	}
}
void Nhap1Nguoi(Danhsach *x){
	printf("Nhap STT ");
	scanf("%d", &x->STT);
	printf("\nNhap so CCCD ");
	scanf("%d", &x->So_CCCD);
	fflush(stdin);
	printf("\nNhap Ho ten ");
	gets(x->Ho_ten);
	printf("\nNhap Tuoi ");
	scanf("%d", &x->Tuoi);
	fflush(stdin);
	printf("\nNhap nghe nghiep ");
	gets(x->Nghe_nghiep);
}
void Xuat1Nguoi(Danhsach x){
	printf("%d \t %d \t %s \t %d \t %s \n", x.STT, x.So_CCCD, x.Ho_ten, x.Tuoi, x.Nghe_nghiep);
}
int main(){
	list l;
	Khoi_Tao(&l);
	node *p;
	Danhsach x;
	int So_CCCD;
	while(1){
		printf("1.Nhap Danh sach\n");
		printf("2.Xuat danh sach\n");
		printf("3.Chen nguoi dang ky\n");
		printf("4.Tim kiem nguoi dky\n");
		printf("5.Xoa 1 nguoi dky\n");
		printf("6.Sua thong tin\n");
		printf("0.Ket thuc\n");
		int a;
		printf("Nhap lua chon ");
		scanf("%d", &a);
		if(a==1){
			int b;
			printf("\nNhap so nguoi dang ky ");
			scanf("%d", &b);
			for(int i=0;i<b;i++){
				Nhap1Nguoi(&x);
				p=Tao_node(x);
				chen_cuoi(&l, p);
			}
		}else if(a==2){
			printf("DANH SACH DANG KY TIEM VACXIN COVID \n ");
			printf("STT \t So CCCD \t Ho ten \t Tuoi \t Nghe nghiep\n ");
			node *q1=l.head;
			while(q1!=NULL){
				Xuat1Nguoi(q1->data);
				q1=q1->next;
			}
		}else if(a==3){
			Nhap1Nguoi(&x);
			node *q=Tao_node(x);
			
			int c;
			printf("\nNhap so CCCD can chen sau ");
			scanf("%d", &c);
			node *p=l.head;
			while(p!=NULL){
				if(c==p->data.So_CCCD){
					chen_giua(&l, q, p);
					break;
				}else{
					p=p->next;
				}
			}
		}
		else if(a==4){
			printf("Nhap So CCCD can tim kiem");
			scanf("%d", &So_CCCD);
			node *p=timKiem(&l, So_CCCD);
			if(p!=NULL){
				Xuat1Nguoi(p->data);
			}else{
			printf("Khong tim thay");
				}
		}else if(a==5){
			printf("Nhap so CCCD cua nguoi can xoa ");
			scanf("%d", &So_CCCD);
			xoa_node(&l, So_CCCD);
		}
		else if(a==6){
			printf("\nNhap so CCCD cua nguoi can sua ");
			scanf("%d", &So_CCCD);
			printf("\nNhap nghe nghiep can sua ");
			char NgheNghiep[20];
			scanf("%d", &NgheNghiep);
			suaThongTin(&l, So_CCCD, NgheNghiep);
		}else if(a==0){
			break;
		}
	}
}
