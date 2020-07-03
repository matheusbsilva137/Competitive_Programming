#include<bits/stdc++.h>
using namespace std;
int k, n;
#define INF 0x3f3f3f3f3f3f3f3f
vector<long long int> l;
long long int dp[5020][1020];

long long int solve(int i, int j){
    if (dp[i][j] != -1) return dp[i][j];  //calculado anteriormente
    if (j == 0) return 0; //0 convidados
    if (i >= n || i + 3*j > n) return INF; //mais convidados que o máximo especificado ou excede a quantidade de palitos disponiveis
    dp[i][j] = min(solve(i+1, j), solve(i + 2, j - 1) + (l[i+1] - l[i])*(l[i+1] - l[i]) ); //usar o palito ou nao
    return dp[i][j];
}

int main(){
    int t;
    long long int a;

    cin >> t;
    while (t--){
        memset(dp, -1, sizeof(dp));
        cin >> k >> n;
        for (int i = 0; i < n; i++){
            cin >> a;
            l.push_back(a);
        }

        cout << solve(0, k+8) << endl;
        l.clear();
    }

    return 0;
}