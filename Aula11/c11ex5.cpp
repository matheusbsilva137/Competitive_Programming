#include<bits/stdc++.h>
using namespace std;
#define MAX_SIZE 300005

long long int n, x, y, quantPares = 0, menorComp = 0;
vector<long long int> adj[MAX_SIZE];
long long int tamF, tamB, tamD;
bool searchY = true;

int subtreeSize(int no, int pai){
    long long int i, size = 1;
    for (i = 0; i < adj[no].size(); i++){
        if (adj[no].at(i) != pai) size += subtreeSize(adj[no].at(i), no);
    }
    return size;
}

void dfs (int no, int pai){
    long long int i;

    if (no == y){
        tamB = subtreeSize(y, pai);
        searchY = false;
    }

    for (i = 0; i < adj[no].size() && searchY; i++)
        if (adj[no].at(i) != pai) dfs(adj[no].at(i), no);

    if (pai == x && no != x && !searchY) tamD = subtreeSize(no, pai);
}

int main(){
    long long int i, j, a, b;

    cin >> n >> x >> y;
    for (i = 0; i < n - 1; i++){
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(x, x);

    tamF = n - tamD;
    quantPares = n * (n-1) - tamF * tamB;

    cout << quantPares << endl;
    return 0;
}