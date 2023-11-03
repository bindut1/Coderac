#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#define MAX_LEN 40000

int a[99999999];
 void giaithua(int n){
 	int m=1;
 	long long r=0, tmp;
 	a[0]=1;
 	for(int i=2;i<=n;i++){
 		for(int j=0;j<m;j++){
 			tmp=r;
 			r=(a[j]*i+r)/10;
 			a[j]=(a[j]*i+tmp)%10;
 		}
 		while(r>0){
 			a[m]=r%10;
 			m++;
 			r/=10;
 		}
 	}
 	for(int i=m-1;i>=0;i--) printf("%d", a[i]);
 }

//char a[MAX_LEN]={'0'};

// void giaithua1(int n){
// 	memset(a,'0',MAX_LEN);
// 	a[0]='1';s
// 	int i, j, len=1, tmp=0;
// 	for(i=2;i<=n;i++){
// 		for(j=0;j<len||tmp!=0;j++){
// 			tmp+=(a[j]-'0')*i;
// 			a[j]=tmp%10+'0';
// 			tmp/=10;
// 		}
// 		len=j;
// 	}
// 	for(int i=len-1;i>=0;i--) printf("%c",a[i]);
// }

int main(){
	int n;
	scanf("%d",&n);
	giaithua(n);
}