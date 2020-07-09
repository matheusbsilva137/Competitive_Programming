#include<bits/stdc++.h>
using namespace std;

int main(){
    int ans[55];
    long long int m, pot;
    int n, l = 1, r;

    scanf("%d %lld", &n, &m);
    r = n;
    for (int i = 1; i <= n; i++){
        //cada iteracao gera um elemento da sequência
        if (n - i - 1 <= 0) pot = 1;
        else pot = (1LL << (n-i-1)); //2^(n-i-1)

        if (m <= pot) ans[l++] = i;
        else{
            ans[r--] = i;
            m -= pot;
        }
    }

    //imprime a m-ésima permutação
    for (int i = 1; i <= n; i++)
        printf("%d ", ans[i]);
    printf("\n");
    return 0;
}