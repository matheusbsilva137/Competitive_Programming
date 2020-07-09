#include<bits/stdc++.h>
using namespace std;
#define MAX 1010 
vector<int> adj[MAX];
vector<int> first, euler, prof, seg;
vector<bool> mrk;
int n;

void dfs(int no, int profAt){
    mrk[no] = true;
    prof[no] = profAt;
    first[no] = euler.size();
    euler.push_back(no);

    for(int i = 0; i < adj[no].size(); i++){
        if (!mrk[adj[no][i]]){
            dfs(adj[no][i], profAt+1);
            euler.push_back(no);
        }
    }
}

void build(int no, int b, int e){
    //constroi a segtree necessaria para encontrar o lca
    if (b == e) seg[no] = euler[b];
    else{
        int m = (b+e)/2;
        build(no << 1, b, m);
        build(no << 1 | 1, m + 1, e);
        int l = seg[no << 1];
        int r = seg[no << 1 | 1];
        if (prof[l] < prof[r]) seg[no] = l;
        else seg[no] = r;
    }
}

void construirLCA(){
    prof.resize(n);
    first.resize(n);
    euler.reserve(2*n);
    mrk.assign(n, false);
    dfs(0, 0);
    int m = euler.size();
    seg.resize(4*m);
    build(1, 0, m-1);
}

int qMin(int v, int lo, int hi, int l, int r){
    if (lo > r || hi < l) return -1;
    if (lo >= l && hi <= r) return seg[v];
    
    int m = (lo+hi) >> 1;
    int left = qMin(v << 1, lo, m, l, r);
    int right = qMin(v << 1 | 1, m+1, hi, l, r);
    if (right == -1) return left;
    if (left == -1) return right;
    if (prof[left] < prof[right]) return left;
    else return right;
}

int lca(int u, int v){
    int l = first[u], r = first[v];
    if (l > r) swap(l, r);
    return qMin(1, 0, euler.size() - 1, l, r);
}

int main(){
    int t, c = 1, q, v, w, qAdj, noAdj;
    cin >> t;

    while (t--){
        cin >> n;
        for (int i = 1; i <= n; i++){
            cin >> qAdj;
            for (int j = 0; j < qAdj; j++){
                cin >> noAdj;
                adj[i-1].push_back(noAdj-1);
                adj[noAdj-1].push_back(i-1);
            }
        }

        construirLCA();

        cin >> q;
        cout << "Case " << c << ":" << endl;
        for (int i = 0; i < q; i++){
            cin >> v >> w;
            cout << lca(v-1, w-1) + 1 << endl;
        }

        //limpa os vetores usados
        for (int i = 0; i < n; i++) adj[i].clear();
        first.clear();
        euler.clear();
        mrk.clear();
        prof.clear();
        seg.clear();
        c++;
    }
    
    return 0;
}