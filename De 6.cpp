#include<stdio.h>
#include<malloc.h>
#include<string.h>

//Bai 1
//int KTso_nt(int x){
//	if(x<1) return 0;
//	for(int i=2;i<x-1;i++){
//		if(x%i==0) return 0;
//	}return 1;
//}
//void in_soNT(int x){
//	int dem=0;
//	scanf("%d", &x);
//	for(int i=1;i<=x;i++){
//		if(KTso_nt(i)==1){
//			dem++;
//			printf("%3d", i);
//		}
//	}printf("\nCo %d so nguyen to be hon n ", dem);
//}
//int main(){
//	int x;
//	in_soNT( x);
//}

//Bai 2
struct danhsach{
	int STT, Tuoi, So_CCCD;
	char Ho_ten[20]; 
	char Nghe_nghiep[20];
};
struct Node{
	danhsach data;
	Node *pnext;
};
typedef struct Node node;
struct List{
	node *phead;
	node *ptail;
};
typedef struct List list;

node *tao_node(danhsach x){
	node *p=(node*)malloc(sizeof(node));
	if(p==NULL){
		printf("Loi cap nhat");
		return NULL;
	}
	p->data=x;
	p->pnext=NULL;
	return p;
}
void khoi_tao(list *l){
	l->phead=l->ptail=NULL;
}
//void chen_cuoi(list *l, node *p){
//	if(l->head==NULL){
//		l->head=l->tail=p;
//	}
//	l->tail->next=p;
//	l->tail=p;
//}
void chen_dau(list *l, node *p){
	if(l->phead==NULL){
		l->phead=l->ptail=p;
	}else{
		p->pnext=l->phead;
		l->phead=p;
	}
}
void chen_giua(list *l, node *p, node *q){
	
	if(l->phead==NULL){
		l->phead=l->ptail=NULL;
	}else{
		p->pnext=q->pnext;
		q->pnext=p;
	}
}
node *xoa_node(node *l, int k){
	node *p=l;
	for(int i=0;i<k-1;i++){
		p=p->pnext;
	}
	node *temp=p->pnext;
	p->pnext=p->pnext->pnext;
	delete(temp);
	return l;
}
void nhap1Nguoi(danhsach *x){
	printf("\nNhap STT "); 
	scanf("%d", &x->STT);
	printf("\nNhap So CCCD "); 
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
void xuat1Nguoi(danhsach x){
	printf("%d \t %d \t %s \t %d \t %s \n", x.STT, x.So_CCCD, x.Ho_ten, x.Tuoi, x.Nghe_nghiep);
}
int main(){
	list l;
	khoi_tao(&l);
	node *p;
	danhsach x;
	while(1){
		printf("1.Tao danh sach\n");
		printf("2.Hien thi danh sach\n");
		printf("3.Chen nguoi dang ky\n");
		printf("4.Xoa 1 nguoi dang ky\n");
		printf("5.Ket thuc\n");
		int z;
		printf("Nhap lua chon "); 
		scanf("%d", &z);
		if(z==1){
			int b;
			printf("Nhap so nguoi dang ky ");
			scanf("%d", &b);
			for(int i=0;i<b;i++){
				nhap1Nguoi(&x);
				p=tao_node(x);
				chen_dau(&l, p);
			}
		}else if(z==2){
			node *q=l.phead;
			printf("DANH SACH DANG KY TIEM VACXIN COVID\n ");
			printf("STT \t So CCCD \t Ho ten \t Tuoi \t Nghe nghiep \n");
			while(q!=NULL){
				xuat1Nguoi(q->data);
				q=q->pnext;
			}
		}else if(z==3){
			nhap1Nguoi(&x);
			node *q1=tao_node(x);
			int a;
			printf("\nNhap so CCCD cua node can chen sau ");
			scanf("%d", &a);
			node *p=l.phead;
			while(p!=NULL){
				if(a==p->data.So_CCCD){
					chen_giua(&l, q1, p);
					break;
				}else{
					p=p->pnext;
				}
			}	
//			node *p1=l.head;
//			while(p1!=NULL){
//				xuat1Nguoi(p1->data);
//				p1=p1->next;
//			}
		}
		else if(z==4){
			node *p2;
			int c;
			printf("\nNhap so CCCD cua nguoi can xoa ");
			scanf("%d", &c);
			if(c==p2->data.So_CCCD){
				xoa_node(&l, p2);
			}
		}else if(z==5){
			break;
		}
	}
}








