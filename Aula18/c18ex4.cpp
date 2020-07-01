#include<bits/stdc++.h>
using namespace std;
int dp[10005][2];

int main(){
    int m, n, t;

    while (cin >> m){
        cin >> n >> t;

        for (int i = 0; i <= t; i++){
            if (m <= i && n <= i){
                if (dp[i-m][1] < dp[i-n][1] || (dp[i-m][1] == dp[i-n][1] && dp[i-m][0] >= dp[i-n][0])) {
                    dp[i][1] = dp[i-m][1];
                    dp[i][0] = dp[i-m][0]+1;
                }else{
                    dp[i][1] = dp[i-n][1];
                    dp[i][0] = dp[i-n][0]+1;
                }
            }else if (n <= i) {
                dp[i][0] = dp[i-n][0]+1;
                dp[i][1] = dp[i-n][1];
            }else if (m <= i){
                dp[i][0] = dp[i-m][0]+1;
                dp[i][1] = dp[i-m][1];
            }else{
                dp[i][0] = 0;
                dp[i][1] = i;
            }
        }

        if (dp[t][1] != 0) cout << dp[t][0] << " " << dp[t][1] << endl;
        else cout << dp[t][0] << endl;
    }
    return 0;
}