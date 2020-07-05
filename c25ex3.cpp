#include<bits/stdc++.h>
using namespace std;
bool hasCat[100005];
bool mrk[100005];
vector<int> t[100005];
int m;

int dfs(int v, int qCat){
    int ans = 0;
    if (mrk[v]) return 0;
    else mrk[v] = true;

    if (hasCat[v]) qCat++;
    else qCat = 0;

    if (qCat > m) return 0;
    if (t[v].size() == 1 && mrk[t[v][0]-1]) return 1;
    for (int i = 0; i < t[v].size(); i++) ans += dfs(t[v][i]-1, qCat);
    return ans;
}

int main(){
    int n, a, b, ans = 0, r;

    cin >> n >> m;

    for (int i = 0; i < n; i++) cin >> hasCat[i];
    for (int i = 0; i < n - 1; i++){
        cin >> a >> b;
        t[a-1].push_back(b);
        t[b-1].push_back(a);
    }

    cout << dfs(0, 0) << endl;
    return 0;
}