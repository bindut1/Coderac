#include <bits/stdc++.h>
using namespace std;

int n, a[1001], ok;

void ktao(){
    for(int i = 1; i <= n; i++) a[i] = i;
}

void sinh(){
    int i = n - 1;
    while(i >= 1 && a[i] > a[i+1]){
        --i;
    }
    if(i==0) ok = 0; //day la cau hinh cuoi cung
    else{
        //di tim thang lon hon a[i] trong doan [i+1, n]
        int j = n;
        while(a[i] > a[j]) --j;
        swap(a[i], a[j]);
        int l = i + 1, r = n;
        while(l < r){
            swap(a[l], a[r]);
            ++l, --r;
        }
        //co the dung ham reverse de lat nguoc
        //reverse(a + i + 1, a + n + 1);
    }
}

main(){
    cin >> n;
    ok = 1;
    ktao();
    while(ok){
        for(int i = 1; i <= n; i++) cout << a[i];
        cout << endl;
        sinh();
    }
}



// Dung ham sinh hoan vi co san
// main(){
//     int n; cin >> n;
//     int a[n];
//     for(int i = 0; i < n; i++) a[i] = i + 1;
//     do{
//         for(int i = 0; i < n; i++) cout << a[i];
//         cout << endl;
//     }while(next_permutation(a, a + n));
// }

// Dung ham sinh hoan vi nguoc co san
// main(){
//     int n; cin >> n;
//     int a[n];
//     for(int i = 0; i < n; i++) a[i] = n - i;
//     do{
//         for(int i = 0; i < n; i++) cout << a[i];
//         cout << endl;
//     }while(prev_permutation(a, a + n));
// }