#include<bits/stdc++.h>
using namespace std;
vector<int> adj[100000];
bool mrk[100000];

long long int dfs(int n){
    long long int ans = 1;

    if (!mrk[n]){
        mrk[n] = true;
        for (int i = 0; i < adj[n].size(); i++){
            int a = adj[n].at(i);
            if (!mrk[a]) ans *= 2*dfs(a);
        }
    }
    return ans;
}

int main(){
    int n, m, i, j, x, y, c = 0;
    long long int ans = 0, maxAns = 0;
    bool fx, fy;

    cin >> n >> m;
    for (i = 0; i < m; i++) {
        cin >> x >> y;
        adj[x-1].push_back(y-1);
        adj[y-1].push_back(x-1);
    }
    
    for (i = 0; i < n; i++){
        if (!mrk[i]) {
            if (c == 0) ans += dfs(i);
            else ans *= dfs(i);
            c++;
        }
    }

    cout << ans << endl;
}