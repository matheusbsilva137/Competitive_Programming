#include<bits/stdc++.h>
using namespace std;
#define MAX 100020
int n;
bool seg[4*MAX];
bool lazy[4*MAX];
char s[MAX];

void push(int v){
    //empurra o lazy de um vértice para os seus filhos
    if (lazy[v]){
        lazy[v] = false;
        lazy[v*2] = !lazy[v*2];
        seg[v*2] = !seg[v*2];
        lazy[v*2 + 1] = !lazy[v*2 + 1];
        seg[v*2 + 1] = !seg[v*2 + 1];
    }
}

void build(bool num[], int v, int lo, int hi){
    if (lo == hi) seg[v] = num[lo];
    else{
        int m = (lo+hi)/2;
        build(num, v*2, lo, m);
        build(num, v*2 + 1, m+1, hi);
        seg[v] = false;
        lazy[v] = false;
    }
}

void rangeUpdate(int v, int lo, int hi, int l, int r){
    if (l > r) return;
    if (l == lo && r == hi){
        seg[v] = !seg[v];
        lazy[v] = !lazy[v];
    }else{
        push(v);
        int m = (lo+hi)/2;
        rangeUpdate(v*2, lo, m, l, min(r, m));
        rangeUpdate(v*2 + 1, m + 1, hi, max(l, m + 1), r);
    }
}

bool pointQuery(int v, int lo, int hi, int pos){
    if (lo == hi) return seg[v];
    push(v);

    int m = (lo+hi)/2;
    if (pos <= m) return pointQuery(v*2, lo, m, pos);
    else return pointQuery(v*2 + 1, m + 1, hi, pos);
}

int main(){
    bool v[MAX];
    int t, q, l, r, i, n;
    char com;

    scanf("%d", &t);
    for (int c = 1; c <= t; c++){
        scanf(" %s", s);

        for (i = 0; s[i] != '\0'; i++) 
            v[i] = s[i] - '0';

        scanf("%d", &q);
        n = i;

        build(v, 1, 0, n - 1);

        printf("Case %d:\n", c);
        for (int i = 0; i < q; i++){
            scanf(" %c", &com);

            if (com == 'I'){
                scanf(" %d %d", &l, &r);
                rangeUpdate(1, 0, n-1, l-1, r-1);
            }else{
                scanf(" %d", &l);
                printf("%d\n", pointQuery(1, 0, n-1, l-1));
            }
        }
        memset(v, 0, sizeof(v));
    }
    return 0;
}