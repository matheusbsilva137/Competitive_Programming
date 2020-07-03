#include<bits/stdc++.h>
using namespace std;
int dp[5610];
#define INF 0x3f3f3f3f

int main(){
    int w, s, n = 0, ans = 0;
    vector<pair<int, int>> c;
    while (cin >> w >> s) {
        c.push_back(make_pair(s, w));
        n++;
    }
    sort(c.begin(), c.end());

    memset(dp, INF, sizeof(dp));
    dp[0] = 0;

    for(int i = 0; i < n; i++){
        for(int j = n-1; j >= 0; j--){
            if (c[i].first >= (dp[j] + c[i].second)){
                //consigo inserir a tartaruga na base da pilha
                dp[j+1] = min(dp[j+1], dp[j]+c[i].second);
                ans = max(ans, j+1);
            }
        }
    }
    cout << ans << endl;
    return 0;
}