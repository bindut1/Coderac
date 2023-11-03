#include <stdio.h>
#include <math.h>
#define eps 1e-6
//pp lap
double g1(double x){
	return x*x*x-1;
}

double g2(double x){
	return pow(x+1,1.0/3.0);
}

double g3(double x){
	return (x+1)/(x*x);
}

double xuli(double x, double (*g)(double)){
	double max=1e9;
	double y;
	do{
		y=x;
		x=g(y);
		double q=fabs(x-y);
		if(q>max) return 0;
		else max=q;
	}while(fabs(x-y)>eps && fabs(x-y)!=0);
	return x;
}

int main(){
	int lc;
	double x;
	char c;
	do{
		printf("---------------------------\n");
		printf("Nhap 1: g(x)=x^3-1\n");
		printf("Nhap 2: g(x)=(x+1)^(1/3)\n");
		printf("Nhap 3: g(x)=(x+1)/(x^2)\n");
		printf("---------------------------\n");
		printf("Nhap lua chon : ");
		scanf("%d",&lc);
		printf("Nhap nghiem xap xi : ");
		scanf("%lf",&x);
		if(lc==1){
			if(xuli(x,g1)) printf("Pt co nghiem la : %lf\n", xuli(x, g1));
			else printf("Ham khong hoi tu\n");n
		}
		else if(lc==2){
			if(xuli(x,g2)) printf("Pt co nghiem la : %lf\n", xuli(x, g2));
			else printf("Ham khong hoi tu\n");
		}
		else{
			if(xuli(x,g3)) printf("Pt co nghiem la : %lf\n", xuli(x, g3));
			else printf("Ham khong hoi tu\n");
		}
		printf("Nhap c de tiep tuc chuong trinh : ");
		getchar();
		scanf("%c",&c);	
	}while(c=='c');
}