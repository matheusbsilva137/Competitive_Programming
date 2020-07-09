#include<bits/stdc++.h>
using namespace std;
#define MAX 100005
int seg[4*MAX];
int a[MAX];

void buildSegTree(int v, int tl, int tr){
    if (tl == tr) seg[v] = a[tl];
    else{
        int tm = (tl + tr)/2;
        buildSegTree(v*2, tl, tm);
        buildSegTree(v*2+1, tm+1, tr);
        seg[v] = min(seg[v*2], seg[v*2 + 1]);
    }
}

int minQ(int v, int tl, int tr, int l, int r) {
    if (l > tr || r < tl) return INT_MAX;
    if (l >= tl && r <= tr) return seg[v];
    int tm = (l + r) / 2;
    return min(minQ(2*v, tl, tr, l, tm), minQ(2*v+1, tl, tr, tm+1, r));
}

int main(){
    int t, n, q, l, r, c = 1;
    bool found = false;

    scanf("%d", &t);
    while (t--){
        scanf("%d %d", &n, &q);
        for (int i = 0; i < n; i++) scanf("%d", &(a[i]));

        buildSegTree(1, 0, n-1);

        printf("Case %d:\n", c);
        for (int i = 0; i < q; i++){
            scanf("%d %d", &l, &r);

            printf("%d\n", minQ(1, l, r, 1, n));
        }
        c++;
    }
    return 0;
}