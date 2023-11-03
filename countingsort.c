#include <stdio.h>
#include <math.h>

// O(N+K)
// Dem xem moi gia tri xuat hien bao nhieu lan, sau do in tu be den lon
// Cac pt trong mang khong duoc la so am, khai bao duoc 1 mang dem co co la K+1(K la pt lon nhat trong mang)
int cnt[10000001] = {0};

void countingsort(int a[], int n)
{
    int max = -1e9;
    for (int i = 0; i < n; i++)
    {
        max = fmax(max, a[i]);
    }
    for (int i = 0; i < n; i++)
    {
        cnt[a[i]]++;
    }
    for (int i = 0; i <= max; i++)
    {
        for (int j = cnt[i] - 1; j >= 0; j--)
        {
            printf("%d ", i);
        }
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    countingsort(a, n);
}
