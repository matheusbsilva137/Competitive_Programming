#include<bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
int S[1000][1000];
int dp[1000][1000];
int r, c;

int solve(){
    for(int i = r-1; i >= 0; i--){
        for(int j = c-1; j >= 0; j--){
            if (i == r-1 && j == c-1) continue;
            if (S[i][j] >= 0) dp[i][j] = max(min(dp[i+1][j] - S[i][j], dp[i][j+1]  - S[i][j]), 1);
            else dp[i][j] = max(min(abs(S[i][j]) + dp[i+1][j], abs(S[i][j]) + dp[i][j+1]), 1);
        }
    }
    return dp[0][0];
}

int main(){
    int t;

    scanf("%d", &t);
    while (t--){                
        scanf("%d %d", &r, &c);

        for (int i = 0; i <= r; i++)
            for (int j = 0; j <= c; j++) dp[i][j] = INF;
        
        for (int i = 0; i < r; i++)
            for (int j = 0; j < c; j++) scanf("%d", &(S[i][j]));

        dp[r-1][c-1] = 1;
        printf("%d\n", solve());
    }
    return 0;
}