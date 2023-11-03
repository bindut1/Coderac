#include<stdio.h>
#include<math.h>

void binary_insertionsort(int a[], int n){
    int l, m, r;
    float x;    //luu gia tri a[i] tranh bi ghi de khi doi cho cac phan tu
    for(int i = 1; i < n; i++){
        x = a[i];   
        l = 0;     r = i - 1;
        while(l <= r){ //tim vi tri chen x
            m = (l + r) / 2;    //tim vi tri thich hop m
            if(x < a[m]) r = m - 1;
            else l = m + 1;
        }
        for(int j = i - 1; j >= l; j--)     a[j + 1] = a[j];    //doi cac phan tu se dung sau x
        a[l] = x; //chen x vao day
    }
}

int main(){
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    binary_insertionsort(a,n);
    for(int i=0;i<n;i++) printf("%d ",a[i]);
}