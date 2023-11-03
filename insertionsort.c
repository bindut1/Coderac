#include <stdio.h>
#include <math.h>

// O moi buoc se chen phan tu dang xet vao day cac phan tu da sap xep truoc do
// O(N^2)
void insertionsort(int a[], int n)
{
    for (int i = 2; i <= n; i++)
    {
        int pos = i - 1, value = a[i];
        while (pos >= 1 && value < a[pos])
        {
            a[pos + 1] = a[pos];
            --pos;
        }
        a[pos + 1] = value;
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
    insertionsort(a, n);
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
}