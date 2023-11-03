#include <stdio.h>
#include <math.h>
#define eps 1e-6
//pp tiep tuyen
double f(double x){
    return x*x*x+x-5;
}

double fdh(double x){
    return 3*x*x+1;
}

double fdh2(double x){
    return 6*x;
}

int solve(double x, double (*f)(double), double (*fdh)(double), double (*fdh2)(double), double *q){
    double y;
    if(f(x)*fdh2(x)<=0) return 0;
    do{
        y=x;
        x=y-f(y)/fdh(y);
    }while(fabs(x-y)>eps);
    *q=x;
    return 1;
}

int main(){
    double x,q;
    printf("Nhap nghiem ban dau : ");
    scanf("%lf",&x);
    if(solve(x,f,fdh,fdh2,&q)) printf("Nghiem gan dung la : %lf",q);
    else printf("Khong thoa man dieu kien hoi tu Furie");
}