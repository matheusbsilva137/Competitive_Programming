#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, i, j, k, cont = 1, maxCont = 1;
    cin >> n;

    long long int* a = new long long int[n];
    for (i = 0; i < n; i++){
        cin >> a[i];
        if (i > 0 && a[i] <= 2 * a[i-1]) cont++;
        else {
            if (cont > maxCont) maxCont = cont;
            cont = 1;
        }
    }

    if (maxCont < cont) maxCont = cont;
    delete a;
    cout << maxCont << endl;
}