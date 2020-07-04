#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, i, j, k, manag, size = 0, quantGrupos = 0;
    int* p;

    cin >> n;
    p = new int[n];

    for (i = 0; i < n; i++) cin >> p[i];

    for (i = 0; i < n; i++){
        size = 1;
        manag = p[i];
        while (manag != -1) {
            size++;
            manag = p[manag-1];
        }

        if (size > quantGrupos) quantGrupos = size;
    }

    cout << quantGrupos << endl;
}