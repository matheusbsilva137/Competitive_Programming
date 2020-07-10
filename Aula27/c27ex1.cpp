#include<bits/stdc++.h>
using namespace std;

int main(){
    long long int xH, yH, xU, yU, n, a, b, c, ans = 0, valH, valU;

    scanf("%lld %lld", &xH, &yH);
    scanf("%lld %lld", &xU, &yU);
    scanf("%lld", &n);

    for (int i = 0; i < n; i++){
        scanf("%lld %lld %lld", &a, &b, &c);
        valH = a*xH + b*yH + c;
        valU = a*xU + b*yU + c;
        if ( ( valH > 0 &&  valU < 0) || (valH < 0 && valU > 0) ) ans++;
    }
    
    printf("%lld\n", ans);
}