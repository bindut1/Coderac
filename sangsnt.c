#include<stdio.h>
#include<math.h>

//O(Nlog(logN))
int n=10000000;
int prime[10000001];

void sang(){
    for(int i=0;i<=n;i++){
        prime[i]=1;
    }
    prime[0]=prime[1]=0;
    for(int i=2;i<=sqrt(n);i++){
        if(prime[i]){
            for(int j=i*i;j<=n;j+=i){
                prime[j]=0;
            }
        }
    }
}

int main(){
    int n;
    scanf("%d",&n);
    sang();
    
}