#include <stdio.h>
#include <math.h>
#define eps 1e-6
//phuong phap chia doi
void inp(double a[], int n){
	for(int i=0; i<=n; i++) scanf("%lf",a+i);
}

double f(double a[], int n, double x){
	double res=0;
	for(int i=0; i<=n; i++) res+=a[i]*pow(x,n-i);
	return res;
}

int solve(double a[], int n, double l, double r, double *q){
    double c,fc;
    if(f(a,n,l)*f(a,n,r)>0) return 0;
    do{
        c=(l+r)/2;
	    fc=f(a,n,c);
        if(fc>0) r=c;
		else l=c;
    }while(fabs(l-r)>eps && fc!=0);
    *q=c;
	return 1;
}

int main(){
	int n;
	double a[100], l, r, q;
	printf("Nhap bac cua phuong trinh : ");
	scanf("%d",&n);
	printf("Nhap cac he so cua phuong trinh : ");
	inp(a,n);
	printf("Nhap khoang nghiem (l,r) : ");
	scanf("%lf %lf",&l, &r);
	if(solve(a,n,l,r,&q)) printf("Nghiem gan dung cua phuong trinh la : %lf",q);
    else printf("Khong tim thay nghiem trong khoang vua nhap.");
}