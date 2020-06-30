#include<bits/stdc++.h>
using namespace std;

int main(){
    int t, n, j, cont = 0, num = 0;
    int* a;

    for (cin >> t; t > 0; t--){
        cont = 0;
        num = 0;
        cin >> n;
        a = new int[n];
        for(j = 0; j < n; j++) cin >> a[j];

        sort(a, a+n);
        for(j = 0; j < n; j++){
            if (a[j] != num){
                num = a[j];
                cont++;
            }
        }
        cout << cont << endl;
        delete a;
    }
}