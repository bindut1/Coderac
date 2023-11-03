//giai thua
#include<stdio.h>
long long gt(int n){
    long long res=1;
    for(int i=1;i<=n;i++){
        res*=i;
    }
    return res;
}
int main(){
    int n;
    scanf("%d",&n);
    printf("%d",gt(n));
}
//nhap vao n, in ra YES neu n la so nguyen to, nguoc lai in ra NO
#include<stdio.h>
#include<math.h>
int nguyento(long long n){
    if(n<2) 
        return 0;
    for(long long i=2;i<=sqrt(n);i++){
        if(n%i==0)
        return 0;
    }
    return 1;
}
int main(){
    long long n;
    scanf("%lld",&n);
    if(nguyento(n)==1) printf("YES");
    else printf("NO");
}
//nhap vao n, in ra tong uoc cua n
#include<stdio.h>
#include<math.h>
int tonguoc(int n){
    int sum=0;
    for(int i=1;i<=sqrt(n);i++){
        if(n%i==0){
            sum+=i;
            if(n/i!=i)
            sum+=n/i;
        }
    }
    return sum;
}
int main(){
    int n;
    scanf("%d",&n);
    printf("%d",tonguoc(n));
}
//nhap vao n va kiem tra xem n co phai la so chinh phuong hay khong
#include<stdio.h>
#include<math.h>
int chinhphuong(long long n){
    int k=sqrt(n);
    if(1ll*k*k==n)
    return 1;
    else
    return 0;
}

int main(){
    int n;
    scanf("%d",&n);
    if(chinhphuong(n)==1) printf("YES");
    else printf("NO");
}
// nhap vao n, kiem tra xem n co phai la so hoan hao
// bai nay tuong tu nhu tinh tong uoc, chi khac la lay sum-n==n
#include<stdio.h>
#include<math.h>
int hoanhao(int n){
    if(n==0) return 0;
    int sum=0;
    for(int i=1;i<=sqrt(n);i++){
        if(n%i==0){
            sum+=i;
            if(i!=n/i)
            sum+=n/i;
        }
    }
    if(sum-n==n)
        return 1;
    else 
        return 0;
}
int main(){
    int n;
    scanf("%d",&n);
    printf("%d",hoanhao(n));
}
//so hoan hao toi uu hon:
#include<stdio.h>
#include<math.h>
#define ll long long

int nt(ll n){
    if(n<2) return 0;
    for(int i=2;i<=sqrt(n);i++){
        if(n%i==0) return 0;
    }
    return 1;
}

int check(ll n){
    for(int p=2;p<=32;p++){
        ll k=(ll)pow(2,p)-1;
        if(nt(p) && nt(k)){
            ll h=(ll)pow(2,p-1)*k;
            if(h==n) return 1;
        }
    }
    return 0;
}

int main(){
    ll n;
    scanf("%lld",&n);
    if(check(n)) printf("YES");
    else printf("NO");
}
//phan tich thua so nguyen to
#include<stdio.h>
#include<math.h>
void ptich(int n){
    for(int i=2;i<=sqrt(n);i++){
        if(n%i==0){
            while(n%i==0){
                printf("%d ",i);
                n/=i;
            }
        }
    }
    if(n!=1) printf("%d",n);
}

int main(){
    int n;
    scanf("%d",&n);
    ptich(n);
}
//UCLN,BCNN
#include<stdio.h>
int ucln(int a,int b){
    while(b!=0){
        int r=a%b;
        a=b;
        b=r;
    }
    return a;
}
int bcnn(int a,int b){
    return a/ucln(a,b)*b;
}

int main(){
    printf("%d %d",ucln(15,8), bcnn(15,8));
}
// So thuan nghich
int thuannghich(int n){
    int lat=0;
    int temp=n; //luu lai gia tri ban dau cua n
    while(n){
        lat=lat*10+n%10;
        n/=10;
    }
    if(temp==lat)
        return 1;
    else
        return 0;
}

int main(){
    printf("%d",thuannghich(12332));
}
//To hop chap k cua n
#include<stdio.h>
#include<math.h>
long long tohop(int n,int k){
    k=fmin(k,n-k);
    long long res=1;
    for(int i=1;i<=k;i++){
        res*=(n-i+1);
        res/=i;
    }
return res;
}
int main(){
    printf("%lld", tohop(4,2));
}
//tam giac pascal
#include<stdio.h>
#include<math.h>
long long tohop(int n,int k){
    k=fmin(k,n-k);
    long long res=1;
    for(int i=1;i<=k;i++){
        res*=(n-i+1);
        res/=i;
    }
return res;
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            printf("%d ", tohop(i,j));
        }
        printf("\n");
    }
}
//nhap vao n, kiem tra n co phai la so Fibonacci
#include<stdio.h>
int checkFibo(long long n){
    if(n==0 || n==1) return 1;
    long long fn1=1,fn2=0;
    for(int i=2;i<=92;i++){
        long long fn=fn1+fn2;
        if(fn==n) return 1;
        fn2=fn1;
        fn1=fn;
    }
    return 0;
}
int main(){
    long long n;
    scanf("%d",&n);
    if(checkFibo(n)==1) printf("YES");
    else printf("NO");
    return 0;
}
//in ra n so Fibo dau tien
#include<stdio.h>
void inFibo(int n){
    if(n==1) printf("0");
    else if(n==2) printf("0 1");
    else{
        printf("0 1 ");
        long long fn1=1,fn2=0;
        for(int i=2;i<n;i++){
            long long fn=fn1+fn2;
            printf("%lld ",fn);
            fn2=fn1;
            fn1=fn;
        }
    }
}
int main(){
    inFibo(92);
}
//in ra so Fibo thu n
#include<stdio.h>
long long findFibo(int n){
    if(n==0 || n==1) return n;
    long long fn1=1, fn2=0, fn;
    for(int i=2;i<=n;i++){
        fn=fn1+fn2;
        fn2=fn1;
        fn1=fn;
    }
    return fn;
}
int main(){
    int n;
    scanf("%d",&n);
    printf("%lld",findFibo(n));
}
//a^b luy thua nhi phan
#include<stdio.h>
long long lt2(int a,int b){
    long long res=1;
    while(b){
        if(b%2==1){
            res*=a;
        }
        a*=a;
        b/=2;
    }
    return res;
}
int main(){
    printf("%lld",lt2(2,10));
}