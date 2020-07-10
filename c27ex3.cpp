#include<bits/stdc++.h>
using namespace std;
int tab[13][13];
vector<int> rainhas;

int main(){
    int n, m, r, c = 0, q = 0;
    bool f = false;

    scanf("%d %d", &n, &m);
    while (n != 0 || m != 0){
        q = 0;
        for (int i = 0; i < m; i++){
            scanf("%d %d", &r, &c);
            tab[r][c] = -1;
        }

        r = 0;
        c = 0;
        while(r != 0 || c < n){
            f = false;
            r = (int) rainhas.size();
            if (c >= n || r >= n){
                c = rainhas.back() + 1;
                rainhas.pop_back();
                r--;
            }else c = 0;

            while (c < n && !f){
                if (tab[r][c] != -1){
                    int i = 0;
                    for (i = 0; i < (int) rainhas.size() && c != rainhas[i] && abs(i - r) != abs(rainhas[i] - c); i++);
                    if (i == (int) rainhas.size()){
                        f = true;
                        rainhas.push_back(c);
                    }else c++;
                }else c++;
            }

            if ((int)rainhas.size() == n && f) q++;
        }

        printf("%d\n", q);

        scanf("%d %d", &n, &m);
        memset(tab, 0, sizeof(tab));
        rainhas.clear();
    }
    return 0;
}