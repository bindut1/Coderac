#include <stdio.h>
#include <math.h>
#define eps 1e-6
//phuong phap day cung
double f(double x){
    return pow(2,x)+x-4;
}
int solve(double a, double b, double (*f)(double), double *q){
    double x, fx, fa, fb;
    if(f(a)*f(b)>0) return 0;
    do{
        fa=f(a);
        fb=f(b);
        x=a-((b-a)*fa)/(fb-fa);
        fx=f(x);
        if(fx*fa<0) b=x;
        else a=x;
    }while(fabs(fx)>eps);
    *q=x;
    return 1;
}

int main(){
    double x,q,a,b;
    printf("Nhap khoang nghiem (a,b) : ");
    scanf("%lf %lf",&a, &b);
    if(solve(a,b,f,&q)) printf("Nghiem gan dung la : %lf",q);
    else printf("Khong ton tai nghiem trong khoang vua nhap");
}