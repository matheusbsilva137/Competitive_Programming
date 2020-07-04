#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, k, i, size, rat, j;

    cin >> n >> k;
    int *a = new int[n];
    int *t = new int[k];
    size = -1;

    for(i = 0; i < n && size + 1 < k; i++){
        cin >> rat;
        a[i] = rat;
        for (j = 0; j <= size && a[t[j] - 1] != rat; j++);
        if (j > size) t[++size] = i + 1;
    }

    if (size == k - 1){
        cout << "YES" << endl;
        for (i = 0; i < k; i++) cout << t[i] << " ";
        cout << endl;
    }else cout << "NO" << endl;
}