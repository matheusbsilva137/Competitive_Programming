#include<bits/stdc++.h>
using namespace std;

int lev[2005][2005];
string a, b;

int solve(int i, int j){
    if (lev[i][j] != -1) return lev[i][j];
    if (min(i, j) == 0) lev[i][j] = max(i, j);
    else lev[i][j] = min(solve(i-1, j)+1, min(solve(i, j-1) + 1, solve(i-1, j-1) + ( (a[i-1] == b[j-1]) ? 0 : 1 ) ));

    return lev[i][j];
}

int main(){
    int t, oper;
    cin >> t;

    while (t--){
        memset(lev, -1, sizeof(lev));
        cin >> a >> b;

        cout << solve(a.size(), b.size()) << endl;
    }
    return 0;
}