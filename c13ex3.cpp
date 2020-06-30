#include<bits/stdc++.h>
using namespace std;

int main(){
    int i, n, m, l, lant = -4;
    bool travessia = true;
    char pos, posAnt = 'N';
    cin >> n >> m;

    for (i = 0; i < m && travessia; i++){
        cin >> l >> pos;
        if (pos == 'M' || (l - lant < 4 && pos != posAnt)) travessia = false;
        lant = l;
        posAnt = pos;
    }

    if (travessia) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}