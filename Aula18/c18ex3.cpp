#include<bits/stdc++.h>
using namespace std;
int dp[10005];
vector<pair<int, int>> c;

int main(){
    int t, e, f, n, p, w;

    for (cin >> t; t > 0; t--){
        int x = 0;
        cin >> e >> f >> n;    
        for (int i = 0; i < n; i++){
            cin >> p >> w;
            c.push_back(make_pair(w, p));
        }
        sort(c.begin(), c.end());

        dp[0] = 0;
        for (int i = 1; i <= (f - e); i++){
            dp[i] = INT_MAX;
            for (int j = 0; j < n && c.at(j).first <= i; j++)
                if (dp[i-c.at(j).first] != INT_MAX) dp[i] = min(dp[i], dp[i-c.at(j).first] + c.at(j).second);
        }

        if (dp[f - e] == INT_MAX) cout << "This is impossible." << endl;
        else cout << "The minimum amount of money in the piggy-bank is " << dp[f - e] << "." << endl;
        c.clear();
    }
    return 0;
}