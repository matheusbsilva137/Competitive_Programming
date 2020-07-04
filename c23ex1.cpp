#include<bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f
const int MAX = 2005;
vector<int> adj[MAX];
int gender[MAX];

bool dfs(int i, int g){
    gender[i] = g;
    for (int j = 0; j < adj[i].size(); j++){
        if (gender[adj[i].at(j) - 1] == INF && dfs(adj[i].at(j) - 1, (g+1)%2) == false) return false;
        else if (gender[adj[i].at(j) - 1] == g) return false;
    }
    return true;
}

bool biparted(int n){
    int g = 0;
    for (int i = 0; i < n; i++)
        if (gender[i] == INF && dfs(i, g) == false) return false;
    return true;
}

int main(){
    int s, n, i;
    cin >> s;

    for (int k = 1; k <= s; k++){
        int a, b;
        memset(gender, INF, sizeof(gender));

        cin >> n >> i;
        for (int j = 0; j < i; j++){
            cin >> a >> b;
            adj[a-1].push_back(b);
            adj[b-1].push_back(a);
        }

        if (biparted(n)) cout << "Scenario #" << k << ":" << endl << "No suspicious bugs found!" << endl;
        else cout << "Scenario #" << k << ":" << endl << "Suspicious bugs found!" << endl;

        for (int j = 0; j < n; j++) adj[j].clear();
    }
    return 0;
}