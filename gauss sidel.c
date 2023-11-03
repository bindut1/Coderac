#include <stdio.h>
#include <math.h>
#define eps 1e-6
#define max 1000
//pp gauss-seidel

int check(double a[][100], int n){
	for(int i=1; i<=n; i++){
		double sum=0;
		for(int j=1; j<=n; j++){
			if(j!=i) sum+=fabs(a[i][j]);
		}
		if(fabs(a[i][i])<=sum) return 0;
	}
	return 1;
}

void xuli(double a[][100], double x[], int n){
	double s, t;
		t=0;
		for(int i=1; i<=n; i++){
			s=0;
			for(int j=1; j<=n; j++){
				if(j!=i) s+=a[i][j]*x[j];
			}
			double yi=(a[i][n+1]-s)/a[i][i];
			t+=fabs(yi-x[i]);
			x[i]=yi;
		}
		if(t<eps) break;
}

int main(){
	int n;
	scanf("%d",&n);
	double a[100][100], x[100], y[100];
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n+1; j++){
			scanf("%lf",&a[i][j]);
		}
	}
	for(int i=1; i<=n; i++) scanf("%lf",x+i);

	if(check){
		xuli(a,x,n);
		for(int i=1; i<=n; i++) printf("%lf	",x[i]);
	}
	else printf("He phuong trinh khong thoa man dieu kien hoi tu");
}