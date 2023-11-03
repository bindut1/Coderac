#include <stdio.h>
#include <math.h>
//tim nghiem bang pp Cramer

void matran(double a[][100], int n, int cot, double b[][100]){
	for(int c=1; c<=n; c++){
		if(c!=cot){
			for(int h=1; h<=n; h++) b[h][c]=a[h][c];
		}
		else{
			for(int h=1; h<=n; h++) b[h][c]=a[h][n+1];
		}
	}
}

void swap(double a[][100], int n, int l, int r){
	for(int k=1; k<=n; k++){
		double tmp=a[l][k];
		a[l][k]=a[r][k];
		a[r][k]=tmp;
	}
}

double dt(double a[][100], int n){
	double d=1;
	for(int i=1; i<=n; i++){
		if(a[i][i]==0){
			for(int j=i+1; j<=n; j++){
				if(a[j][i]!=0){
					swap(a,n,i,j);
					d*=-1;
					break;
				}
			}
		}
		for(int j=i+1; j<=n; j++){
			double m=-a[j][i]/a[i][i];
			for(int k=i; k<=n; k++) a[j][k]+=a[i][k]*m;
		}
	}
	for(int i=1; i<=n; i++) d*=a[i][i];
	return d;
}

int timnghiem(double a[][100], int n, double ans[]){
	double b[100][100];
	matran(a,n,0,b);
	double D=dt(b,n);
	if(D==0) return 0;
	for(int cot=1; cot<=n; cot++){
		matran(a,n,cot,b);
		double d=dt(b,n);
		ans[cot]=d/D;
	}
	return 1;
}

int main(){
	int n;
	scanf("%d",&n);
	double a[100][100], ans[100];
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n+1; j++){
			scanf("%lf",&a[i][j]);
		}
	}
	if(timnghiem(a,n,ans)){
		for(int i=1; i<=n; i++) printf("%.3lf	",ans[i]);
	}
	else printf("Ma tran khong suy bien");
}