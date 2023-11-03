#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>

struct sinhvien{
    char ten[100];
    char lop[100];
    double gpa;
};

typedef struct sinhvien sv;

void inp(sv *x){
	getchar();
    printf("Nhap ten : "); gets(x->ten);
    printf("Nhap lop : "); gets(x->lop);
    printf("Nhap GPA : "); scanf("%lf",&x->gpa);
}

void outp(sv x){
    printf("%s %s %lf\n", x.ten, x.lop, x.gpa);
}

void find(sv a[], int n, char name[]){
    int check=0;
    for(int i=0; i<n; i++){
        if(strcmp(a[i].ten,name)==0){
            outp(a[i]);
            check=1;
        }
    }
    if(!check) printf("Khong tim thay sinh vien !\n");
}

void maxgpa(sv a[], int n){
    double max=0;
    for(int i=0; i<n; i++){
        max=fmax(max,a[i].gpa);
    }
    printf("Thong tin cac sinh vien co GPA cao nhat :\n");
    for(int i=0; i<n; i++){
        if(max==a[i].gpa) outp(a[i]);
    }
}

void detele(sv a[], int *n, char name[]){
    for(int i=0; i<*n; i++){
        if(strcmp(a[i].ten,name)==0){
            for(int j=i; j<*n-1; j++){
                a[j]=a[j+1];
            }
            (*n)--;
        }
    }
}

int partition(sv a[], int l, int r){
    int i=l-1;
    double pivot=a[r].gpa;
    for(int j=l; j<r; j++){
        if(a[j].gpa>=pivot){
            ++i;
            sv tmp=a[i]; a[i]=a[j]; a[j]=tmp;
        }
    }
    ++i;
    sv tmp=a[i]; a[i]=a[r]; a[r]=tmp;
    return i;
}

void quicksort(sv a[], int l, int r){
    if(l<r){
        int pos=partition(a,l,r);
        quicksort(a,l,pos-1);
        quicksort(a,pos+1,r);
    }
}

int comp(const void *a, const void *b){
    sv *x=(sv*)a;
    sv *y=(sv*)b;
    return x->gpa-y->gpa;
} 

int main(){
    sv a[100];
    int n;
    printf("\n---------------------------------------------CHUONG TRINH QUAN LY SINH VIEN---------------------------------------------\n");
    printf("Nhap so luong sinh vien : "); scanf("%d",&n);
    for(int i=0; i<n; i++) inp(a+i);
    while(1){
        printf("-----------------------------------------------\n");
        printf("1. Hien thi danh sach sinh vien\n");
        printf("2. Tim kiem sinh vien theo ten\n");
        printf("3. Liet ke sinh vien co GPA cao nhat\n");
        printf("4. Xoa sinh vien theo ten\n");
        printf("5. Sap xep sinh vien theo thu tu GPA giam dan\n");
        printf("0. Thoat chuong trinh\n");
        printf("-----------------------------------------------\n");
        printf("\nNhap lua chon : ");
        int x; scanf("%d",&x);
        if(x==1){
            printf("Danh sach sinh vien : \n");
            for(int i=0; i<n; i++) outp(a[i]);
        }
        else if(x==2){
            char name[100];
            getchar();
            printf("Nhap ten sinh vien can tim kiem : ");
            gets(name);
            find(a,n,name);
        }
        else if(x==3){
            maxgpa(a,n);
        }
        else if(x==4){
            char name[100];
            getchar();
            printf("Nhap ten sinh vien can xoa : ");
            gets(name); 
            delete(a,&n,name);
        }
        else if(x==5){
            quicksort(a,0,n-1);
            for(int i=0; i<n; i++) outp(a[i]);
        }
        else if(x==0) break;
    }
}
