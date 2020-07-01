#include<bits/stdc++.h>
using namespace std;
int dp[2005][2005];
int n;
int v[2005];

int solve(int i, int j){
    int ano = n - j + i;
    if (j == i) return ano*v[i]; //Só existe i no intervalo
    if (dp[i][j] != -1) return dp[i][j]; //já foi resolvido e memorizado anteriormente
    if (i > j) return 0; //não existe resposta, intervalo inválido

    dp[i][j] = 0;
    dp[i][j] = max(dp[i][j], solve(i+1, j) + v[i]*ano);
    dp[i][j] = max(dp[i][j], solve(i, j-1) + v[j]*ano);
    return dp[i][j];
}

int main(){
    cin >> n;

    memset(dp, -1, sizeof(dp));
    for (int i = 0; i < n; i++) cin >> v[i];

    cout << solve(0, n) << endl;
    return 0;
}