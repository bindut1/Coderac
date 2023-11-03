#include <stdio.h>
//tim nghiem bang pp Gauss
void swap(double a[][100], int n, int l, int r){
	for(int k=1; k<=n; k++){
		double tmp=a[l][k];
		a[l][k]=a[r][k];
		a[r][k]=tmp;
	}
}

void xuli(double a[][100], int n){
	for(int i=1; i<n; i++){
		if(a[i][i]==0){
			int j=i+1;
			for(; j<=n; j++){
				if(a[j][i]!=0) break;
			}
			if(j==n+1){
				printf("He khong co nghiem doc lap");
				return;
			}
			else swap(a,n,i,j);
		}
		for(int j=i+1; j<=n; j++){
			double m=-a[j][i]/a[i][i];
			for(int k=i; k<=n+1; k++) a[j][k]+=a[i][k]*m;
		}
	}
}

void nghiem(double a[][100], int n, double x[100]){
	for(int i=n; i>=1; i--){
		x[i]=a[i][n+1];
		for(int j=i+1; j<=n; j++) x[i]-=x[j]*a[i][j];
		x[i]/=a[i][i];
	}
}

int main(){
	int n;
	scanf("%d",&n);
	double a[100][100], x[100];
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n+1; j++){
			scanf("%lf",&a[i][j]);
		}
	}
	xuli(a,n);
	nghiem(a,n,x);
	for(int i=1; i<=n; i++){
		printf("%.3lf	",x[i]);
	}
}