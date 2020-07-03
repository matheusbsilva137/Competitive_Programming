#include<bits/stdc++.h>
using namespace std;
int dp[55];

int main(){
    int n, m, fi;
    vector<int> f;

    cin >> n >> m;
    for (int i = 0; i < m; i++){
        cin >> fi;
        f.push_back(fi);
    }
    sort(f.begin(), f.end());

    for(int i = 0; i < m; i++){
        if (i >= n - 1) dp[i] = min(dp[i-1], f.at(i) - f.at(i-n+1));
        else dp[i] = INT_MAX;
    }

    cout << dp[m-1] << endl;
    return 0;
}