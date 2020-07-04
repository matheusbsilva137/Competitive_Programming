#include<bits/stdc++.h>
using namespace std;
#define MAX 100000
vector<int> adj[MAX];
int randC[MAX];
int C[MAX];

int getHashAdjList(vector<int>& v){
    int h = 0;
    for (int i = 0; i < v.size(); i++) h = h ^ randC[v[i]];
    return h;
}

int main(){
    int n, m, a, b, ocur;
    map<int , int>  V, qV;
    srand(time(NULL));

    cin >> n >> m;
    for (int i = 0; i < n; i++) randC[i] = rand();

    for (int i = 0; i < m; i++){
        cin >> a >> b;
        adj[a-1].push_back(b-1);
        adj[b-1].push_back(a-1); 
    }

    ocur = 1;
    for (int i = 0; i < n; i++){
        int h = getHashAdjList(adj[i]);
        if (V.find(h) == V.end()) V[h] = ocur++;
        C[i] = V[h];
        qV[V[h]]++;
    }

    if (V.size() == 3){
        int i;
        for(i = 0; i < n && adj[i].size() == n - qV[C[i]]; i++);
        if (i == n){
            for (i = 0; i < n; i++) cout << C[i] << " ";
            cout << endl;
        }else cout << -1 << endl;
    }else cout << -1 << endl;

    return 0;
}