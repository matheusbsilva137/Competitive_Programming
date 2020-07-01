#include<bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
int n;
long long int m[105];
int c[105]; //c[i] guarda a cor da mistura dos elementos 0..i, inclusive
long long int dp[105][105]; //dp[i][j] é a quantidade mínima de fumaça produzida ao misturar os elements i...j


long long int resColor(int i, int j){
    //calcula a cor resultante da mistura dos elementos i,...,j;
    if (i == 0) return c[j];
    else return (c[j] - c[i-1] + 100)%100;
}

long long int solve(int i, int j){
    if (j == i) return 0; //Só existe i no intervalo
    if (dp[i][j] != -1) return dp[i][j]; //já foi resolvido e memorizado anteriormente
    if (i > j) return INF; //não existe resposta, intervalo inválido

    dp[i][j] = INF;
    for (int k = i; k < j; k++)
        dp[i][j] = min(dp[i][j], solve(i, k) + solve (k+1, j) + resColor(i, k)*resColor(k+1, j));
    return dp[i][j];
}

int main(){
    while(cin >> n){
        memset(dp, -1, sizeof(dp));
        for (int i = 0; i < n; i++) cin >> m[i];

        for (int i = 0; i < n; i++)
            if (i == 0) c[i] = m[i]%100;
            else c[i] = (c[i-1]+m[i])%100;
        cout << solve(0, n - 1) << endl;
    }
    return 0;
}