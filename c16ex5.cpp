#include<bits/stdc++.h>
using namespace std;
#define MAXSIZE 10000
vector<int> a[MAXSIZE];
int profundidade[MAXSIZE];
int maxProf = 0, noMaxProf = 0;

void dfs(int no, int noPai){
    for (int  i = 0; i < a[no].size(); i++){
        int adj = a[no].at(i);
        if (adj != noPai) {
            profundidade[adj] = profundidade[no] + 1;
            if (profundidade[adj] > maxProf){
                maxProf = profundidade[adj];
                noMaxProf = adj;
            }
            dfs(adj, no);
        }
    }
}

int main(){
    int i, n, u, v;
    bool found = false;

    cin >> n;
    for (i = 0; i < n - 1; i++){
        cin >> u >> v;
        a[u-1].push_back(v-1);
        a[v-1].push_back(u-1);
    }
    dfs(0, 0);

    maxProf = 0;
    for (i = 0; i < n; i++) profundidade[i] = 0;
    dfs(noMaxProf, noMaxProf);

    cout << maxProf << endl;
    return 0;
}