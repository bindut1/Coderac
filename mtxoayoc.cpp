#include <bits/stdc++.h>
using namespace std;

void Fibo(long long b[]){
    b[0] = 0, b[1] = 1;
    for(int i = 2; i <= 92; i++) b[i] = b[i-1] + b[i-2];
}

main(){
    int n; cin >> n;
    int a[n][n];
    long long b[1000];
    int h1 = 0, h2 = n - 1, c1 = 0, c2 = n - 1;
    int dem = 0;
    Fibo(b);
    while(dem < n*n){
        for(int i = c1; i <= c2; i++) a[h1][i] = b[dem++];
        ++h1;
        for(int i = h1; i <= h2; i++) a[i][c2] = b[dem++];
        --c2;
        for(int i = c2; i >= c1; i--) a[h2][i] = b[dem++];
        --h2;
        for(int i = h2; i >= h1; i--) a[i][c1] = b[dem++];
        ++c1;
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}