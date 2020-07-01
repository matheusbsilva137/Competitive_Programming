#include<bits/stdc++.h>
using namespace std;
int dp[4005];

int main(){
    int n, a, b, c, lastOcur = 0;

    cin >> n >> a >> b >> c;
    dp[0] = 0;

    for(int i = 1; i <= n; i++){
        dp[i] = -1;
        if (i >= a && dp[i - a] >= 0) dp[i] = dp[i-a]+1;
        if (i >= b && dp[i - b] >= 0) dp[i] = max(dp[i], dp[i-b]+1);
        if (i >= c && dp[i - c] >= 0) dp[i] = max(dp[i], dp[i-c]+1);

        if (dp[i] >= 0) lastOcur = i;
    }

    cout << dp[lastOcur] << endl;

    return 0;
}