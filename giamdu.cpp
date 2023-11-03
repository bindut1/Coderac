#include <stdio.h>
#include <math.h>
 
#define eps 0.00001
const int maxN = 15;
 
int main() 
{
    // nhap du lieu bang file:
    //freopen ("input.txt", "r", stdin);
     
    int n, t;
    float a[maxN][maxN], x[maxN], r[maxN];
     
    // Nhap:
    printf("Nhap n = ");
    scanf("%d", &n);
    printf("\nNhap he phuong trinh: \n");
    for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n + 1; j++) scanf("%f", &a[i][j]);
    printf("\nNhap vector nghiem ban dau: \n");
    for (int i = 1; i <= n; i++) scanf("%f", &x[i]);
     
    // Bien doi:
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n + 1; j++) {
            if (i != j) a[i][j] /= a[i][i];
        }
        a[i][i] = 1;
    }
     
    // tinh r[i] ban dau:
    for (int i = 1; i <= n; i++) {
        r[i] = a[i][n+1];
        for (int j = 1; j <= n; j++) {
            r[i] -= a[i][j] * x[j];
        }
    }
     
    // implementation:
    do {
        for (int i = 1; i <= n; i++) printf("%8.3f", r[i]);
        printf("\n");
        t = 0; // dk dung
         
        // tim max(abs(r[i]));
        int idx = 1;
        for (int i = 2; i <= n; i++) {
            if (fabs(r[i]) > fabs(r[idx])) idx = i;
        }
        x[idx] += r[idx];
         
        // tinh lai r[i] kiem tra tiep tuc lap:
        float d = r[idx];
        for (int i = 1; i <= n; i++) {
            r[i] -= a[i][idx] * d;
            if (fabs(r[i]) >= eps) t = 1;
        }
    } while (t);
     
    printf("Nghiem cua hpt la: \n");
    for (int i = 1; i <= n; i++) printf("%8.3f", x[i]);
     
    return 0;
}
