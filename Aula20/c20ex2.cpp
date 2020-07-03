#include<bits/stdc++.h>
using namespace std;

long long int reverterNumero(long long int p){
    if (p == 0) return 0;
    long long int pow10[11] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000, 10000000000};
    int quantDig = (int) log10(p);
    long long int r = 0;

    for (int i = quantDig, j = 0; i >= 0; i--, j++){
        r += (p/pow10[i])*pow10[j];
        p = p%pow10[i];
    }
    
    return r;
}

int main(){
    int n;
    long long int p;

    cin >> n;
    while (n--){
        cin >> p;
        int m = 0;
        long long int r = reverterNumero(p);
        while (r != p){
            m++;
            p += r;
            r = reverterNumero(p);
        }
        cout << m << " " << r << endl;
    }

    return 0;
}