#include<bits/stdc++.h>
using namespace std;
#define MAX 10000
int v[MAX];

int main(){
    int t, n, u, i, j, q, l, r, val, index;

    for(scanf("%d", &t); t > 0; t--){
        scanf("%d%d", &n, &u);
        for (i = 0; i < n; i++) v[i] = 0;

        for (i = 0; i < u; i++){
            scanf("%d%d%d", &l, &r, &val);
            for (j = l; j <= r; j++) v[j] += val;
        }

        cin >> q;
        for (i = 0; i < q; i++){
            scanf("%d", &index);
            printf("%d\n", v[index]);
        }
    }

    return 0;
}