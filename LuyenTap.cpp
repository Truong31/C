//#include<stdio.h>
//#include<malloc.h>
//#include<string.h>
//struct danhsach{
//	char Ho_ten[50], Nghe_nghiep[20];
//	int Tuoi;
//	float Diem_Toan, Diem_Ly, Diem_hoa;
//};
//struct Node{
//	danhsach data;
//	Node *next;
//};
//typedef struct Node node;
//struct List{
//	node *head;
//	node *tail;
//};
//typedef struct List list;
//void Khoi_tao(list *l){
//	l->head=l->tail=NULL;
//}
//node *Tao_node(danhsach x){
//	node *p=(node*)malloc(sizeof(node));
//	if(p==NULL){
//		printf("Loi cap nhat ");
//		return NULL;
//	}
//	p->data=x;
//	p->next=NULL;
//	return p;
//}
//void chen_cuoi(list *l, node *p){
//	if(l->head==NULL){
//		l->head=l->tail=p;
//	}else{
//		l->tail->next=p;
//		l->tail=p;
//	}
//}
//void nhap1nguoi(danhsach *x){
//	fflush(stdin);
//	printf("\nNhap ho ten ");
//	gets(x->Ho_ten);
//	printf("\nNhap tuoi ");
//	scanf("%d", &x->Tuoi);
//	fflush(stdin);
//	printf("\nNhap nghe nghiep ");
//	gets(x->Nghe_nghiep);
//	printf("\nNhap diem Toan ");
//	scanf("%f", &x->Diem_Toan);
//	printf("\nNhap diem Ly ");
//	scanf("%f", &x->Diem_Ly);
//	printf("\nNhap diem Hoa ");
//	scanf("%f", &x->Diem_hoa);
//}
//void xuat1nguoi(danhsach x){
//	printf("%s \t %d \t %s \t %f \t %f \t %f \t %f \n", x.Ho_ten, x.Tuoi, x.Nghe_nghiep, x.Diem_Toan, x.Diem_Ly, x.Diem_hoa, x.Diem_hoa+x.Diem_Ly+x.Diem_Toan);
//}
//node *Timkiem(list *l, char HoTen[50]){
//	for(node *p=l->head;p!=NULL;p=p->next){
//		if(strcmp(p->data.Ho_ten, HoTen)==0){
//			return p;
//			break;
//		}
//	}
//	return NULL;
//}
//void xoaThiSinh(list *l, char HoTen[50]){
//	node *p=Timkiem(l, HoTen);
//	while(p!=NULL){
//		if(p==l->head){
//			l->head=p->next;
//			free(p);
//			return;
//		}
//		node *q;
//		q->next=p->next;
//		if(p==l->tail){
//			l->tail=q;
//		}
//		free(p);
//	}
//}
//void chenGiua(list *l, node *p, node *q){
//	if(l->head==NULL){
//		l->head=l->tail=p;
//	}else{
//		p->next=q->next;
//		q->next=p;
//	}
//}
//void SuaThongTin(list *l, char HoTen[50] , char NgheNghiep[20]){
//	node *p=Timkiem(l, HoTen);
//	if(p!=NULL){
//		strcpy(p->data.Nghe_nghiep, NgheNghiep);
//	}else{
//		printf("Khong tim thay ");
//	}
//}
//void sapXepTongDiem(list *l){
//	danhsach x;
//	node *q=Tao_node(x);
//	for(node *i=l->head;i!=NULL;i=i->next){
//		for(node *j=i->next;j!=NULL;j=j->next){
//			if((i->data.Diem_hoa+i->data.Diem_Ly+i->data.Diem_Toan)>(j->data.Diem_hoa+j->data.Diem_Ly+j->data.Diem_Toan)){
//				q->data=i->data;
//				i->data=j->data;
//				j->data=q->data;
//			}
//		}
//	}
//}
//void sapXepToan(list *l){
//	danhsach x;
//	node *q=Tao_node(x);
//	for(node *i=l->head;i!=NULL;i=i->next){
//		for(node *j=i->next;j!=NULL;j=j->next){
//			if(i->data.Diem_Toan>j->data.Diem_Toan){
//				q->data=i->data;
//				i->data=j->data;
//				j->data=q->data;
//			}
//		}
//	}
//}
//void sapXepLy(list *l){
//	danhsach x;
//	node *q=Tao_node(x);
//	for(node *i=l->head;i!=NULL;i=i->next){
//		for(node *j=i->next;j!=NULL;j=j->next){
//			if(i->data.Diem_Ly>j->data.Diem_Ly){
//				q->data=i->data;
//				i->data=j->data;
//				j->data=q->data;
//			}
//		}
//	}
//}
//void sapXepHoa(list *l){
//	danhsach x;
//	node *q=Tao_node(x);
//	for(node *i=l->head;i!=NULL;i=i->next){
//		for(node *j=i->next;j!=NULL;j=j->next){
//			if(i->data.Diem_hoa>j->data.Diem_hoa){
//				q->data=i->data;
//				i->data=j->data;
//				j->data=q->data;
//			}
//		}
//	}
//}
//int main(){
//	list l;
//	Khoi_tao(&l);
//	danhsach x;
//	node *p;
//	char HoTen[50], NgheNghiep[20];
//	while(1){
//		printf("1.Nhap danh sach\n");
//		printf("2.Xuat danh sach\n");
//		printf("3.Xoa thi sinh\n");
//		printf("4.Them thi sinh\n");
//		printf("5.Sua thi sinh\n");
//		printf("6.Sap xep danh sach\n");
//		printf("0.Ket thuc\n");
//		int chon, STT=0;
//		printf("Nhap lua chon ");
//		scanf("%d", &chon);
//		if(chon==1){
//			int n;
//			printf("\nNhap so luong thi sinh ");
//			scanf("%d", &n);
//			for(int i=0;i<n;i++){
//				nhap1nguoi(&x);
//				p=Tao_node(x);
//				chen_cuoi(&l, p);
//			}
//		}else if(chon==2){
//			for(node *i=l.head;i!=NULL;i=i->next){
//				if((i->data.Diem_hoa+i->data.Diem_Ly+i->data.Diem_Toan)>=20){
//					STT++;
//					printf("%d\t", STT);
//					xuat1nguoi(i->data);
//				}
//			}
//		}else if(chon==3){
//			fflush(stdin);
//			printf("\nNhap ten nguoi can xoa ");
//			gets(HoTen);
//			xoaThiSinh(&l, HoTen);
//		}
//		else if(chon==4){
//			nhap1nguoi(&x);
//			fflush(stdin);
//			printf("\nNhap ho ten nguoi muon chen sau");
//			gets(HoTen);
//			node *q=Tao_node(x);
//			node *p=Timkiem(&l, HoTen);
//			for(p=l.head;p!=NULL;p=p->next){
//				if(strcmp(p->data.Ho_ten, HoTen)==0){
//					chenGiua(&l, q, p);
//					break;
//				}
//			}
//		}else if(chon==5){
//			fflush(stdin);
//			printf("\nNhap ho ten nguoi muon sua ");
//			gets(HoTen);
//			printf("\nNhap thong tin can sua ");
//			gets(NgheNghiep);
//			SuaThongTin(&l, HoTen, NgheNghiep);
//		}else if(chon==6){
//			while(2){
//				printf("\n1.Sap xep theo diem Toan");
//				printf("\n2.Sap xep theo diem Ly");
//				printf("\n3.Sap xep theo diem Hoa");
//				printf("\n4.Sap xep theo Tong diem");
//				printf("\nNhap lua chon ");
//				int a;
//				scanf("%d", &a);
//				if(a==1){
//					sapXepToan(&l);
//					break;
//				}else if(a==2){
//					sapXepLy(&l);
//					break;
//				}else if(a==3){
//					sapXepHoa(&l);
//					break;
//				}else if(a==4){
//					sapXepTongDiem(&l);
//					break;
//				}
//			}
//		}else if(chon==0){
//			break;
//		}
//	}
//}


#include<stdio.h>
int main(){
	int n=10, m=20;
	printf("n tren = %d, m tren = %d", n, m);
	{
		int n=30, p=60;
		m=m*5;
		printf("\n n trong = %d, m trong = %d, p trong = %d", n, m, p);
	}
	printf("\n n duoi = %d, m duoi = %d", n, m);
}
