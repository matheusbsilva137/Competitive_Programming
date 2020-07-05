#include<bits/stdc++.h>
using namespace std;
#define MAX 100001
int freq[MAX];
int aXor[MAX];
int proxSeq[MAX];

int main(){
    int n, k, x, ai, c = 0, aux = 0, d, maxXor = 0;
    vector<int> a;

    scanf("%d %d %d", &n, &k, &x);
    for (int i = 0; i < n; i++){
        scanf("%d", &ai);
        a.push_back(ai);
        freq[ai]++;
        aXor[ai] = ai^x;
        maxXor = max(max(aXor[ai], ai), maxXor);
        if (aXor[ai] < MAX) aXor[aXor[ai]] = ai;
    }
    
    while(k--){
        c = 0;
        for (int i = 0; i <= maxXor; i++){
            aux = freq[i];
            if (freq[i] > 0){
                //o elemento está no vetor
                if(c % 2 == 0){
                    d = ceil((float)freq[i]/2);
                    freq[i] -= d; //diminui em d a frequência de i, dado que foi feita a operação xor em d elementos
                    proxSeq[aXor[i]] += d; //a sequência gerada tem, portanto, d elementos i^x adicionados
                }else{
                    d = freq[i]/2; 
                    freq[i] -= d;
                    proxSeq[aXor[i]] += d;
                }
            }
            c += aux; //c é atualizado com a quantidade de elementos já analisados
        }

        for(int i = 0; i <= maxXor; i++){
            freq[i] += proxSeq[i]; //elimina os elementos já analisados
            proxSeq[i] = 0; //zera o vetor que guarda a frequência dos elementos da próxima sequência
        }
    }

    int minX = INT_MAX, maxX = 0;
    for (int i = 0; i <= maxXor; i++){
        if (freq[i] > 0){
            minX = min(minX, i);
            maxX = max(maxX, i);
        }
    }

    printf("%d %d\n", maxX, minX);
    return 0;
}