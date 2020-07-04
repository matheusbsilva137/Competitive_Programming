#include<bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f
vector<pair<int, int>> v;
int dp[105]; //dp[i] é o menor custo possível para comprar i kg de maçã usando quaisquer pacotes

int solve(int k){
    if (dp[k] != INF) return dp[k];
    else{
        for (int i = 0; i < v.size() && v[i].first <= k ; i++)
            dp[k] = min(dp[k], solve(k-v[i].first)+v[i].second);
    }
    return dp[k];
}

int main(){
    long long int c, n, k, y, x;

    cin >> c;
    while (c--){
        cin >> n >> k;

        for (int i = 0; i < k; i++){
            dp[i] = INF;
            cin >> y;
            if (y != -1) v.push_back(make_pair(i+1, y));
        }
        dp[k] = INF;

        dp[0] = 0;

        if (solve(k) == INF) cout << -1 << endl;
        else cout << dp[k] << endl;

        v.clear();
    }
    return 0;
}