#include<bits/stdc++.h>
using namespace std;

int main(){
    long int n, tAnt, tAtual, vAnt, vAtual, areaParcial, areaTotal = 0;
    double areaFinal, vAtualDouble;
    
    cin >> n >> tAnt >> vAtualDouble;
    vAnt = vAtualDouble * 10;

    while (n > 1){
        cin >> tAtual >> vAtualDouble;

        vAtual = vAtualDouble * 10;
        areaParcial = (vAnt + vAtual) * (tAtual - tAnt);
        areaTotal += areaParcial;

        tAnt = tAtual;
        vAnt = vAtual;
        n--;
    }
    areaFinal = (double)areaTotal/20000;
    printf("%lf\n", areaFinal);
    return 0;
}