// FLOYD
#include <stdio.h>
#define MAX 10
const int INF=1e9;
int c[MAX][MAX];
int n,m;
int trace[MAX][MAX];
void Floyd(){
	for (int k=1;k<=n;k++){
		for (int u=1;u<=n;u++){
			for (int v=1;v<=n;v++){
				if (c[u][v]>c[u][k]+c[k][v]){
					c[u][v]=c[u][k]+c[k][v];
					trace[u][v]=trace[u][k];
				}
			}
		}
	}
}
void inkq(int s,int f){
	while (s!=f){
		printf("%d --> ",s);
		s=trace[s][f];
	}
	printf("%d",f);
}
void init(){
	for (int u=1;u<=n;u++){
		for (int v=1;v<=n;v++){
			c[u][v]=INF;
			trace[u][v]=v;
		}
		c[u][u]=0;
	}
	
}
void input(FILE *fi, int *s, int *f){
	fscanf(fi,"%d%d%d%d",&n,&m,s,f);
	init();
	for (int i=1;i<=m;i++){
		int u,v,w;
		fscanf(fi,"%d%d%d",&u,&v,&w);
		c[u][v]=w;
	}
}
int main(){
	int s,f;
	input(fopen("hi.txt","r"),&s,&f);
	Floyd();
	if (c[s][f]!=INF){
		printf("MIN LENGTH = %d\n",c[s][f]);
		inkq(s,f);
	}
	else puts("NO PATH");
	return 0;
}
