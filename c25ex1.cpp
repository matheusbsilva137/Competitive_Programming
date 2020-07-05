#include<bits/stdc++.h>
using namespace std;
int dp[2005][2005];
vector<pair<int, int>> items;

int solve(int c, int n){
    //dp[i][j] é o valor máximo na bolsa de capacidade máxima i usando até o item j
    for (int i = 1; i <= c; i++)
        for (int j = 1; j <= n; j++) 
            dp[i][j] = max(dp[i][j-1], ((i - items[j-1].first >= 0)? (dp[i - items[j-1].first][j-1] + items[j-1].second) : 0) );
    return dp[c][n];
}

int main(){
    int n, c, s, v;

    cin >> c >> n;
    for (int i = 0; i < n; i++){
        cin >> s >> v;
        items.push_back(make_pair(s, v));
    }

    cout << solve(c, n) << endl;
    return 0;
}