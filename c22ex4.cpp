#include<bits/stdc++.h>
using namespace std;

#define ABRE true
#define FECHA false

struct bracket{
    bool type;
    int pair = -1;
    bool erase = false;
};

int main(){
    int n, m, p, qDir = 0, qEsq = 0;
    char c;
    vector<bracket> v;
    stack<int> s;

    scanf("%d %d %d\n", &n, &m, &p);
    for (int i = 0; i < n; i++){
        bracket b;
        scanf("%c", &c);

        if (c == '('){
            b.type = ABRE;
            s.push(i+1);
        }else{
            b.type = FECHA;
            b.pair = s.top();
            v[s.top()-1].pair = i+1;
            s.pop();
        }
        v.push_back(b);
    }

    for (int i = 0; i < m; i++){
        scanf(" %c", &c);
        
        if (c == 'R') qDir++;
        else if (c == 'L') qEsq++;
        else{
            if (qDir - qEsq > 0){
                while (qDir - qEsq > 0){
                    p++;
                    while (p <= n && v[p-1].erase == true) {
                        if (v[p-1].type == ABRE) p = v[p-1].pair + 1;
                        else p++;
                    }
                    qDir--;
                }
            }else if (qEsq - qDir > 0){
                while (qEsq - qDir > 0){
                    p--;
                    while(p >= 1 && v[p-1].erase == true){
                        if (v[p-1].type == FECHA) p = v[p-1].pair - 1;
                        else p--;
                    }
                    qEsq--;
                }
            }
            qDir = qEsq = 0;

            v[p-1].erase = true;
            v[v[p-1].pair - 1].erase = true;
            
            //tenta ir para a direita
            int pAnt = p;
            if (v[p-1].type == ABRE) p = v[p-1].pair + 1;
            else p++;
            while (p <= n && v[p-1].erase == true) {
                if (v[p-1].type == ABRE) p = v[p-1].pair + 1;
                else p++;
            }

            int pDirMax = p;

            //se não conseguir ir para a direita, vai para a esquerda
            
            p = pAnt;
            if (v[p-1].type == ABRE) p = p - 1;
            else p = v[p-1].pair - 1;
            while(p >= 1 && v[p-1].erase == true){
                if (v[p-1].type == FECHA) p = v[p-1].pair - 1;
                else p--;
            }

            int pEsqMin = p;

            v[pDirMax-2].pair = pEsqMin + 1;
            v[pEsqMin].pair = pDirMax - 1;

            if (pDirMax <= n) p = pDirMax;
            else p = pEsqMin;
        }
    }

    for (p = 0; p < n; p++){
        if (v[p].erase == false){
            if (v[p].type == ABRE) printf("(");
            else printf(")");
        }else p = v[p].pair - 1;
    }
    printf("\n");
    return 0;
}