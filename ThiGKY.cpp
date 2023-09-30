#include<stdio.h>
#include<malloc.h>
#include<string.h>
struct Danhsach{
	int Tuoi;
	char Ho_ten[50], Nghe_nghiep[50];
	float Diem_toan, Diem_ly, Diem_hoa;
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
void Khoi_tao(list *l){
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
node *TimKiem(list *l, char Ho_ten[50]){
	node *p=l->head;
	while(p!=NULL){
		if(strcmp(p->data.Ho_ten, Ho_ten)==0){
		return p;
		}
		p=p->next;
	}
	return NULL;
}
void Chen_cuoi(list *l, node *p){
	if(l->head==NULL){
		l->head=l->tail=p;
	}else{
		l->tail->next=p;
		l->tail=p;
	}
}
void Chen_giua(list *l, node *p, node *q){
	if(l->head==NULL){
		l->head=l->tail=p;
	}else {
		p->next=q->next;
		q->next=p;
	}
}
void Xoa_phantu(list *l, char Ho_ten[50]){
	node *p=TimKiem(l, Ho_ten);
	while(p!=NULL){
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
void Sap_xep(list *l){
	Danhsach x;
	node *q=Tao_node(x);
	for(node *i=l->head;i!=NULL;i=i->next){
		for(node *j=i->next;j!=NULL;j=j->next){
			if((i->data.Tuoi)>(j->data.Tuoi)){
				q->data=i->data;
				i->data=j->data;
				j->data=q->data;
			}
		}
	}
}
void SuaThongTin(list *l, char Ho_ten[50], char NgheNghiep[50]){
	node *p=TimKiem(l, Ho_ten);
	if(p!=NULL){
		strcpy(p->data.Nghe_nghiep, NgheNghiep);
	}else{
		printf("\nkhong tim thay");
	}
}
void Nhap1Nguoi(Danhsach *x){
	fflush(stdin);
	printf("Nhap Ho ten ");
	gets(x->Ho_ten);
	printf("\nNhap Tuoi ");
	scanf("%d", &x->Tuoi);
	fflush(stdin);
	printf("Nhap Nghe Nghiep ");
	gets(x->Nghe_nghiep);
	printf("\nNhap Diem Toan ");
	scanf("%f", &x->Diem_toan);
	printf("\nNhap Diem Ly ");
	scanf("%f", &x->Diem_ly);
	printf("\nNhap Diem Hoa ");
	scanf("%f", &x->Diem_hoa);
}
void Xuat1Nguoi(Danhsach x){
	printf("%15s %10d %10s %10f %10f %10f %10f \n", x.Ho_ten, x.Tuoi, x.Nghe_nghiep, x.Diem_toan, x.Diem_ly, x.Diem_hoa, (x.Diem_hoa+x.Diem_ly+x.Diem_toan));
}
int main(){
	list l;
	Danhsach x;
	Khoi_tao(&l);
	node *p;
	char Ho_ten[50], NgheNghiep[50];
	while(1){
		printf("1.Nhap danh sach \n");
		printf("2.Xuat danh sach \n");
		printf("3.Chen thi sinh \n");
		printf("4.Xoa thi sinh \n");
		printf("5.Sap xep thi sinh \n");
		printf("6.Sua thong tin thi sinh \n");
		printf("0.Ket thuc \n");
		int Chon, STT=0;
		printf("Nhap lua chon ");
		scanf("%d", &Chon);
		if(Chon==1){
			int a;
			printf("\nNhap so luong thi sinh ");
			scanf("%d", &a);
			for(int i=0;i<a;i++){
				Nhap1Nguoi(&x);
				p=Tao_node(x);
				Chen_cuoi(&l, p);
			}
		}else if(Chon==2){
			node *p=l.head;
			printf("\t \n DANH SACH THI SINH \n");
			printf("STT \t Ho ten \t Tuoi \t Nghe nghiep \t Diem Toan \t Diem Ly \t Diem Hoa \t Tong Diem \n");
			while(p!=NULL){
				if((p->data.Diem_hoa+p->data.Diem_ly+p->data.Diem_toan)>=20){
					STT++;
					printf("%d\t", STT);
					Xuat1Nguoi(p->data);
					
				}p=p->next;
			}
		}else if(Chon==3){
			Nhap1Nguoi(&x);
			fflush(stdin);
			printf("\nNhap ho ten nguoi can chen sau ");
			gets(Ho_ten);
			node *p=TimKiem(&l, Ho_ten);
			node *q=Tao_node(x);
			while(p!=NULL){
				Chen_giua(&l, q, p);
				p=p->next;
				break;
			}
		}else if(Chon==4){
			fflush(stdin);
			printf("\nNhap Ho ten nguoi can xoa ");
			gets(Ho_ten);
			Xoa_phantu(&l, Ho_ten);
		}else if(Chon==5){
			Sap_xep(&l);
		}else if(Chon==6){
			fflush(stdin);
			printf("\nNhap Ho ten nguoi can sua ");
			gets(Ho_ten);
			printf("\nSua lai Nghe nghiep ");
			gets(NgheNghiep);
			SuaThongTin(&l, Ho_ten, NgheNghiep);
		}else if(Chon==0){
			break;
		}
	}
}








































	
