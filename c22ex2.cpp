#include<bits/stdc++.h>
using namespace std;
#define MAXN 10005

long long int dp[MAXN]; //dp[i] é a quantidade máxima de moedas considerando os monstros 0...i-1
vector<int> c;

long long int solve(long long int n){
    if (n == 0) return 0;
    else if (n == 1) return c[n-1];
    else if (dp[n] != -1) return dp[n];

    if (c[n-1] == 0) dp[n] = max(solve(n-1), solve(n-2));
    else dp[n] = max (solve(n-1), solve(n-2) + c[n-1]);

    return dp[n];
}

int main(){
    int t, coin;
    long long int n;

    cin >> t;
    for (int cs = 1; cs <= t; cs++){
        memset(dp, -1, sizeof(dp));
        cin >> n;
        for (long long int i = 0; i < n; i++){
            cin >> coin;
            c.push_back(coin);
        }

        cout << "Case " << cs << ": " << solve(n) << " " << endl;
        c.clear();
    }
    return 0;
}