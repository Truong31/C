#include<stdio.h>
#include<malloc.h>
struct danhsach{
	int STT, so_CCCD, Tuoi;
	char Hoten[20], Nghe_nghiep[10];
};
typedef struct danhsach ds;
struct Node{
	ds data;
	Node *next;
};
typedef struct Node node;
struct List{
	node *head;
	node *tail;
};
typedef struct List list;
void init(list *l){
	l->head=NULL;
	l->tail=NULL;
}
node *createnode(ds x){
	node *p=(node*)malloc(sizeof(node));
	if(p==NULL){
		printf("Loi cap nhat "); 
		return NULL;
	}
	p->data=x;
	p->next=NULL;
	return p;
}
void ChenCuoi (list *l, node *p){
    if (l->head==NULL) {
        l->head=l->tail=p;
    }
    else {
        l->tail->next=p;
        l->tail=p;
    }
}

//void insert_head(list &l, node *p){
//	if(l.head==NULL){
//		l.head=l.tail=p;
//	}
//	p->next=l.head;
//	l.head=p;
//}
void nhapDS(list *l, int n){
	printf("\nNhap vao so nguoi dang ky ");
	scanf("%d", &n);
	for(int i=0;i<n;i++){
		ds x;
		printf("Nhap STT "); 
		scanf("%d", &x.STT);
		printf("\nNhap so CCCD ");
		scanf("%d", &x.so_CCCD);
		fflush(stdin);
		printf("\nNhap Ho ten ");
		gets(x.Hoten);
		printf("\nNhap Tuoi ");
		scanf("%d", &x.Tuoi);
		fflush(stdin);
		printf("\nNhap Nghe nghiep ");
		gets(x.Nghe_nghiep);
		node *p;
		p=createnode(x);
		ChenCuoi(l, p);

	}
}
void xuatDS(list *l){
	printf("DANH SACH DANG KY TIEM VACXIN COVID\n");
	printf("STT \t So CCCD \t Ho ten \t Tuoi \t Nghe nghiep\n ");
	for(node *p=l->head;p!=NULL;p=p->next){
		printf("%d %10d %20s %10d %10s\n ", p->data.STT, p->data.so_CCCD, p->data.Hoten, p->data.Tuoi, p->data.Nghe_nghiep);
	}
}
int main(){
	list l;
	init(&l);
	int a;
	while(1){
		printf("-----------------------\n");
		printf("1.Tao danh sach\n");
		printf("2.Hien thi danh sach\n");
		printf("3.Chen nguoi dang ky\n");
		printf("4.Ket thuc\n");
		printf("-----------------------\n");
		int n;
		printf("Nhap lua chon ");
		scanf("%d", &n);
		if(n==1){	
			nhapDS(&l, a);
		}else if(n==2){
			xuatDS(&l);
		}else if(n==3){
			printf("-----");
		}else if(n==4){
			break;
		}
	}
}

