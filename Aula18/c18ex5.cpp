#include<bits/stdc++.h>
using namespace std;
#define M 1000000007
long long int dp[2][4];

int main(){
    long long int n;
    cin >> n;
    
    dp[0][3] = 1;
    for(int i = 1; i <= n; i++){
        for(int j = 0; j < 4; j++){
            dp[i%2][j] = 0;
            for (int u = 0; u < 4; u++)
                if (u != j) dp[i%2][j] = (dp[i%2][j] + dp[(i-1)%2][u])%M;
        }
    }
    cout << dp[n%2][3] << endl;
    return 0;
}