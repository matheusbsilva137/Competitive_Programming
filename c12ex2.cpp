#include<bits/stdc++.h>
using namespace std;

int main(){
    int a1, a2, k1, k2, n, min = 0, max = 0;
    int tmpa1, tmpa2;
    cin >> a1 >> a2 >> k1 >> k2 >> n;

    if (a1 * k1 < a2 * k2){
        swap(k1, k2);
        swap(a1, a2);
    }
    tmpa1 = a1; tmpa2 = a2;

    max = a1 + a2;
    while (a1 * k1 + a2 * k2 > n && max > 0){
        max--;
        if ( (a1 > 0 && (a1 - 1)*k1 + a2 * k2 < a1 * k1 + (a2 - 1) * k2) || a2 <= 0) a1--;
        else a2--;
    }

    a1 = tmpa1; a2 = tmpa2;

    while (k1 > 1 && n > 0) {
        n -= a1;
        k1--;
    }

    while (k2 > 1 && n > 0) {
        n -= a2;
        k2--;
    }

    if (n > 0) min = n;
    else min = 0;

    cout << min << " " << max << endl;

    return 0;
}